#include<iostream>
using namespace std;

struct Node{
	int data;
	Node *next;
};

void traverse(Node *n){
	Node *temp = n;
	cout<<endl<<"Linked List : ";
	while(temp != NULL){
		cout<<temp->data<<", ";
		temp=temp->next;
	}
}

void search(Node *n){
	Node *temp = n;
	int num, pos=1;
	cout<<"Enter a value to search : "<<endl;
	cin>>num;
	while(temp != NULL && num != temp->data){
		pos++;
	}
	cout<<"Value present at "<<pos<<" in linked list "<<endl;
}

void insert_beg(Node *&n){
	Node *newNode=new Node;
	int num;
	cout<<"Enter value to insert "<<endl;
	cin>>num;
	newNode -> data = num;
	newNode -> next = n;
	n = newNode;
}

void insert_end(Node *&n){
	Node *newNode = new Node;
	Node *temp;
	int num;
	cout<<"Enter a value to insert "<<endl;
	cin>>num;
	newNode -> data = num;
	newNode -> next = NULL;
	if(n==NULL){
		n = newNode;
		return;
	}
	temp = n;
	
	while(temp->next != NULL){
		temp = temp->next;
	}
	temp->next=newNode;
}

void insert_after(Node *&n){
	Node *newNode = new Node;
	Node *temp;
	int num, counter=1;
	cout<<"Enter a value to insert "<<endl;
	cin>>num;
	newNode->data = num;
	newNode->next = NULL;
	if(n==NULL){
		n = newNode;
		return;
	}
	temp = n;
	int pos;
	cout<<"Enter after which index you want to insert "<<endl;
	cin>>pos;
	while(temp->data!=NULL && counter<pos){
		temp = temp->next;
		counter++;
	}
	newNode -> next = temp -> next;
	temp -> next = newNode;
}

void insert_before(Node *&n){
	Node *newNode = new Node;
	Node *temp;
	int num, counter=1;
	cout<<"Enter a value to insert "<<endl;
	cin>>num;
	newNode->data = num;
	newNode->next = NULL;
	if(n==NULL){
		n = newNode;
		return;
	}
	temp = n;
	int pos;
	cout<<"Enter before which index you want to insert "<<endl;
	cin>>pos;
	while(temp->data!=NULL && temp->data!=pos){
		temp = temp->next;
//		counter++;
	}
	if((temp->data!=NULL && temp->data==pos))
	{
		newNode -> next = temp -> next;
	temp -> next = newNode;
	}
	
	
	if(temp==NULL){
		cout<<"Out of bound"<<endl;
	}
}

int main(){
	Node *head = NULL;
	insert_beg(head);
	insert_end(head);
	insert_end(head);
	insert_end(head);
	insert_before(head);
	traverse(head);
	return 0;
}
