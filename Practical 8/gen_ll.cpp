#include <iostream>
using namespace std;

struct GLLNode {
    bool isAtom;
    union {
        struct {
            int row;
            int col;
            int val;
        } data;
        GLLNode* sublist;
    };
    GLLNode* next;
};

GLLNode* createAtom(int r, int c, int v) {
    GLLNode* node = new GLLNode;
    node->isAtom = true;
    node->data.row = r;
    node->data.col = c;
    node->data.val = v;
    node->next = nullptr;
    return node;
}

GLLNode* createSublist(GLLNode* list) {
    GLLNode* node = new GLLNode;
    node->isAtom = false;
    node->sublist = list;
    node->next = nullptr;
    return node;
}

void appendNode(GLLNode*& head, GLLNode* node) {
    if (!head) head = node;
    else {
        GLLNode* temp = head;
        while(temp->next) temp = temp->next;
        temp->next = node;
    }
}

void displayGLL(GLLNode* head) {
    GLLNode* temp = head;
    while(temp) {
        if(temp->isAtom) {
            cout << "(" << temp->data.row << "," << temp->data.col << ")=" << temp->data.val;
        } else {
            cout << "{ ";
            displayGLL(temp->sublist);
            cout << " }";
        }
        if(temp->next) cout << " -> ";
        temp = temp->next;
    }
}

int main() {
    GLLNode* matrix = nullptr;

    GLLNode* row0 = nullptr;
    appendNode(row0, createAtom(0,1,5));
    appendNode(row0, createAtom(0,3,8));
    appendNode(matrix, createSublist(row0));

    GLLNode* row1 = nullptr;
    appendNode(row1, createAtom(1,0,3));
    appendNode(row1, createAtom(1,2,6));
    appendNode(matrix, createSublist(row1));

    cout << "Sparse matrix GLL representation:\n";
    displayGLL(matrix);
    cout << endl;

    return 0;
}
