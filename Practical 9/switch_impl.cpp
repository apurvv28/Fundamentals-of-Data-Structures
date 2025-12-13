#include <iostream>
#include <string>
using namespace std;
class Song {
public:
    string title;
    string artist;
    int duration;
    Song* next;
    Song* prev;
    
    Song(string t, string a, int d) {
        title = t;
        artist = a;
        duration = d;
        next = nullptr;
        prev = nullptr;
    }
};
class SinglyLinkedList {
private:
    Song* head;
public:
    SinglyLinkedList() {
        head = nullptr;
    }
    void addSong(string title, string artist, int duration) {
        Song* newSong = new Song(title, artist, duration);
        if (head == nullptr) {
            head = newSong;
        } else {
            Song* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newSong;
        }
    }
    void deleteSong(string title) {
        if (head == nullptr) return;
        if (head->title == title) {
            Song* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Song* temp = head;
        while (temp->next != nullptr && temp->next->title != title) {
            temp = temp->next;
        }
        if (temp->next != nullptr) {
            Song* toDelete = temp->next;
            temp->next = temp->next->next;
            delete toDelete;
        }
    }
    bool searchSong(string title) {
        Song* temp = head;
        while (temp != nullptr) {
            if (temp->title == title) return true;
            temp = temp->next;
        }
        return false;
    }
    void updateSong(string title, string newTitle, string newArtist, int newDuration) {
        Song* temp = head;
        while (temp != nullptr) {
            if (temp->title == title) {
                temp->title = newTitle;
                temp->artist = newArtist;
                temp->duration = newDuration;
                return;
            }
            temp = temp->next;
        }
    }
    void displayPlaylist() {
        Song* temp = head;
        while (temp != nullptr) {
            cout << temp->title << " - " << temp->artist << " (" << temp->duration << "s)" << endl;
            temp = temp->next;
        }
    }
    void arrangeSongs() {
        if (head == nullptr) return;
        bool swapped;
        do {
            swapped = false;
            Song* current = head;
            while (current->next != nullptr) {
                if (current->title > current->next->title) {
                    swap(current->title, current->next->title);
                    swap(current->artist, current->next->artist);
                    swap(current->duration, current->next->duration);
                    swapped = true;
                }
                current = current->next;
            }
        } while (swapped);
    }
};
class DoublyLinkedList {
private:
    Song* head;
public:
    DoublyLinkedList() {
        head = nullptr;
    }
    void addSong(string title, string artist, int duration) {
        Song* newSong = new Song(title, artist, duration);
        if (head == nullptr) {
            head = newSong;
        } else {
            Song* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newSong;
            newSong->prev = temp;
        }
    }
    void deleteSong(string title) {
        if (head == nullptr) return;
        Song* temp = head;
        while (temp != nullptr && temp->title != title) {
            temp = temp->next;
        }
        if (temp == nullptr) return;
        if (temp->prev != nullptr) {
            temp->prev->next = temp->next;
        } else {
            head = temp->next;
        }
        if (temp->next != nullptr) {
            temp->next->prev = temp->prev;
        }
        delete temp;
    }
    bool searchSong(string title) {
        Song* temp = head;
        while (temp != nullptr) {
            if (temp->title == title) return true;
            temp = temp->next;
        }
        return false;
    }
    void updateSong(string title, string newTitle, string newArtist, int newDuration) {
        Song* temp = head;
        while (temp != nullptr) {
            if (temp->title == title) {
                temp->title = newTitle;
                temp->artist = newArtist;
                temp->duration = newDuration;
                return;
            }
            temp = temp->next;
        }
    }
    void displayPlaylist() {
        Song* temp = head;
        while (temp != nullptr) {
            cout << temp->title << " - " << temp->artist << " (" << temp->duration << "s)" << endl;
            temp = temp->next;
        }
    }
    void arrangeSongs() {
        if (head == nullptr) return;   
        bool swapped;
        do {
            swapped = false;
            Song* current = head;
            while (current->next != nullptr) {
                if (current->title > current->next->title) {
                    swap(current->title, current->next->title);
                    swap(current->artist, current->next->artist);
                    swap(current->duration, current->next->duration);
                    swapped = true;
                }
                current = current->next;
            }
        } while (swapped);
    }
};
class CircularLinkedList {
private:
    Song* head;  
public:
    CircularLinkedList() {
        head = nullptr;
    }
    void addSong(string title, string artist, int duration) {
        Song* newSong = new Song(title, artist, duration);
        if (head == nullptr) {
            head = newSong;
            newSong->next = head;
        } else {
            Song* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newSong;
            newSong->next = head;
        }
    }
    void deleteSong(string title) {
        if (head == nullptr) return;   
        if (head->title == title && head->next == head) {
            delete head;
            head = nullptr;
            return;
        }
        Song* temp = head;
        Song* prev = nullptr;
        if (head->title == title) {
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = head->next;
            Song* toDelete = head;
            head = head->next;
            delete toDelete;
            return;
        }
        while (temp->next != head && temp->next->title != title) {
            temp = temp->next;
        }
        if (temp->next->title == title) {
            Song* toDelete = temp->next;
            temp->next = temp->next->next;
            delete toDelete;
        }
    }
    bool searchSong(string title) {
        if (head == nullptr) return false;   
        Song* temp = head;
        do {
            if (temp->title == title) return true;
            temp = temp->next;
        } while (temp != head);
        return false;
    }
    void updateSong(string title, string newTitle, string newArtist, int newDuration) {
        if (head == nullptr) return;   
        Song* temp = head;
        do {
            if (temp->title == title) {
                temp->title = newTitle;
                temp->artist = newArtist;
                temp->duration = newDuration;
                return;
            }
            temp = temp->next;
        } while (temp != head);
    }
    void displayPlaylist() {
        if (head == nullptr) return;   
        Song* temp = head;
        do {
            cout << temp->title << " - " << temp->artist << " (" << temp->duration << "s)" << endl;
            temp = temp->next;
        } while (temp != head);
    }
    void arrangeSongs() {
        if (head == nullptr) return;   
        bool swapped;
        do {
            swapped = false;
            Song* current = head;
            do {
                if (current->next != head && current->title > current->next->title) {
                    swap(current->title, current->next->title);
                    swap(current->artist, current->next->artist);
                    swap(current->duration, current->next->duration);
                    swapped = true;
                }
                current = current->next;
            } while (current->next != head);
        } while (swapped);
    }
};

int main() {
    SinglyLinkedList sll;
    DoublyLinkedList dll;
    CircularLinkedList cll;
    int mainChoice, listChoice;
    string title, artist, newTitle;
    int duration, newDuration;
    do {
        cout << "\nMain Menu:\n";
        cout << "1. Singly Linked Playlist\n";
        cout << "2. Doubly Linked Playlist\n";
        cout << "3. Circular Linked Playlist\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> mainChoice;
        if (mainChoice == 4) break;
        do {
            cout << "\n1. Add Song\n";
            cout << "2. Delete Song\n";
            cout << "3. Search Song\n";
            cout << "4. Update Song\n";
            cout << "5. Display Playlist\n";
            cout << "6. Arrange Songs\n";
            cout << "7. Exit to Main Menu\n";
            cout << "Enter choice: ";
            cin >> listChoice;
            switch(listChoice) {
                case 1:
                    cout << "Enter song title: ";
                    cin.ignore();
                    getline(cin, title);
                    cout << "Enter artist: ";
                    getline(cin, artist);
                    cout << "Enter duration (seconds): ";
                    cin >> duration;
                    if (mainChoice == 1) sll.addSong(title, artist, duration);
                    else if (mainChoice == 2) dll.addSong(title, artist, duration);
                    else if (mainChoice == 3) cll.addSong(title, artist, duration);
                    break;
                case 2:
                    cout << "Enter song title to delete: ";
                    cin.ignore();
                    getline(cin, title);
                    if (mainChoice == 1) sll.deleteSong(title);
                    else if (mainChoice == 2) dll.deleteSong(title);
                    else if (mainChoice == 3) cll.deleteSong(title);
                    break;
                case 3:
                    cout << "Enter song title to search: ";
                    cin.ignore();
                    getline(cin, title);
                    if (mainChoice == 1) 
                        cout << (sll.searchSong(title) ? "Found" : "Not Found") << endl;
                    else if (mainChoice == 2) 
                        cout << (dll.searchSong(title) ? "Found" : "Not Found") << endl;
                    else if (mainChoice == 3) 
                        cout << (cll.searchSong(title) ? "Found" : "Not Found") << endl;
                    break;
                case 4:
                    cout << "Enter song title to update: ";
                    cin.ignore();
                    getline(cin, title);
                    cout << "Enter new title: ";
                    getline(cin, newTitle);
                    cout << "Enter new artist: ";
                    getline(cin, artist);
                    cout << "Enter new duration: ";
                    cin >> newDuration;
                    if (mainChoice == 1) sll.updateSong(title, newTitle, artist, newDuration);
                    else if (mainChoice == 2) dll.updateSong(title, newTitle, artist, newDuration);
                    else if (mainChoice == 3) cll.updateSong(title, newTitle, artist, newDuration);
                    break;
                case 5:
                    if (mainChoice == 1) sll.displayPlaylist();
                    else if (mainChoice == 2) dll.displayPlaylist();
                    else if (mainChoice == 3) cll.displayPlaylist();
                    break;
                case 6:
                    if (mainChoice == 1) sll.arrangeSongs();
                    else if (mainChoice == 2) dll.arrangeSongs();
                    else if (mainChoice == 3) cll.arrangeSongs();
                    break;
                case 7:
                    break;
                default:
                    cout << "Invalid choice!" << endl;
            }
        } while (listChoice != 7);
    } while (mainChoice != 4);
    return 0;
}