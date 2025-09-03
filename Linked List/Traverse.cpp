#include<iostream>
using namespace std;

struct Node {
	int data;
	Node *next;
};

void traverse(struct Node *head){
	struct Node *temp = head;
	cout<<"Linked List Nodes :"<<endl;
	while(temp!=NULL){
		cout<<temp->data<<endl;
		temp=temp->next;
	}
}

int main(){
	struct Node *head = new Node;
	struct Node *n1=new Node;
	head->data=10;
	head->next=n1;
	
	n1->data=20;
	n1->next=NULL;
	traverse(head);
	return 0;
	
}
