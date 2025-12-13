#include <iostream>
using namespace std;
#define MAX 5
class Deque {
    int dq[MAX];
    int front, rear;
public:
    Deque() {
        front = -1;
        rear = -1;
    }
    void insertFront(int x) {
        if (front == 0) {
            cout << "Deque Overflow at Front\n";
            return;
        }
        if (front == -1) {
            front = rear = 0;
        } else {
            front--;
        }
        dq[front] = x;
        cout << x << " inserted at front\n";
    }
    void insertRear(int x) {
        if (rear == MAX - 1) {
            cout << "Deque Overflow at Rear\n";
            return;
        }
        if (rear == -1) {
            front = rear = 0;
        } else {
            rear++;
        }
        dq[rear] = x;
        cout << x << " inserted at rear\n";
    }
    void deleteFront() {
        if (front == -1 || front > rear) {
            cout << "Deque Underflow\n";
            return;
        }
        cout << dq[front] << " deleted from front\n";
        front++;
    }
    void deleteRear() {
        if (front == -1 || front > rear) {
            cout << "Deque Underflow\n";
            return;
        }
        cout << dq[rear] << " deleted from rear\n";
        rear--;
    }
    void display() {
        if (front == -1 || front > rear) {
            cout << "Deque is Empty\n";
            return;
        }
        cout << "Deque Elements: ";
        for (int i = front; i <= rear; i++) {
            cout << dq[i] << " ";
        }
        cout << endl;
    }
};
int main() {
    Deque d;
    d.insertRear(10);
    d.insertRear(20);
    d.insertFront(5);
    d.display();
    d.deleteFront();
    d.deleteRear();
    d.display();
    return 0;
}
