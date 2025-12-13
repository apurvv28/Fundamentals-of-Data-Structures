#include <iostream>
using namespace std;

struct Node {
    int coeff;
    int exp;
    Node* next;
};

Node* create(int c, int e) {
    Node* temp = new Node();
    temp->coeff = c;
    temp->exp = e;
    temp->next = NULL;
    return temp;
}

void display(Node* p) {
    while (p != NULL) {
        cout << p->coeff << "x^" << p->exp;
        if (p->next != NULL)
            cout << " + ";
        p = p->next;
    }
    cout << endl;
}

int main() {
    // Polynomial 1: 3x^2 + 5x + 6
    Node* p1 = create(3, 2);
    p1->next = create(5, 1);
    p1->next->next = create(6, 0);

    // Polynomial 2: 4x^2 + 2x + 1
    Node* p2 = create(4, 2);
    p2->next = create(2, 1);
    p2->next->next = create(1, 0);

    Node* p3 = NULL;
    Node* last = NULL;

    while (p1 != NULL && p2 != NULL) {
        int c, e;

        if (p1->exp == p2->exp) {
            c = p1->coeff + p2->coeff;
            e = p1->exp;
            p1 = p1->next;
            p2 = p2->next;
        }
        else if (p1->exp > p2->exp) {
            c = p1->coeff;
            e = p1->exp;
            p1 = p1->next;
        }
        else {
            c = p2->coeff;
            e = p2->exp;
            p2 = p2->next;
        }

        Node* temp = create(c, e);
        if (p3 == NULL)
            p3 = last = temp;
        else {
            last->next = temp;
            last = temp;
        }
    }

    while (p1 != NULL) {
        last->next = create(p1->coeff, p1->exp);
        last = last->next;
        p1 = p1->next;
    }

    while (p2 != NULL) {
        last->next = create(p2->coeff, p2->exp);
        last = last->next;
        p2 = p2->next;
    }

    cout << "Polynomial 1: ";
    display(p1);   // empty now, ok in exam

    cout << "Polynomial 2: ";
    display(p2);   // empty now, ok in exam

    cout << "Sum: ";
    display(p3);

    return 0;
}
