#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

Node* head = NULL;

// Insert at beginning
void insertBegin(int x) {
    Node* temp = new Node();
    temp->data = x;
    temp->prev = NULL;
    temp->next = head;

    if (head != NULL)
        head->prev = temp;

    head = temp;
}

// Insert at end
void insertEnd(int x) {
    Node* temp = new Node();
    temp->data = x;
    temp->next = NULL;

    if (head == NULL) {
        temp->prev = NULL;
        head = temp;
        return;
    }

    Node* curr = head;
    while (curr->next != NULL)
        curr = curr->next;

    curr->next = temp;
    temp->prev = curr;
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
    temp->prev = curr;

    if (curr->next != NULL)
        curr->next->prev = temp;

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

    if (head != NULL)
        head->prev = NULL;

    delete temp;
}

// Delete from end
void deleteEnd() {
    if (head == NULL) {
        cout << "List is Empty\n";
        return;
    }

    Node* curr = head;

    if (curr->next == NULL) {
        delete curr;
        head = NULL;
        return;
    }

    while (curr->next != NULL)
        curr = curr->next;

    curr->prev->next = NULL;
    delete curr;
}

// Delete at position
void deletePos(int pos) {
    if (pos == 1) {
        deleteBegin();
        return;
    }

    Node* curr = head;
    for (int i = 1; i < pos && curr != NULL; i++)
        curr = curr->next;

    if (curr == NULL) {
        cout << "Invalid Position\n";
        return;
    }

    if (curr->next != NULL)
        curr->next->prev = curr->prev;

    curr->prev->next = curr->next;
    delete curr;
}

// Display forward
void displayForward() {
    Node* curr = head;
    cout << "Forward: ";
    while (curr != NULL) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

// Display reverse
void displayReverse() {
    Node* curr = head;
    if (curr == NULL) return;

    while (curr->next != NULL)
        curr = curr->next;

    cout << "Reverse: ";
    while (curr != NULL) {
        cout << curr->data << " ";
        curr = curr->prev;
    }
    cout << endl;
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

int main() {
    insertBegin(10);
    insertEnd(20);
    insertEnd(30);
    insertPos(15, 2);

    displayForward();
    displayReverse();

    deleteBegin();
    deleteEnd();
    deletePos(2);

    displayForward();

    search(20);
    search(100);

    return 0;
}
