#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

// Insert at beginning
void insertBegin(int x) {
    Node* temp = new Node();
    temp->data = x;
    temp->next = head;
    head = temp;
}

// Insert at end
void insertEnd(int x) {
    Node* temp = new Node();
    temp->data = x;
    temp->next = NULL;

    if (head == NULL) {
        head = temp;
        return;
    }

    Node* curr = head;
    while (curr->next != NULL)
        curr = curr->next;

    curr->next = temp;
}

// Insert at position
void insertPos(int x, int pos) {
    if (pos == 1) {
        insertBegin(x);
        return;
    }

    Node* curr = head;
    for (int i = 1; i < pos - 1 && curr != NULL; i++)
        curr = curr->next;

    if (curr == NULL) {
        cout << "Invalid Position\n";
        return;
    }

    Node* temp = new Node();
    temp->data = x;
    temp->next = curr->next;
    curr->next = temp;
}

// Delete from beginning
void deleteBegin() {
    if (head == NULL) {
        cout << "List is Empty\n";
        return;
    }

    Node* temp = head;
    head = head->next;
    delete temp;
}

// Delete from end
void deleteEnd() {
    if (head == NULL) {
        cout << "List is Empty\n";
        return;
    }

    if (head->next == NULL) {
        delete head;
        head = NULL;
        return;
    }

    Node* curr = head;
    while (curr->next->next != NULL)
        curr = curr->next;

    delete curr->next;
    curr->next = NULL;
}

// Delete at position
void deletePos(int pos) {
    if (pos == 1) {
        deleteBegin();
        return;
    }

    Node* curr = head;
    for (int i = 1; i < pos - 1 && curr != NULL; i++)
        curr = curr->next;

    if (curr == NULL || curr->next == NULL) {
        cout << "Invalid Position\n";
        return;
    }

    Node* temp = curr->next;
    curr->next = temp->next;
    delete temp;
}

// Search element
void search(int key) {
    Node* curr = head;
    int pos = 1;

    while (curr != NULL) {
        if (curr->data == key) {
            cout << "Element found at position " << pos << endl;
            return;
        }
        curr = curr->next;
        pos++;
    }
    cout << "Element not found\n";
}

// Display list
void display() {
    if (head == NULL) {
        cout << "List is Empty\n";
        return;
    }

    Node* curr = head;
    cout << "Linked List: ";
    while (curr != NULL) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

int main() {
    insertBegin(10);
    insertEnd(20);
    insertEnd(30);
    insertPos(15, 2);

    display();

    deleteBegin();
    deleteEnd();
    deletePos(2);

    display();

    search(20);
    search(100);

    return 0;
}
