#include<iostream>
using namespace std;

struct Node{
	int data;
	Node *next;
};

void traverse(Node *&head){
	Node *temp = head;
	cout<<endl<<"Linked List : ";
	while(temp != NULL){
		cout<<temp->data<<", ";
		temp=temp->next;
	}
}

void insert_beg(Node *&head){
	Node *newNode = new Node;
	int num;
	cout<<"Enter a value to insert at beginning in the linked list = "<<endl;
	cin>>num;
	newNode -> data = num;
	newNode -> next = head;
	head = newNode;
}
void insert_end(Node *&head){
	Node *newNode = new Node;
	Node *temp;
	int num;
	cout<<"Enter a value to insert at the end of the linked list = "<<endl;
	cin>>num;
	newNode ->data = num;
	newNode ->next = NULL;
	if(head == NULL){
		head = newNode;
		return;
	}
	temp = head;
	while(temp->next!=NULL){
		temp = temp->next;
	}
	temp->next=newNode;
}

void insert_after(Node *&head){
	Node *newNode = new Node;
	Node *temp;
	int counter = 1, num, pos;
	cout<<"Enter a value to insert after an element in the linked list = "<<endl;
	cin>>num;
	newNode ->data = num;
	newNode ->next = NULL;
	if(head == NULL){
		head = newNode;
		return;
	}
	temp=head;
	cout<<"Enter the element after which you have to insert the new element = "<<endl;
	cin>>pos;
	while(temp->data!=NULL && counter < pos){
		counter++;
		temp=temp->next;
	}
	newNode ->next = temp->next;
	temp->next = newNode;
}

void insert_before(Node *&head){
	Node *newNode = new Node;
	Node *temp = head;
	Node *prev = NULL;
	int num, pos;
	cout<<"Enter the value to insert = "<<endl;
	cin>>num;
	cout<<"Enter the element before which you want to enter this element "<<endl;
	cin>>pos;
	newNode->data=num;
	newNode->next=NULL;
	
	if(head == NULL){
		head = newNode;
		return;
	}
	
	if(head->data == pos){
		newNode->next = head;
		head = newNode;
		return;
	}
	while(temp!=NULL && temp->data!=pos){
		prev = temp;
		temp = temp->next; 
	}
	prev->next = newNode;
	newNode->next = temp;
}

void insert_index(Node *&head){
	int num, pos;
	cout<<"Enter the element to insert = "<<endl;
	cin>>num;
	cout<<"Enter the position at which you want to enter the element = "<<endl;
	cin>>pos;
	Node *newNode = new Node{num, NULL};
	Node *temp = head;
	if(pos<=0){
		cout<<"Invalid Position!"<<endl;
		delete newNode;
		return;
	}
	if(pos == 1){
		newNode->next = head;
		head = newNode;
		return;
	}
	int counter = 1;
	while(temp!=NULL && counter < pos-1){
		temp = temp->next;
		counter++;
	}
	newNode ->next =temp->next;
	temp->next= newNode;
}

void delete_beg(Node *&head){
	if(head==NULL){
		cout<<"Linked list is empty!"<<endl;
		return;
	}
	Node *temp = head;
	head = head->next;
	delete temp;
	cout<<"First node deleted!"<<endl;
}

void delete_last(Node *&head){
	if(head==NULL){
		cout<<"Linked list is empty!"<<endl;
		return;
	}
	if(head->next==NULL){
		delete head;
		head = NULL;
		cout<<"Deleted the last element!"<<endl;
	}
	Node *temp = head;
	while(temp->next->next!=NULL){
		temp=temp->next;
	}
	delete temp->next;
	temp->next=NULL;
	cout<<"Last element deleted"<<endl;
}

void delete_index(Node *&head){
	int pos, counter=1;
	cout<<"Specify the index of the node you want to delete = "<<endl;
	cin>>pos;
	if(head==NULL){
		cout<<"Linked List is empty!"<<endl;
		return;
	}
	if(pos==1){
		Node *temp = head;
		head=head->next;
		delete temp;
		cout<<"Deleted the element!"<<endl;
		return;
	}
	Node *temp=head;
	while(temp!=NULL && counter < pos-1){
		temp=temp->next;
		counter++;
	}
	if(temp==NULL && temp->next==NULL){
		cout<<"Invalid Index!"<<endl;
		return;
	}
	Node *n = temp->next;
	temp->next = n->next;
	delete n;
	cout<<"Node at index "<<pos<<" deleted!"<<endl;
}

void delete_value(Node *&head){
	int val;
	cout<<"Enter a value to delete = "<<endl;
	cin>>val;
	if(head==NULL){
		cout<<"Linked list is empty!"<<endl;
		return;
	}
	if(val==head->data){
		Node *temp = head;
		head=head->next;
		delete temp;
		cout<<"Node deleted successfully!"<<endl;
		return;
	}
	Node *temp = head;
	while(temp!=NULL && temp->next->data!=val){
		temp=temp->next;
	}
	if(temp==NULL && temp->next==NULL){
		cout<<"Invalid Index!"<<endl;
		return;
	}
	Node *n = temp->next;
	temp->next = n->next;
	delete n;
	cout<<"Node with value "<<val<<" deleted!"<<endl;
}

int main(){
	Node *head = NULL;
	insert_end(head);
	insert_end(head);
	insert_end(head);
	insert_index(head);
	delete_value(head);
	traverse(head);
	return 0;
}
