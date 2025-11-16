from flask import Flask, render_template, request, redirect, url_for, session, flash, jsonify, send_file
from flask_pymongo import PyMongo
from flask_mail import Mail, Message
from bson import ObjectId
from datetime import datetime, timezone
import os
import bcrypt
import qrcode
from io import BytesIO
import base64
from functools import wraps
import threading
import cv2
import numpy as np
from pyzbar.pyzbar import decode

app = Flask(__name__)
app.secret_key = os.getenv('SECRET_KEY', 'fallback-secret-key-change-in-production')

# MongoDB Configuration
app.config["MONGO_URI"] = os.getenv('MONGO_URI', 'mongodb://localhost:27017/event_management')

# Email Configuration
app.config['MAIL_SERVER'] = os.getenv('MAIL_SERVER', 'smtp.gmail.com')
app.config['MAIL_PORT'] = int(os.getenv('MAIL_PORT', 587))
app.config['MAIL_USE_TLS'] = os.getenv('MAIL_USE_TLS', 'True').lower() == 'true'
app.config['MAIL_USERNAME'] = os.getenv('MAIL_USERNAME', 'your-email@gmail.com')
app.config['MAIL_PASSWORD'] = os.getenv('MAIL_PASSWORD', 'your-app-password')
app.config['MAIL_DEFAULT_SENDER'] = os.getenv('MAIL_DEFAULT_SENDER', 'your-email@gmail.com')

mongo = PyMongo(app)
mail = Mail(app)

# Data Structures Implementation
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class LinkedList:
    def __init__(self):
        self.head = None
    
    def append(self, data):
        new_node = Node(data)
        if not self.head:
            self.head = new_node
            return
        current = self.head
        while current.next:
            current = current.next
        current.next = new_node
    
    def to_list(self):
        result = []
        current = self.head
        while current:
            result.append(current.data)
            current = current.next
        return result

class Stack:
    def __init__(self):
        self.items = []
    
    def push(self, item):
        self.items.append(item)
    
    def pop(self):
        return self.items.pop() if self.items else None
    
    def peek(self):
        return self.items[-1] if self.items else None
    
    def is_empty(self):
        return len(self.items) == 0

class Queue:
    def __init__(self):
        self.items = []
    
    def enqueue(self, item):
        self.items.append(item)
    
    def dequeue(self):
        return self.items.pop(0) if self.items else None
    
    def is_empty(self):
        return len(self.items) == 0

# Initialize data structures
event_manager = LinkedList()
undo_stack = Stack()
waiting_list_queue = Queue()

# Email sending function
def send_email_async(app, msg):
    with app.app_context():
        try:
            mail.send(msg)
            print(f"✅ Email sent successfully to {msg.recipients}")
            return True
        except Exception as e:
            print(f"❌ Failed to send email: {str(e)}")
            return False

def send_welcome_email(user_data):
    """Send welcome email to new users"""
    try:
        msg = Message(
            subject="Welcome to EventHub - Your Account Details",
            recipients=[user_data['email']],
            html=render_template('email/welcome_email.html',
                               user=user_data)
        )
        return send_email_async(app, msg)
    except Exception as e:
        print(f"❌ Welcome email failed: {str(e)}")
        return False

def send_registration_confirmation(registration_data, event_data):
    """Send confirmation email to participant"""
    try:
        msg = Message(
            subject=f"Event Registration Confirmation - {event_data['title']}",
            recipients=[registration_data['email']],
            html=render_template('email/registration_confirmation.html',
                               registration=registration_data,
                               event=event_data)
        )
        
        # Attach QR code if available
        if registration_data.get('qr_code'):
            qr_img_data = base64.b64decode(registration_data['qr_code'])
            msg.attach(f"qr_code_{registration_data['prn']}.png", 
                      "image/png", qr_img_data)
        
        return send_email_async(app, msg)
    except Exception as e:
        print(f"❌ Registration confirmation email failed: {str(e)}")
        return False

def send_admin_notification(registration_data, event_data):
    """Send notification email to admin"""
    try:
        # Get admin email or use default sender
        admin_email = app.config['MAIL_DEFAULT_SENDER']
        
        msg = Message(
            subject=f"New Registration - {event_data['title']}",
            recipients=[admin_email],
            html=render_template('email/new_registration_notification.html',
                               registration=registration_data,
                               event=event_data)
        )
        return send_email_async(app, msg)
    except Exception as e:
        print(f"❌ Admin notification email failed: {str(e)}")
        return False

# Decorators
def login_required(f):
    @wraps(f)
    def decorated_function(*args, **kwargs):
        if 'username' not in session:
            flash('Please login to access this page.', 'error')
            return redirect(url_for('login'))
        return f(*args, **kwargs)
    return decorated_function

def admin_required(f):
    @wraps(f)
    def decorated_function(*args, **kwargs):
        if 'username' not in session or session.get('role') not in ['Host', 'Organizer', 'Admin']:
            flash('Admin access required.', 'error')
            return redirect(url_for('login'))
        return f(*args, **kwargs)
    return decorated_function

# Utility Functions
def generate_qr_code(data):
    qr = qrcode.QRCode(
        version=1,
        error_correction=qrcode.constants.ERROR_CORRECT_L,
        box_size=10,
        border=4,
    )
    qr.add_data(data)
    qr.make(fit=True)
    
    img = qr.make_image(fill_color="black", back_color="white")
    buffered = BytesIO()
    img.save(buffered, format="PNG")
    img_str = base64.b64encode(buffered.getvalue()).decode()
    return img_str

def get_event_stats():
    events = mongo.db.events.find()
    total_events = mongo.db.events.count_documents({})
    total_participants = 0
    total_checked_in = 0
    
    for event in events:
        total_participants += len(event.get('registered_participants', []))
        total_checked_in += len(event.get('checked_in_participants', []))
    
    attendance_rate = (total_checked_in / total_participants * 100) if total_participants > 0 else 0
    
    return {
        'total_events': total_events,
        'total_participants': total_participants,
        'total_checked_in': total_checked_in,
        'attendance_rate': round(attendance_rate, 1)
    }

def format_time_ago(dt):
    """Format datetime as time ago string"""
    now = datetime.now(timezone.utc)
    diff = now - dt
    
    if diff.days > 0:
        return f"{diff.days} day{'s' if diff.days > 1 else ''} ago"
    elif diff.seconds >= 3600:
        hours = diff.seconds // 3600
        return f"{hours} hour{'s' if hours > 1 else ''} ago"
    elif diff.seconds >= 60:
        minutes = diff.seconds // 60
        return f"{minutes} minute{'s' if minutes > 1 else ''} ago"
    else:
        return "Just now"

# Preload default events
def preload_default_events():
    if mongo.db.events.count_documents({}) == 0:
        default_events = [
            {
                'host': 'admin',
                'organization': 'CodeHub',
                'title': 'Tech Innovators Summit 2024',
                'description': 'Join us for an exciting summit on emerging technologies, AI, and innovation. Network with industry leaders and showcase your projects.',
                'date': '2024-12-15',
                'time': '09:00',
                'venue': 'Grand Conference Center, Main Hall',
                'capacity': 200,
                'fee': 299,
                'is_team_event': False,
                'team_size': 1,
                'prize_pool': '₹50,000',
                'registered_participants': [],
                'checked_in_participants': [],
                'created_at': datetime.now(timezone.utc),
                'image_url': '/static/images/tech-summit.jpg'
            },
            {
                'host': 'admin',
                'organization': 'FutureTech',
                'title': 'AI & Machine Learning Hackathon',
                'description': '24-hour hackathon focusing on AI and ML solutions. Build innovative projects and win amazing prizes!',
                'date': '2024-11-20',
                'time': '10:00',
                'venue': 'Innovation Lab, Tech Park',
                'capacity': 50,
                'fee': 499,
                'is_team_event': True,
                'team_size': 4,
                'prize_pool': '₹1,00,000',
                'registered_participants': [],
                'checked_in_participants': [],
                'created_at': datetime.now(timezone.utc),
                'image_url': '/static/images/ai-hackathon.jpg'
            }
        ]
        mongo.db.events.insert_many(default_events)
        print("✅ Default events loaded successfully!")

# ============================================================================
# API ROUTES FOR QR CODE SCANNING AND CHECK-IN
# ============================================================================

@app.route('/api/detect-qr', methods=['POST'])
@login_required
@admin_required
def detect_qr():
    """Detect QR code from image data sent from frontend"""
    try:
        data = request.get_json()
        if not data or 'image_data' not in data:
            return jsonify({'success': False, 'error': 'No image data provided'})
        
        print("🔍 Processing QR code detection request...")
        
        # Convert image data to numpy array
        image_data = np.array(data['image_data'], dtype=np.uint8)
        image_data = image_data.reshape((data['height'], data['width'], 4))  # RGBA
        
        # Convert to BGR for OpenCV
        image_bgr = cv2.cvtColor(image_data, cv2.COLOR_RGBA2BGR)
        
        # Convert to grayscale for better QR detection
        gray = cv2.cvtColor(image_bgr, cv2.COLOR_BGR2GRAY)
        
        # Detect QR codes using pyzbar
        decoded_objects = decode(gray)
        
        if decoded_objects:
            # Get the first QR code found
            qr_data = decoded_objects[0].data.decode('utf-8')
            print(f"✅ QR Code detected: {qr_data[:50]}...")
            
            return jsonify({
                'success': True,
                'data': qr_data,
                'count': len(decoded_objects)
            })
        else:
            print("❌ No QR code detected in image")
            return jsonify({'success': False, 'data': None})
            
    except Exception as e:
        print(f"❌ QR detection error: {e}")
        return jsonify({'success': False, 'error': str(e)})

@app.route('/api/checkin', methods=['POST'])
@login_required
@admin_required
def api_checkin():
    """API endpoint for check-in (both manual and QR)"""
    try:
        data = request.get_json()
        event_id = data.get('event_id')
        search_type = data.get('search_type')
        search_value = data.get('search_value')
        checkin_method = data.get('checkin_method', 'manual')
        
        if not event_id or not search_type or not search_value:
            return jsonify({'success': False, 'error': 'Missing required fields'})
        
        print(f"🔍 API Check-in attempt: {search_type}={search_value} for event {event_id} via {checkin_method}")
        
        # Validate event exists
        event = mongo.db.events.find_one({'_id': ObjectId(event_id)})
        if not event:
            return jsonify({'success': False, 'error': 'Event not found'})
        
        # Find the registration
        query = {'event_id': event_id}
        if search_type == 'prn':
            query['prn'] = search_value
        else:  # search by name
            query['full_name'] = {'$regex': search_value, '$options': 'i'}
        
        registration = mongo.db.registrations.find_one(query)
        
        if not registration:
            return jsonify({'success': False, 'error': 'Registration not found for this event'})
        
        if registration['is_checked_in']:
            return jsonify({'success': False, 'error': 'Participant already checked in'})
        
        # Perform check-in
        mongo.db.registrations.update_one(
            {'_id': registration['_id']},
            {'$set': {'is_checked_in': True, 'checked_in_at': datetime.now(timezone.utc)}}
        )
        
        # Update event checked-in participants
        mongo.db.events.update_one(
            {'_id': ObjectId(event_id)},
            {'$push': {'checked_in_participants': registration['full_name']}}
        )
        
        print(f"✅ Check-in successful: {registration['full_name']} for {event['title']} via {checkin_method}")
        
        return jsonify({
            'success': True,
            'participant_name': registration['full_name'],
            'event_name': event['title'],
            'checkin_method': checkin_method,
            'timestamp': datetime.now(timezone.utc).isoformat()
        })
        
    except Exception as e:
        print(f"❌ API check-in error: {e}")
        return jsonify({'success': False, 'error': str(e)})

@app.route('/api/search-registrations')
@login_required
@admin_required
def search_registrations():
    """Search registrations for manual check-in"""
    try:
        event_id = request.args.get('event_id')
        search_type = request.args.get('search_type')
        search_value = request.args.get('search_value')
        
        if not event_id or not search_type or not search_value:
            return jsonify([])
        
        print(f"🔍 Searching registrations: {search_type}={search_value} for event {event_id}")
        
        query = {'event_id': event_id}
        if search_type == 'prn':
            query['prn'] = search_value
        else:  # search by name
            query['full_name'] = {'$regex': search_value, '$options': 'i'}
        
        registrations = list(mongo.db.registrations.find(query).limit(10))
        
        # Convert ObjectId to string and remove sensitive data for JSON serialization
        result = []
        for reg in registrations:
            result.append({
                '_id': str(reg['_id']),
                'full_name': reg['full_name'],
                'prn': reg['prn'],
                'email': reg['email'],
                'class_name': reg['class_name'],
                'branch': reg['branch'],
                'is_checked_in': reg['is_checked_in'],
                'created_at': reg['created_at'].isoformat() if reg.get('created_at') else None
            })
        
        print(f"✅ Found {len(result)} registration(s)")
        return jsonify(result)
        
    except Exception as e:
        print(f"❌ Search registrations error: {e}")
        return jsonify([])

@app.route('/api/event-stats')
@login_required
@admin_required
def event_stats_api():
    """Get event statistics for check-in page"""
    try:
        event_id = request.args.get('event_id')
        if not event_id:
            return jsonify({})
        
        total_registrations = mongo.db.registrations.count_documents({'event_id': event_id})
        checked_in_count = mongo.db.registrations.count_documents({
            'event_id': event_id,
            'is_checked_in': True
        })
        pending_count = total_registrations - checked_in_count
        
        stats = {
            'total_registrations': total_registrations,
            'checked_in_count': checked_in_count,
            'pending_count': pending_count,
            'attendance_rate': round((checked_in_count / total_registrations * 100), 1) if total_registrations > 0 else 0
        }
        
        print(f"📊 Event stats for {event_id}: {stats}")
        return jsonify(stats)
        
    except Exception as e:
        print(f"❌ Event stats error: {e}")
        return jsonify({})

@app.route('/api/recent-checkins')
@login_required
@admin_required
def recent_checkins():
    """Get recent check-ins for display"""
    try:
        event_id = request.args.get('event_id')
        if not event_id:
            return jsonify([])
        
        recent_checkins = list(mongo.db.registrations.find({
            'event_id': event_id,
            'is_checked_in': True
        }).sort('checked_in_at', -1).limit(10))
        
        # Format for display
        formatted_checkins = []
        for checkin in recent_checkins:
            time_ago = "Recently"
            if checkin.get('checked_in_at'):
                time_ago = format_time_ago(checkin['checked_in_at'])
            
            formatted_checkins.append({
                'full_name': checkin['full_name'],
                'prn': checkin['prn'],
                'checked_in_at': time_ago,
                'actual_time': checkin['checked_in_at'].strftime('%I:%M %p') if checkin.get('checked_in_at') else 'Unknown'
            })
        
        print(f"✅ Found {len(formatted_checkins)} recent check-in(s)")
        return jsonify(formatted_checkins)
        
    except Exception as e:
        print(f"❌ Recent checkins error: {e}")
        return jsonify([])

@app.route('/api/validate-qr', methods=['POST'])
@login_required
@admin_required
def validate_qr():
    """Validate QR code data and return registration info"""
    try:
        data = request.get_json()
        qr_data = data.get('qr_data')
        event_id = data.get('event_id')
        
        if not qr_data or not event_id:
            return jsonify({'success': False, 'error': 'Missing QR data or event ID'})
        
        print(f"🔍 Validating QR data for event {event_id}")
        
        # Parse QR code data (assuming format from generate_qr_code)
        lines = qr_data.strip().split('\n')
        qr_info = {}
        
        for line in lines:
            if ':' in line:
                key, value = line.split(':', 1)
                qr_info[key.strip()] = value.strip()
        
        # Extract PRN from QR data
        prn = qr_info.get('PRN')
        if not prn:
            return jsonify({'success': False, 'error': 'Invalid QR code format - PRN not found'})
        
        # Find registration
        registration = mongo.db.registrations.find_one({
            'event_id': event_id,
            'prn': prn
        })
        
        if not registration:
            return jsonify({'success': False, 'error': 'Registration not found for this event'})
        
        if registration['is_checked_in']:
            return jsonify({'success': False, 'error': 'Participant already checked in'})
        
        # Return registration info for confirmation
        return jsonify({
            'success': True,
            'registration': {
                'full_name': registration['full_name'],
                'prn': registration['prn'],
                'email': registration['email'],
                'class_name': registration['class_name'],
                'branch': registration['branch'],
                'event_name': registration['event_name']
            }
        })
        
    except Exception as e:
        print(f"❌ QR validation error: {e}")
        return jsonify({'success': False, 'error': str(e)})

# ============================================================================
# MAIN APPLICATION ROUTES
# ============================================================================

@app.route('/')
def index():
    featured_events = list(mongo.db.events.find().limit(3))
    stats = get_event_stats()
    return render_template('index.html', events=featured_events, stats=stats)

@app.route('/register', methods=['GET', 'POST'])
def register():
    if request.method == 'POST':
        username = request.form['username']
        password = request.form['password']
        role = request.form['role']
        organization = request.form.get('organization', '')
        email = request.form['email']
        full_name = request.form['full_name']
        
        print(f"🔍 Registration attempt - Username: {username}, Email: {email}")
        
        # Check if user already exists
        existing_user = mongo.db.users.find_one({'username': username})
        if existing_user:
            print(f"❌ Username already exists: {username}")
            flash('Username already exists! Please choose a different one.', 'error')
            return render_template('register.html')
        
        existing_email = mongo.db.users.find_one({'email': email})
        if existing_email:
            print(f"❌ Email already registered: {email}")
            flash('Email already registered! Please use a different email.', 'error')
            return render_template('register.html')
        
        # Hash password
        hashed_password = bcrypt.hashpw(password.encode('utf-8'), bcrypt.gensalt())
        
        user_data = {
            'username': username,
            'password': hashed_password,
            'email': email,
            'full_name': full_name,
            'role': role,
            'organization': organization,
            'created_at': datetime.now(timezone.utc)
        }
        
        print(f"📝 User data to insert: {user_data}")
        
        try:
            # Insert user into database
            result = mongo.db.users.insert_one(user_data)
            user_data['_id'] = result.inserted_id
            
            print(f"✅ User registered successfully! ID: {result.inserted_id}")
            
            # Verify the user was actually inserted
            verify_user = mongo.db.users.find_one({'_id': result.inserted_id})
            if verify_user:
                print(f"✅ User verified in database: {verify_user['username']}")
            else:
                print("❌ User not found in database after insertion!")
            
            # Send welcome email
            email_sent = send_welcome_email(user_data)
            if email_sent:
                flash('Registration successful! Welcome email sent.', 'success')
            else:
                flash('Registration successful! Welcome email could not be sent.', 'warning')
            
            return redirect(url_for('login'))
            
        except Exception as e:
            print(f"❌ Database insertion failed: {e}")
            flash('Registration failed! Please try again.', 'error')
            return render_template('register.html')
    
    return render_template('register.html')

@app.route('/login', methods=['GET', 'POST'])
def login():
    if request.method == 'POST':
        username = request.form['username']
        password = request.form['password']
        
        print(f"🔍 Login attempt - Username: {username}")
        
        # Find user in database
        user = mongo.db.users.find_one({'username': username})
        
        if user:
            print(f"✅ User found in database: {user['username']}")
            print(f"📧 User email: {user.get('email', 'Not found')}")
            print(f"🔑 Stored password hash: {user['password']}")
            
            # Verify password
            try:
                password_valid = bcrypt.checkpw(password.encode('utf-8'), user['password'])
                print(f"🔐 Password valid: {password_valid}")
                
                if password_valid:
                    # Set session data
                    session['user_id'] = str(user['_id'])
                    session['username'] = user['username']
                    session['role'] = user['role']
                    session['organization'] = user.get('organization', '')
                    session['full_name'] = user.get('full_name', '')
                    session['email'] = user.get('email', '')
                    
                    print(f"✅ Login successful! Session data: {dict(session)}")
                    
                    flash(f'Welcome back, {user["full_name"]}!', 'success')
                    
                    if user['role'] in ['Host', 'Organizer', 'Admin']:
                        return redirect(url_for('admin_dashboard'))
                    else:
                        return redirect(url_for('user_dashboard'))
                else:
                    print("❌ Invalid password")
                    flash('Invalid username or password!', 'error')
                    
            except Exception as e:
                print(f"❌ Password verification failed: {e}")
                flash('Invalid username or password!', 'error')
        else:
            print(f"❌ User not found: {username}")
            flash('Invalid username or password!', 'error')
    
    return render_template('login.html')

# FIXED: Add the missing events route
@app.route('/events')
def events():
    """Display all events"""
    events_list = list(mongo.db.events.find())
    return render_template('events.html', events=events_list)

@app.route('/admin/dashboard')
@login_required
@admin_required
def admin_dashboard():
    events = list(mongo.db.events.find({'host': session['username']}))
    all_events = list(mongo.db.events.find())
    stats = get_event_stats()
    
    # Get recent registrations
    recent_registrations = list(mongo.db.registrations.find().sort('created_at', -1).limit(5))
    
    return render_template('admin_dashboard.html', 
                         events=events, 
                         all_events=all_events,
                         stats=stats,
                         recent_registrations=recent_registrations)

@app.route('/user/dashboard')
@login_required
def user_dashboard():
    events = list(mongo.db.events.find())
    user_registrations = list(mongo.db.registrations.find({'user_id': session['username']}))
    
    return render_template('user_dashboard.html', 
                         events=events, 
                         registrations=user_registrations)

@app.route('/events/create', methods=['GET', 'POST'])
@login_required
@admin_required
def create_event():
    if request.method == 'POST':
        event_data = {
            'host': session['username'],
            'organization': session['organization'],
            'title': request.form['title'],
            'description': request.form['description'],
            'date': request.form['date'],
            'time': request.form['time'],
            'venue': request.form['venue'],
            'capacity': int(request.form['capacity']),
            'fee': float(request.form['fee']),
            'is_team_event': 'is_team_event' in request.form,
            'team_size': int(request.form.get('team_size', 1)),
            'prize_pool': request.form['prize_pool'],
            'registered_participants': [],
            'checked_in_participants': [],
            'created_at': datetime.now(timezone.utc),
            'image_url': request.form.get('image_url', '/static/images/event-default.jpg')
        }
        
        result = mongo.db.events.insert_one(event_data)
        event_manager.append(event_data)
        undo_stack.push(('create_event', str(result.inserted_id)))
        
        flash('Event created successfully!', 'success')
        return redirect(url_for('admin_dashboard'))
    
    return render_template('create_event.html')

@app.route('/events/<event_id>/register', methods=['POST'])
@login_required
def register_event(event_id):
    try:
        event = mongo.db.events.find_one({'_id': ObjectId(event_id)})
        if not event:
            flash('Event not found!', 'error')
            return redirect(url_for('events'))
        
        print(f"🔍 Registration attempt for event: {event['title']} by user: {session['username']}")
        
        # Check if already registered
        existing_reg = mongo.db.registrations.find_one({
            'user_id': session['username'],
            'event_id': event_id
        })
        
        if existing_reg:
            flash('You are already registered for this event!', 'warning')
            return redirect(url_for('events'))
        
        registration_data = {
            'user_id': session['username'],
            'event_id': event_id,
            'event_name': event['title'],
            'full_name': request.form['full_name'],
            'email': request.form['email'],
            'phone': request.form['phone'],
            'address': request.form['address'],
            'prn': request.form['prn'],
            'class_name': request.form['class_name'],
            'branch': request.form['branch'],
            'num_participants': int(request.form['num_participants']),
            'created_at': datetime.now(timezone.utc),
            'is_checked_in': False
        }
        
        print(f"📝 Registration data: {registration_data}")
        
        # Generate QR code data
        qr_data = f"""
        EVENT: {event['title']}
        NAME: {registration_data['full_name']}
        PRN: {registration_data['prn']}
        EMAIL: {registration_data['email']}
        CLASS: {registration_data['class_name']}
        BRANCH: {registration_data['branch']}
        PARTICIPANTS: {registration_data['num_participants']}
        """
        
        registration_data['qr_code'] = generate_qr_code(qr_data)
        
        # Check capacity
        current_registrations = len(event.get('registered_participants', []))
        if current_registrations >= event['capacity']:
            waiting_list_queue.enqueue(registration_data)
            flash('Event is full! You have been added to waiting list.', 'warning')
            return redirect(url_for('events'))
        
        # Insert registration
        result = mongo.db.registrations.insert_one(registration_data)
        registration_data['_id'] = result.inserted_id
        
        # Update event with new participant
        mongo.db.events.update_one(
            {'_id': ObjectId(event_id)},
            {'$push': {'registered_participants': session['username']}}
        )
        
        print(f"✅ Registration successful! Registration ID: {result.inserted_id}")
        
        # Send registration emails
        confirmation_sent = send_registration_confirmation(registration_data, event)
        admin_sent = send_admin_notification(registration_data, event)
        
        if confirmation_sent and admin_sent:
            flash('Registration successful! Confirmation email sent with QR code.', 'success')
        elif confirmation_sent:
            flash('Registration successful! Confirmation email sent.', 'success')
        elif admin_sent:
            flash('Registration successful! Admin notified.', 'success')
        else:
            flash('Registration successful! Emails could not be sent.', 'warning')
        
        return redirect(url_for('user_dashboard'))
        
    except Exception as e:
        print(f"❌ Registration failed: {e}")
        flash('Registration failed! Please try again.', 'error')
        return redirect(url_for('events'))

@app.route('/registrations')
@login_required
def view_registrations():
    if session['role'] in ['Host', 'Organizer', 'Admin']:
        # Admin sees all registrations for their events
        admin_events = mongo.db.events.find({'host': session['username']})
        event_titles = [event['title'] for event in admin_events]
        registrations = list(mongo.db.registrations.find({'event_name': {'$in': event_titles}}))
    else:
        # Users see only their registrations
        registrations = list(mongo.db.registrations.find({'user_id': session['username']}))
    
    return render_template('registrations.html', registrations=registrations)

@app.route('/checkin', methods=['GET', 'POST'])
@login_required
@admin_required
def checkin():
    if request.method == 'POST':
        event_id = request.form['event_id']
        search_type = request.form['search_type']
        search_value = request.form['search_value']
        
        event = mongo.db.events.find_one({'_id': ObjectId(event_id)})
        if not event:
            flash('Event not found!', 'error')
            return redirect(url_for('checkin'))
        
        query = {'event_id': event_id}
        if search_type == 'prn':
            query['prn'] = search_value
        else:  # search by name
            query['full_name'] = {'$regex': search_value, '$options': 'i'}
        
        registration = mongo.db.registrations.find_one(query)
        
        if registration:
            if registration['is_checked_in']:
                flash('Participant already checked in!', 'warning')
            else:
                mongo.db.registrations.update_one(
                    {'_id': registration['_id']},
                    {'$set': {'is_checked_in': True, 'checked_in_at': datetime.now(timezone.utc)}}
                )
                mongo.db.events.update_one(
                    {'_id': ObjectId(event_id)},
                    {'$push': {'checked_in_participants': registration['full_name']}}
                )
                flash(f'Check-in successful for {registration["full_name"]}!', 'success')
        else:
            flash('Registration not found for this event!', 'error')
    
    events = list(mongo.db.events.find({'host': session['username']}))
    return render_template('checkin.html', events=events)

@app.route('/api/event/<event_id>/stats')
@login_required
@admin_required
def event_stats(event_id):
    event = mongo.db.events.find_one({'_id': ObjectId(event_id)})
    if not event:
        return jsonify({'error': 'Event not found'}), 404
    
    registrations_count = mongo.db.registrations.count_documents({'event_id': event_id})
    checked_in_count = mongo.db.registrations.count_documents({
        'event_id': event_id,
        'is_checked_in': True
    })
    
    return jsonify({
        'title': event['title'],
        'capacity': event['capacity'],
        'registered': registrations_count,
        'checked_in': checked_in_count,
        'available': event['capacity'] - registrations_count
    })

@app.route('/profile')
@login_required
def profile():
    user = mongo.db.users.find_one({'username': session['username']})
    user_registrations = list(mongo.db.registrations.find({'user_id': session['username']}))
    
    return render_template('profile.html', 
                         user=user, 
                         registrations=user_registrations)

@app.route('/logout')
def logout():
    session.clear()
    flash('You have been logged out successfully.', 'info')
    return redirect(url_for('index'))

# Error Handlers
@app.errorhandler(404)
def not_found_error(error):
    return render_template('404.html'), 404

@app.errorhandler(500)
def internal_error(error):
    return render_template('500.html'), 500

if __name__ == '__main__':
    with app.app_context():
        # Create indexes
        mongo.db.users.create_index('username', unique=True)
        mongo.db.users.create_index('email', unique=True)
        mongo.db.events.create_index('host')
        mongo.db.registrations.create_index([('user_id', 1), ('event_id', 1)], unique=True)
        
        # Create admin user if not exists
        if not mongo.db.users.find_one({'username': 'admin'}):
            hashed_password = bcrypt.hashpw('admin123'.encode('utf-8'), bcrypt.gensalt())
            mongo.db.users.insert_one({
                'username': 'admin',
                'password': hashed_password,
                'email': 'admin@eventhub.com',
                'full_name': 'System Administrator',
                'role': 'Admin',
                'organization': 'EventHub',
                'created_at': datetime.now(timezone.utc)
            })
            print("✅ Admin user created: username='admin', password='admin123'")
        
        preload_default_events()
    
    print("🚀 Starting EventHub with QR Code Scanning API...")
    app.run(debug=True, host='0.0.0.0', port=5001)