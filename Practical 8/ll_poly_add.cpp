#include <iostream>
using namespace std;

struct Node{
    int coeff;
    int exp;
    Node* next;
};

void insertNode(Node*& head, int coeff, int exp) {
    Node* newNode = new Node();
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = nullptr;

    if (head == nullptr || head->exp < exp) {
        newNode->next = head;
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr && temp->next->exp >= exp) {
            if (temp->next->exp == exp) {
                temp->next->coeff += coeff;
                delete newNode;
                return;
            }
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void printPolynomial(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->coeff << "x^" << temp->exp;
        temp = temp->next;
        if (temp != nullptr) cout << " + ";
    }
    cout << endl;
}

Node* addPolynomials(Node* poly1, Node* poly2) {
    Node* result = nullptr;
    Node* p1 = poly1;
    Node* p2 = poly2;

    while (p1 != nullptr && p2 != nullptr) {
        if (p1->exp > p2->exp) {
            insertNode(result, p1->coeff, p1->exp);
            p1 = p1->next;
        } else if (p1->exp < p2->exp) {
            insertNode(result, p2->coeff, p2->exp);
            p2 = p2->next;
        } else {
            insertNode(result, p1->coeff + p2->coeff, p1->exp);
            p1 = p1->next;
            p2 = p2->next;
        }
    }

    while (p1 != nullptr) {
        insertNode(result, p1->coeff, p1->exp);
        p1 = p1->next;
    }

    while (p2 != nullptr) {
        insertNode(result, p2->coeff, p2->exp);
        p2 = p2->next;
    }

    return result;
}

int main(){
    Node* poly1 = nullptr;
    Node* poly2 = nullptr;

    insertNode(poly1, 5, 3);
    insertNode(poly1, 4, 2);
    insertNode(poly1, 2, 0);

    insertNode(poly2, 3, 3);
    insertNode(poly2, 2, 1);
    insertNode(poly2, 1, 0);

    cout << "First Polynomial: ";
    printPolynomial(poly1);

    cout << "Second Polynomial: ";
    printPolynomial(poly2);

    Node* result = addPolynomials(poly1, poly2);
    cout << "Resultant Polynomial after Addition: ";
    printPolynomial(result);
    return 0;
}