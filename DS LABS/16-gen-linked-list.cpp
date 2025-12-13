#include <iostream>
using namespace std;

struct GLL {
    int tag; //0 for data, 1 for sublist
    union{
        int data;
        GLL* sublist;
    };
    GLL* next;
};

// Create data node
GLL* createData(int x) {
    GLL* temp = new GLL();
    temp->tag=0;
    temp->data=x;
    temp->next=NULL;
    return temp;
}

// Create sublist node
GLL* createSublist(GLL* sub) {
    GLL* temp = new GLL();
    temp->tag=1;
    temp->sublist=sub;
    temp->next=NULL;
    return temp;
}

// Display GLL
void display(GLL* head) {
    cout<<"(";
    while(head!=NULL){
        if(head->tag==0){
            cout<<head->data;
        }else{
            display(head->sublist);
        }
        if(head->next!=NULL){
            cout<<", ";
        }
        head=head->next;
    }
    cout<<")";
}
int main() {
    GLL* n1 = createData(1);
    GLL* n2 = createData(2);
    GLL* n3 = createData(3);
    n2->next = n3;
    GLL* sub = createSublist(n2);
    GLL* n4 = createData(4);
    n1->next = sub;
    sub->next = n4;
    cout << "Generalized Linked List: ";
    display(n1);
    return 0;
}
