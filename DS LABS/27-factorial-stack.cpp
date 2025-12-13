#include <iostream>
using namespace std;

#define MAX 10

class Stack {
    int st[MAX];
    int top;

public:
    Stack() {
        top = -1;
    }

    void push(int x) {
        st[++top] = x;
    }

    int pop() {
        return st[top--];
    }

    bool isEmpty() {
        return top == -1;
    }
};

int main() {
    int n, fact = 1;
    Stack s;

    cout << "Enter a number: ";
    cin >> n;

    // Push values onto stack
    for (int i = n; i >= 1; i--) {
        s.push(i);
    }

    // Pop and calculate factorial
    while (!s.isEmpty()) {
        fact = fact * s.pop();
    }

    cout << "Factorial of " << n << " is " << fact << endl;

    return 0;
}
