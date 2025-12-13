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

int precedence(char c) {
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/') return 2;
    return 0;
}

int main() {
    char infix[MAX], prefix[MAX];
    cout << "Enter infix expression: ";
    cin >> infix;

    // Step 1: Reverse infix and swap brackets
    strrev(infix);
    for (int i = 0; infix[i]; i++) {
        if (infix[i] == '(') infix[i] = ')';
        else if (infix[i] == ')') infix[i] = '(';
    }

    int k = 0;

    // Step 2: Convert to postfix
    for (int i = 0; infix[i]; i++) {
        char ch = infix[i];

        if (isalnum(ch)) {
            prefix[k++] = ch;
        }
        else if (ch == '(') {
            push(ch);
        }
        else if (ch == ')') {
            while (top != -1 && stack[top] != '(')
                prefix[k++] = pop();
            pop();
        }
        else {
            while (top != -1 && precedence(stack[top]) >= precedence(ch))
                prefix[k++] = pop();
            push(ch);
        }
    }

    while (top != -1)
        prefix[k++] = pop();

    prefix[k] = '\0';

    // Step 3: Reverse postfix to get prefix
    strrev(prefix);

    cout << "Prefix expression: " << prefix << endl;

    return 0;
}
