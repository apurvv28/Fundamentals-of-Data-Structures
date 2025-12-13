#include <iostream>
using namespace std;

#define MAX 5

class Queue {
    int q[MAX];
    int front, rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    void enqueue(int x) {
        if (rear == MAX - 1) {
            cout << "Queue Overflow\n";
            return;
        }

        if (front == -1)
            front = 0;

        rear++;
        q[rear] = x;
        cout << x << " enqueued\n";
    }

    void dequeue() {
        if (front == -1 || front > rear) {
            cout << "Queue Underflow\n";
            return;
        }

        cout << q[front] << " dequeued\n";
        front++;
    }

    void peek() {
        if (front == -1 || front > rear) {
            cout << "Queue is Empty\n";
            return;
        }
        cout << "Front Element: " << q[front] << endl;
    }

    void display() {
        if (front == -1 || front > rear) {
            cout << "Queue is Empty\n";
            return;
        }

        cout << "Queue Elements: ";
        for (int i = front; i <= rear; i++) {
            cout << q[i] << " ";
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
    q.peek();

    q.dequeue();
    q.dequeue();

    q.display();

    q.dequeue();
    q.dequeue();   // underflow

    return 0;
}
