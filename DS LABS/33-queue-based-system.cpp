#include <iostream>
using namespace std;
#define MAX 5
class PrinterQueue {
    int queue[MAX];
    int front, rear;
public:
    PrinterQueue() {
        front = -1;
        rear = -1;
    }
    void addJob(int jobId) {
        if (rear == MAX - 1) {
            cout << "Printer Queue is Full\n";
            return;
        }
        if (front == -1)
            front = 0;
        rear++;
        queue[rear] = jobId;
        cout << "Print Job " << jobId << " added to queue\n";
    }
    void processJob() {
        if (front == -1 || front > rear) {
            cout << "No print jobs to process\n";
            return;
        }
        cout << "Processing Print Job " << queue[front] << endl;
        front++;
    }
    void displayQueue() {
        if (front == -1 || front > rear) {
            cout << "Queue is Empty\n";
            return;
        }
        cout << "Pending Print Jobs: ";
        for (int i = front; i <= rear; i++) {
            cout << queue[i] << " ";
        }
        cout << endl;
    }
};
int main() {
    PrinterQueue pq;
    pq.addJob(101);
    pq.addJob(102);
    pq.addJob(103);
    pq.displayQueue();
    pq.processJob();
    pq.processJob();
    pq.displayQueue();
    return 0;
}