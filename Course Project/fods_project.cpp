#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <cstdlib> 
using namespace std;

struct User {
    string username;
    string password;
    string role; 
};

struct Event {
    string host;
    string name;
    string date;
    string time;
    string venue;
    string description;
    int capacity;
    int fee;
    int teamSize;
    string status; 
    vector<string> participants;
    queue<string> waitlist;
};

vector<User> users;
vector<Event> events;
stack< pair<string, string> > undoStack; 
User* loggedInUser = NULL;

// ---------------- Function Declarations ----------------
void mainMenu();
void hostPanel();
void participantPanel();
void registerUser();
void loginUser();
void createEvent(bool teamEvent);
void viewMyEvents();
void editOrDeleteEvent();
void showEventsByStatus(string status);
void registerForEvent();
void undoRegistration();
void myParticipatedEvents();

// ---------------- User Functions ----------------
void registerUser() {
    User u;
    cout << "\nEnter username: ";
    cin >> u.username;
    cout << "Enter password: ";
    cin >> u.password;
    cout << "Are you a Host/Organizer or Participant? ";
    cin >> u.role;
    users.push_back(u);
    cout << "\nRegistration successful!\n";
}

void loginUser() {
    string uname, pass;
    cout << "\nEnter username: ";
    cin >> uname;
    cout << "Enter password: ";
    cin >> pass;

    for (int i = 0; i < users.size(); i++) {
        if (users[i].username == uname && users[i].password == pass) {
            loggedInUser = &users[i];
            cout << "\nLogin successful!\n";
            if (users[i].role == "Host" || users[i].role == "Organizer")
                hostPanel();
            else
                participantPanel();
            return;
        }
    }
    cout << "\nInvalid username or password.\n";
}

// ---------------- Host Panel ----------------
void createEvent(bool teamEvent) {
    Event e;
    e.host = loggedInUser->username;

    cin.ignore();
    cout << "\nEnter Event Name: ";
    getline(cin, e.name);
    cout << "Enter Date (dd-mm-yyyy): ";
    cin >> e.date;
    cout << "Enter Time (hh:mm): ";
    cin >> e.time;
    cin.ignore();
    cout << "Enter Venue: ";
    getline(cin, e.venue);
    cout << "Enter Description: ";
    getline(cin, e.description);
    cout << "Enter Capacity: ";
    cin >> e.capacity;
    cout << "Enter Fee: ";
    cin >> e.fee;
    if (teamEvent) {
        cout << "Enter Team Size: ";
        cin >> e.teamSize;
    } else e.teamSize = 1;

    e.status = "Upcoming";
    events.push_back(e);
    cout << "\nEvent created successfully!\n";
}

void viewMyEvents() {
    cout << "\n--- My Events ---\n";
    for (int i = 0; i < events.size(); i++) {
        if (events[i].host == loggedInUser->username) {
            cout << "\nEvent: " << events[i].name << " | Status: " << events[i].status << endl;
        }
    }
}

void editOrDeleteEvent() {
    string eventName;
    cin.ignore();
    cout << "\nEnter event name to edit/delete: ";
    getline(cin, eventName);

    for (int i = 0; i < events.size(); i++) {
        if (events[i].name == eventName && events[i].host == loggedInUser->username) {
            int choice;
            cout << "\n1. Edit Description\n2. Delete Event\nEnter choice: ";
            cin >> choice;
            if (choice == 1) {
                cin.ignore();
                cout << "Enter new description: ";
                getline(cin, events[i].description);
                cout << "Event updated.\n";
            } else if (choice == 2) {
                events.erase(events.begin() + i);
                cout << "Event deleted.\n";
            }
            return;
        }
    }
    cout << "Event not found.\n";
}

void hostPanel() {
    int choice;
    do {
        cout << "\n--- Host Panel ---\n";
        cout << "1. Create Event\n2. Create Team Event\n3. View My Events\n4. Edit/Delete Events\n5. Logout\nEnter choice: ";
        cin >> choice;
        switch (choice) {
        case 1: createEvent(false); break;
        case 2: createEvent(true); break;
        case 3: viewMyEvents(); break;
        case 4: editOrDeleteEvent(); break;
        case 5: loggedInUser = NULL; mainMenu(); return;
        default: cout << "Invalid choice.\n";
        }
    } while (choice != 5);
}

// ---------------- Participant Panel ----------------
void showEventsByStatus(string status) {
    cout << "\n--- " << status << " Events ---\n";
    for (int i = 0; i < events.size(); i++) {
        if (events[i].status == status) {
            cout << "\nEvent: " << events[i].name
                 << " | Host: " << events[i].host
                 << " | Venue: " << events[i].venue
                 << " | Fee: " << events[i].fee << endl;
        }
    }
}

void registerForEvent() {
    string eventName;
    cin.ignore();
    cout << "\nEnter Event Name to Register: ";
    getline(cin, eventName);

    for (int i = 0; i < events.size(); i++) {
        if (events[i].name == eventName) {
            // check if already registered
            for (int j = 0; j < events[i].participants.size(); j++) {
                if (events[i].participants[j] == loggedInUser->username) {
                    cout << "Already registered!\n";
                    return;
                }
            }

            if (events[i].participants.size() < events[i].capacity) {
                events[i].participants.push_back(loggedInUser->username);
                undoStack.push(make_pair(loggedInUser->username, events[i].name));
                cout << "Registered successfully!\n";
            } else {
                events[i].waitlist.push(loggedInUser->username);
                cout << "Event full! Added to waiting list.\n";
            }
            return;
        }
    }
    cout << "Event not found.\n";
}

void undoRegistration() {
    if (undoStack.empty()) {
        cout << "No action to undo.\n";
        return;
    }
    pair<string, string> last = undoStack.top();
    undoStack.pop();

    for (int i = 0; i < events.size(); i++) {
        if (events[i].name == last.second) {
            for (int j = 0; j < events[i].participants.size(); j++) {
                if (events[i].participants[j] == last.first) {
                    events[i].participants.erase(events[i].participants.begin() + j);
                    cout << "Last registration undone.\n";
                    return;
                }
            }
        }
    }
}

void myParticipatedEvents() {
    cout << "\n--- My Participated Events ---\n";
    for (int i = 0; i < events.size(); i++) {
        for (int j = 0; j < events[i].participants.size(); j++) {
            if (events[i].participants[j] == loggedInUser->username) {
                cout << events[i].name << " by " << events[i].host << endl;
            }
        }
    }
}

void participantPanel() {
    int choice;
    do {
        cout << "\n--- Participant Panel ---\n";
        cout << "1. Upcoming Events\n2. Ongoing Events\n3. Past Events\n4. Profile\n5. My Participated Events\n6. Logout\n7. Register for Event\n8. Undo Last Registration\nEnter choice: ";
        cin >> choice;
        switch (choice) {
        case 1: showEventsByStatus("Upcoming"); break;
        case 2: showEventsByStatus("Ongoing"); break;
        case 3: showEventsByStatus("Past"); break;
        case 4: cout << "\nUsername: " << loggedInUser->username << "\nRole: " << loggedInUser->role << endl; break;
        case 5: myParticipatedEvents(); break;
        case 6: loggedInUser = NULL; mainMenu(); return;
        case 7: registerForEvent(); break;
        case 8: undoRegistration(); break;
        default: cout << "Invalid choice.\n";
        }
    } while (choice != 6);
}

// ---------------- Sorting & Searching ----------------
bool compareByName(const Event &a, const Event &b) {
    return a.name < b.name;
}

int binarySearchEvent(string name) {
    int low = 0, high = events.size() - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (events[mid].name == name)
            return mid;
        else if (events[mid].name < name)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

// ---------------- Main Menu ----------------
void mainMenu() {
    int choice;
    do {
        cout << "\n=== Event Registration & Check-In App ===\n";
        cout << "1. Register\n2. Login\n3. Exit\nEnter choice: ";
        cin >> choice;
        switch (choice) {
        case 1: registerUser(); break;
        case 2: loginUser(); break;
        case 3: cout << "\nExiting...\n"; exit(0);
        default: cout << "Invalid choice.\n";
        }
    } while (choice != 3);
}

int main() {
    mainMenu();
    system("pause");
    return 0;
}

