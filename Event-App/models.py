from flask_pymongo import PyMongo
from bson import ObjectId
import bcrypt
from datetime import datetime
import qrcode
from io import BytesIO
import base64

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

# MongoDB Models
class UserModel:
    def __init__(self, mongo):
        self.mongo = mongo
        self.collection = mongo.db.users
    
    def create_user(self, username, password, role, organization=None):
        hashed_password = bcrypt.hashpw(password.encode('utf-8'), bcrypt.gensalt())
        user = {
            'username': username,
            'password': hashed_password,
            'role': role,
            'organization': organization,
            'created_at': datetime.utcnow()
        }
        return self.collection.insert_one(user)
    
    def find_by_username(self, username):
        return self.collection.find_one({'username': username})
    
    def verify_password(self, user, password):
        return bcrypt.checkpw(password.encode('utf-8'), user['password'])

class EventModel:
    def __init__(self, mongo):
        self.mongo = mongo
        self.collection = mongo.db.events
    
    def create_event(self, event_data):
        return self.collection.insert_one(event_data)
    
    def get_all_events(self):
        return list(self.collection.find())
    
    def get_events_by_host(self, host_username):
        return list(self.collection.find({'host': host_username}))
    
    def get_event_by_id(self, event_id):
        return self.collection.find_one({'_id': ObjectId(event_id)})
    
    def update_event(self, event_id, update_data):
        return self.collection.update_one(
            {'_id': ObjectId(event_id)},
            {'$set': update_data}
        )
    
    def add_participant(self, event_id, participant_name):
        return self.collection.update_one(
            {'_id': ObjectId(event_id)},
            {'$push': {'registered_participants': participant_name}}
        )
    
    def add_checked_in_participant(self, event_id, participant_name):
        return self.collection.update_one(
            {'_id': ObjectId(event_id)},
            {'$push': {'checked_in_participants': participant_name}}
        )

class RegistrationModel:
    def __init__(self, mongo):
        self.mongo = mongo
        self.collection = mongo.db.registrations
    
    def create_registration(self, registration_data):
        # Generate QR Code
        qr_data = f"""
        EVENT: {registration_data['event_name']}
        NAME: {registration_data['full_name']}
        PRN: {registration_data['prn']}
        CLASS: {registration_data['class_name']}
        BRANCH: {registration_data['branch']}
        PARTICIPANTS: {registration_data['num_participants']}
        """
        
        qr = qrcode.QRCode(version=1, box_size=10, border=5)
        qr.add_data(qr_data)
        qr.make(fit=True)
        
        qr_img = qr.make_image(fill_color="black", back_color="white")
        buffered = BytesIO()
        qr_img.save(buffered, format="PNG")
        qr_base64 = base64.b64encode(buffered.getvalue()).decode()
        
        registration_data['qr_code'] = qr_base64
        registration_data['is_checked_in'] = False
        registration_data['created_at'] = datetime.utcnow()
        
        return self.collection.insert_one(registration_data)
    
    def get_all_registrations(self):
        return list(self.collection.find())
    
    def get_registrations_by_event(self, event_name):
        return list(self.collection.find({'event_name': event_name}))
    
    def get_registration_by_prn(self, prn, event_name):
        return self.collection.find_one({'prn': prn, 'event_name': event_name})
    
    def check_in_participant(self, registration_id):
        return self.collection.update_one(
            {'_id': ObjectId(registration_id)},
            {'$set': {'is_checked_in': True}}
        )