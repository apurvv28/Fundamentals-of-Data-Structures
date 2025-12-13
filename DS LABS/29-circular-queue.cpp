#include <iostream>
using namespace std;

#define MAX 5

class CircularQueue {
    int cq[MAX];
    int front, rear;

public:
    CircularQueue() {
        front = -1;
        rear = -1;
    }

    void enqueue(int x) {
        if ((rear + 1) % MAX == front) {
            cout << "Circular Queue Overflow\n";
            return;
        }

        if (front == -1) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % MAX;
        }

        cq[rear] = x;
        cout << x << " enqueued\n";
    }

    void dequeue() {
        if (front == -1) {
            cout << "Circular Queue Underflow\n";
            return;
        }

        cout << cq[front] << " dequeued\n";

        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % MAX;
        }
    }

    void peek() {
        if (front == -1) {
            cout << "Queue is Empty\n";
            return;
        }
        cout << "Front Element: " << cq[front] << endl;
    }

    void display() {
        if (front == -1) {
            cout << "Queue is Empty\n";
            return;
        }

        cout << "Circular Queue Elements: ";
        int i = front;
        while (true) {
            cout << cq[i] << " ";
            if (i == rear)
                break;
            i = (i + 1) % MAX;
        }
        cout << endl;
    }
};

int main() {
    CircularQueue cq;

    cq.enqueue(10);
    cq.enqueue(20);
    cq.enqueue(30);
    cq.enqueue(40);

    cq.display();

    cq.dequeue();
    cq.dequeue();

    cq.display();

    cq.enqueue(50);
    cq.enqueue(60);

    cq.display();

    cq.peek();

    return 0;
}
