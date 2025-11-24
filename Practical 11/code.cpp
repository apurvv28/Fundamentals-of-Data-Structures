#include <iostream>
using namespace std;

class Stack {
private:
    int* arr;
    int top;
    int capacity;
    
public:
    Stack(int size) {
        capacity = size;
        arr = new int[capacity];
        top = -1;
    }
    
    ~Stack() {
        delete[] arr;
    }
    
    void push(int value) {
        if (top == capacity - 1) {
            cout << "Stack overflow" << endl;
            return;
        }
        arr[++top] = value;
    }
    
    int pop() {
        if (isEmpty()) {
            cout << "Stack underflow" << endl;
            return -1;
        }
        return arr[top--];
    }
    
    int peek() {
        if (isEmpty()) {
            return -1;
        }
        return arr[top];
    }
    
    bool isEmpty() {
        return top == -1;
    }
    
    int size() {
        return top + 1;
    }
};

void hanoiRecursive(int n, char from, char to, char aux) {
    if (n == 1) {
        cout << "Move disk 1 from " << from << " to " << to << endl;
        return;
    }
    hanoiRecursive(n - 1, from, aux, to);
    cout << "Move disk " << n << " from " << from << " to " << to << endl;
    hanoiRecursive(n - 1, aux, to, from);
}

void hanoiStack(int n, char from, char to, char aux) {
    Stack st(1000);
    
    st.push(n);
    st.push(from);
    st.push(to);
    st.push(aux);
    st.push(0);
    
    while (!st.isEmpty()) {
        int stage = st.pop();
        char a = st.pop();
        char t = st.pop();
        char f = st.pop();
        int num = st.pop();
        
        if (num == 1) {
            cout << "Move disk 1 from " << f << " to " << t << endl;
            continue;
        }
        
        if (stage == 0) {
            st.push(num);
            st.push(f);
            st.push(t);
            st.push(a);
            st.push(1);
            
            st.push(num - 1);
            st.push(f);
            st.push(a);
            st.push(t);
            st.push(0);
        } else if (stage == 1) {
            cout << "Move disk " << num << " from " << f << " to " << t << endl;
            
            st.push(num - 1);
            st.push(a);
            st.push(t);
            st.push(f);
            st.push(0);
        }
    }
}

int factorialRecursive(int n) {
    if (n == 0 || n == 1) return 1;
    return n * factorialRecursive(n - 1);
}

int factorialStack(int n) {
    Stack st(100);
    int result = 1;
    
    while (n > 1) {
        st.push(n);
        n--;
    }
    
    while (!st.isEmpty()) {
        result *= st.pop();
    }
    
    return result;
}

int main() {
    int choice1, choice2;
    
    cout << "Choose method:\n1. Recursion\n2. Stack\n";
    cin >> choice1;
    
    cout << "Choose operation:\n1. Tower of Hanoi\n2. Factorial\n";
    cin >> choice2;
    
    if (choice2 == 1) {
        int n;
        cout << "Enter number of disks: ";
        cin >> n;
        
        if (choice1 == 1) {
            hanoiRecursive(n, 'A', 'C', 'B');
        } else {
            hanoiStack(n, 'A', 'C', 'B');
        }
    } else {
        int n;
        cout << "Enter number: ";
        cin >> n;
        
        if (choice1 == 1) {
            cout << "Factorial: " << factorialRecursive(n) << endl;
        } else {
            cout << "Factorial: " << factorialStack(n) << endl;
        }
    }
    
    return 0;
}