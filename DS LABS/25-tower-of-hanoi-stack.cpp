#include <iostream>
using namespace std;

#define MAX 50

struct Frame {
    int n;
    char from, to, aux;
    int stage;
};

int main() {
    Frame stack[MAX];
    int top = -1;

    int n;
    cout << "Enter number of disks: ";
    cin >> n;

    // push initial problem
    stack[++top] = {n, 'A', 'C', 'B', 0};

    while (top != -1) {
        Frame cur = stack[top--];

        if (cur.n == 1) {
            cout << "Move disk 1 from "
                 << cur.from << " to " << cur.to << endl;
        } 
        else {
            if (cur.stage == 0) {
                // simulate recursion
                cur.stage = 1;
                stack[++top] = cur;   // save current state

                stack[++top] = {cur.n - 1, cur.from, cur.aux, cur.to, 0};
            }
            else {
                cout << "Move disk " << cur.n << " from "
                     << cur.from << " to " << cur.to << endl;

                stack[++top] = {cur.n - 1, cur.aux, cur.to, cur.from, 0};
            }
        }
    }

    return 0;
}
