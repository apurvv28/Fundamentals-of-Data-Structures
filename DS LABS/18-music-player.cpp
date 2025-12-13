#include <iostream>
using namespace std;

struct Song {
    string name;
    Song* prev;
    Song* next;
};

Song* head = NULL;
Song* current = NULL;

// Add song at end
void addSong(string s) {
    Song* temp = new Song();
    temp->name = s;
    temp->next = NULL;

    if (head == NULL) {
        temp->prev = NULL;
        head = current = temp;
    } else {
        Song* curr = head;
        while (curr->next != NULL)
            curr = curr->next;

        curr->next = temp;
        temp->prev = curr;
    }
    cout << "Song added: " << s << endl;
}

// Delete current song
void deleteSong() {
    if (current == NULL) {
        cout << "Playlist is empty\n";
        return;
    }

    cout << "Deleted song: " << current->name << endl;

    if (current->prev)
        current->prev->next = current->next;
    else
        head = current->next;

    if (current->next)
        current->next->prev = current->prev;

    Song* temp = current;
    current = (current->next) ? current->next : current->prev;
    delete temp;
}

// Move to next song
void nextSong() {
    if (current && current->next) {
        current = current->next;
        cout << "Now playing: " << current->name << endl;
    } else {
        cout << "No next song\n";
    }
}

// Move to previous song
void prevSong() {
    if (current && current->prev) {
        current = current->prev;
        cout << "Now playing: " << current->name << endl;
    } else {
        cout << "No previous song\n";
    }
}

// Display playlist
void displayPlaylist() {
    if (head == NULL) {
        cout << "Playlist is empty\n";
        return;
    }

    Song* temp = head;
    cout << "Playlist:\n";
    while (temp != NULL) {
        if (temp == current)
            cout << "-> ";
        else
            cout << "   ";
        cout << temp->name << endl;
        temp = temp->next;
    }
}

int main() {
    addSong("Song A");
    addSong("Song B");
    addSong("Song C");

    displayPlaylist();

    nextSong();
    nextSong();
    prevSong();

    deleteSong();

    displayPlaylist();

    return 0;
}
