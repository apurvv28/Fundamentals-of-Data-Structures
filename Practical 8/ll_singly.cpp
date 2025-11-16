#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

void traverse(Node* head){
    Node* temp = head;
    cout<<"\nLinked List : ";
    while(temp!=NULL){
        cout<<temp->data<<", ";
        temp=temp->next;
    }
    cout<<endl;
}

void insert(Node* &head){
    Node* temp, *newNode;
    newNode = new Node();
    int num;
    cout<<"Enter data to insert: "<<endl;
    cin>>num;
    newNode->data = num;
    newNode->next = NULL;
    temp = head;
    if(head == NULL){
        head = newNode;
    }
    else{
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void deleteNode(Node* &head, int key){
    Node* temp = head;
    Node* prev = NULL;
    if(temp != NULL && temp->data == key){
        head = temp->next;
        delete temp;
        return;
    }
    while(temp != NULL && temp->data != key){
        prev = temp;
        temp = temp->next;
    }
    if(temp == NULL) return;
    prev->next = temp->next;
    delete temp;
}

int main(){
    Node* head = NULL;
    cout<<"Linked List Operations"<<endl;
    insert(head);
    insert(head);
    traverse(head);
    deleteNode(head, 20);
    traverse(head);
    return 0;
}