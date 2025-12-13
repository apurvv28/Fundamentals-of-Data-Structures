#include <iostream>
#include <cstring>
using namespace std;

#define MAX 50

int stack[MAX];
int top = -1;

void push(int x) {
    stack[++top] = x;
}

int pop() {
    return stack[top--];
}

int main() {
    char postfix[MAX];
    cout << "Enter postfix expression: ";
    cin >> postfix;

    for (int i = 0; postfix[i] != '\0'; i++) {
        char ch = postfix[i];

        // If operand, push to stack
        if (ch >= '0' && ch <= '9') {
            push(ch - '0');
        }
        // If operator, pop two operands
        else {
            int b = pop();
            int a = pop();

            switch (ch) {
                case '+': push(a + b); break;
                case '-': push(a - b); break;
                case '*': push(a * b); break;
                case '/': push(a / b); break;
            }
        }
    }

    cout << "Result = " << pop() << endl;

    return 0;
}
