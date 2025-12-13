#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;
};
class Queue {
    Node* front;
    Node* rear;
public:
    Queue() {
        front = NULL;
        rear = NULL;
    }
    void enqueue(int x) {
        Node* temp = new Node();
        temp->data = x;
        temp->next = NULL;
        if (rear == NULL) {
            front = rear = temp;
        } else {
            rear->next = temp;
            rear = temp;
        }
        cout << x << " enqueued into queue\n";
    }
    void dequeue() {
        if (front == NULL) {
            cout << "Queue Underflow\n";
            return;
        }
        Node* temp = front;
        cout << temp->data << " dequeued from queue\n";
        front = front->next;
        delete temp;

        if (front == NULL)
            rear = NULL;
    }
    void display() {
        if (front == NULL) {
            cout << "Queue is Empty\n";
            return;
        }
        cout << "Queue Elements: ";
        Node* temp = front;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};
int main() {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();
    q.dequeue();
    q.dequeue();
    q.display();
    return 0;
}
