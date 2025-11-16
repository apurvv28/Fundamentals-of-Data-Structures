//In real-world software like music playlists different types of linked lists are used to manage dynamic data efficiently. Implement singly, doubly, circular, and doubly circular linked lists to explore how each structure handles various operations such as create, insert, delete, traverse, search, sort, and concatenate. Simulate practical scenarios (like adding, deleting, updating or rearranging songs to playlist) to understand the strengths and use-cases of each linked list type.
#include <iostream>
#include <string>
using namespace std;

struct Song {
    string name;
    Song* next;
    Song* prev;
};

struct Playlist {
    string title;
    Song* stitle;
    Playlist* next;
    Playlist* prev; 
};

string getPlaylistTitle() {
    string title;
    cout << "Enter playlist title: ";
    getline(cin, title);
    return title;
}

void createPlaylist(Playlist*& head, const string& title) {
    Playlist* newNode = new Playlist();
    newNode->title = title;
    newNode->next = NULL;
    newNode->prev = NULL;
    if(head==NULL){
        head=newNode;
    }else{
        Playlist* temp = head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newNode;
        newNode->prev=temp;
    }
}

void displayPlaylists(Playlist* head) {
    Playlist* temp = head;
    cout << "\nPlaylists: " << endl;
    while (temp != NULL) {
        cout << "- " << temp->title << endl;
        temp = temp->next;
    }
}

void addSongs(Playlist* head){
    string song, ptitle;
    Playlist* temp=head;
    cout<<"\nEnter playlist title to add songs: "<<endl;
    getline(cin, ptitle);
    while(temp!=NULL && temp->title!=ptitle){
        temp=temp->next;
    }
    if(temp==NULL){
        cout<<"Playlist not found!"<<endl;
        return;
    }else{
        cout<<"Adding songs to playlist: "<<ptitle<<endl;
    }
    cout<<"Enter a song to add in playlist: "<<endl;
    getline(cin, song);
    Song* newSong = new Song();
    newSong->name = song;
    newSong->next = NULL;
    newSong->prev = NULL;
    if(temp->stitle==NULL){
        temp->stitle=newSong;
        cout<<"Song added to playlist successfully!"<<endl;
        return;
    }else{
        Song* stemp = temp->stitle;
        while(stemp->next!=NULL){
            stemp=stemp->next;
        }
        stemp->next=newSong;
        newSong->prev=stemp;
        cout<<"Song added to playlist successfully!"<<endl;
        return;
    }
    cout<<"Playlist is full, cannot add more songs!"<<endl;
}

void displaySongs(Playlist* head, const string& title) {
    Playlist* temp = head;
    while (temp != NULL && temp->title != title) {
        temp = temp->next;
    }
    if (temp == NULL) {
        cout << "Playlist not found!" << endl;
        return;
    }
    cout << "\nSongs in Playlist '" << title << "':" << endl;
    Song* stemp = temp->stitle;
    while(stemp != NULL){
        cout<<"- "<<stemp->name<<endl;
        stemp = stemp->next;
    }
}

void searchSong(Playlist* head){
    string song;
    cout<<"Enter song name to search: "<<endl;
    getline(cin, song);
    Playlist* temp = head;
    while(temp!=NULL){
        Song* stemp = temp->stitle;
        while(stemp!=NULL){
            if(stemp->name==song){
                cout<<"Song found in playlist: "<<temp->title<<endl;
                return;
            }
            stemp=stemp->next;
        }
        temp=temp->next;
    }
}

void swap(Song* &a, Song* &b){
    Song* temp = a;
    a = b;
    b = temp;
}

void sortSongs(Playlist* head){
    cout<<"\nEnter a playlist name to sort it's songs: "<<endl;
    getline(cin, head->title);
    Playlist* temp = head;
    while(temp!=NULL){
        if(temp->stitle==NULL){
            temp=temp->next;
            continue;
        }
        Song* stemp1 = temp->stitle;
        while(stemp1!=NULL){
            Song* stemp2 = stemp1->next;
            while(stemp2!=NULL){
                if(stemp1->name > stemp2->name){
                    swap(stemp1->name, stemp2->name);
                }
                stemp2=stemp2->next;
            }
            stemp1=stemp1->next;
        }
        temp=temp->next;
    }
    cout<<"Songs sorted successfully!"<<endl;
}

void concateSongsOfPlaylists(Playlist* &head){
    //using doubly linked list for concatenation
    if(head==NULL || head->next==NULL){
        cout<<"Not enough playlists to concatenate!"<<endl;
        return;
    }
    Playlist* temp = head;
    while(temp->next!=NULL){
        Song* stemp = temp->stitle;
        if(stemp==NULL){
            temp=temp->next;
            continue;
        }
        while(stemp->next!=NULL){
            stemp=stemp->next;
        }
        stemp->next = temp->next->stitle;
        if(temp->next->stitle!=NULL){
            temp->next->stitle->prev = stemp;
        }
        temp=temp->next;
    }
}

int main() {
    Playlist* head = NULL;
    int choice;
    string title;
    do {
        cout << "\n--------Sasta Spotify--------" << endl;
        cout << "1. Create Playlist" << endl;
        cout << "2. Display Playlists" << endl;
        cout << "3. Add Songs to Playlist" << endl;
        cout << "4. Display Songs in Playlist" << endl;
        cout << "5. Search for a Song" << endl;
        cout << "6. Sort Songs in Playlists" << endl;
        cout << "7. Concatenate Playlists" << endl;
        cout << "8. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); 
        switch (choice) {
            case 1:
                title = getPlaylistTitle();
                createPlaylist(head, title);
                break;
            case 2:
                displayPlaylists(head);
                break;
            case 3:
                addSongs(head);
                break;
            case 4:
                cout << "Enter playlist title to display songs: ";
                getline(cin, title);
                displaySongs(head, title);
                break;
            case 5:
                searchSong(head);
                break;
            case 6:
                sortSongs(head);
                break;
            case 7:
                concateSongsOfPlaylists(head);
                break;
            case 8:
                cout << "Exiting Playlist Management System." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 8);
    return 0;
}