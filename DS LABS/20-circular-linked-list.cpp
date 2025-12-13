#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* last = NULL;

// Insert at beginning
void insertBegin(int x) {
    Node* temp = new Node();
    temp->data = x;

    if (last == NULL) {
        last = temp;
        last->next = last;
    } else {
        temp->next = last->next;
        last->next = temp;
    }
}

// Insert at end
void insertEnd(int x) {
    Node* temp = new Node();
    temp->data = x;

    if (last == NULL) {
        last = temp;
        last->next = last;
    } else {
        temp->next = last->next;
        last->next = temp;
        last = temp;
    }
}

// Delete from beginning
void deleteBegin() {
    if (last == NULL) {
        cout << "List is Empty\n";
        return;
    }

    Node* temp = last->next;

    if (last->next == last) {
        last = NULL;
    } else {
        last->next = temp->next;
    }
    delete temp;
}

// Delete from end
void deleteEnd() {
    if (last == NULL) {
        cout << "List is Empty\n";
        return;
    }

    Node* curr = last->next;

    if (last->next == last) {
        delete last;
        last = NULL;
        return;
    }

    while (curr->next != last) {
        curr = curr->next;
    }

    curr->next = last->next;
    delete last;
    last = curr;
}

// Traverse and display
void display() {
    if (last == NULL) {
        cout << "List is Empty\n";
        return;
    }

    Node* temp = last->next;
    cout << "Circular List: ";
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != last->next);
    cout << endl;
}

// Search element
void search(int key) {
    if (last == NULL) {
        cout << "List is Empty\n";
        return;
    }

    Node* temp = last->next;
    int pos = 1;

    do {
        if (temp->data == key) {
            cout << "Element found at position " << pos << endl;
            return;
        }
        temp = temp->next;
        pos++;
    } while (temp != last->next);

    cout << "Element not found\n";
}

int main() {
    insertBegin(10);
    insertEnd(20);
    insertEnd(30);
    insertBegin(5);

    display();

    deleteBegin();
    deleteEnd();

    display();

    search(20);
    search(100);

    return 0;
}
