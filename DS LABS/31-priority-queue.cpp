#include <iostream>
using namespace std;
#define MAX 5
class PriorityQueue {
    int data[MAX];
    int priority[MAX];
    int size;
public:
    PriorityQueue() {
        size = 0;
    }
    void insert(int value, int pr) {
        if (size == MAX) {
            cout << "Priority Queue Overflow\n";
            return;
        }
        data[size] = value;
        priority[size] = pr;
        size++;
        cout << "Inserted value " << value << " with priority " << pr << endl;
    }
    void deleteElement() {
        if (size == 0) {
            cout << "Priority Queue Underflow\n";
            return;
        }
        int highest = 0;
        for (int i = 1; i < size; i++) {
            if (priority[i] < priority[highest]) {
                highest = i;
            }
        }
        cout << "Deleted value " << data[highest]
             << " with priority " << priority[highest] << endl;
        for (int i = highest; i < size - 1; i++) {
            data[i] = data[i + 1];
            priority[i] = priority[i + 1];
        }
        size--;
    }
    void display() {
        if (size == 0) {
            cout << "Priority Queue is Empty\n";
            return;
        }
        cout << "Value  Priority\n";
        for (int i = 0; i < size; i++) {
            cout << data[i] << "        " << priority[i] << endl;
        }
    }
};
int main() {
    PriorityQueue pq;
    pq.insert(10, 3);
    pq.insert(20, 1);
    pq.insert(30, 2);
    pq.display();
    pq.deleteElement();
    pq.display();
    return 0;
}