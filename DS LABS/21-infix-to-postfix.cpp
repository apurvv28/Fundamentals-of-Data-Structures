#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) {
    stack[++top] = c;
}

char pop() {
    return stack[top--];
}

char peek() {
    return stack[top];
}

int precedence(char c) {
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/') return 2;
    return 0;
}

int main() {
    char infix[MAX], postfix[MAX];
    int k = 0;

    cout << "Enter infix expression: ";
    cin.getline(infix, MAX);

    for (int i = 0; infix[i] != '\0'; i++) {
        char ch = infix[i];

        // Operand (multi-digit)
        if (isdigit(ch)) {
            while (isdigit(infix[i])) {
                postfix[k++] = infix[i++];
            }
            postfix[k++] = ' ';
            i--;
        }
        // Opening bracket
        else if (ch == '(') {
            push(ch);
        }
        // Closing bracket
        else if (ch == ')') {
            while (top != -1 && peek() != '(') {
                postfix[k++] = pop();
                postfix[k++] = ' ';
            }
            pop(); // remove '('
        }
        // Operator
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            while (top != -1 && precedence(peek()) >= precedence(ch)) {
                postfix[k++] = pop();
                postfix[k++] = ' ';
            }
            push(ch);
        }
        // Ignore spaces
        else if (ch == ' ') {
            continue;
        }
        // Invalid input
        else {
            cout << "Invalid character found!\n";
            return 0;
        }
    }

    // Pop remaining operators
    while (top != -1) {
        postfix[k++] = pop();
        postfix[k++] = ' ';
    }

    postfix[k] = '\0';

    cout << "Postfix Expression: " << postfix << endl;

    return 0;
}
