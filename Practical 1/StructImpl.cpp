#include <iostream>
#include <string>
using namespace std;

struct stud{
	int roll;
	string div;
	string name;
	string marks;
};

void display(stud s[]){
	for(int i=0;i<5;i++){
	cout<<"----------------------------------"<<endl;
	cout<<"Student Information"<<endl;
	cout<<"Name = "<<s[i].name<<endl;
	cout<<"Roll No. "<<s[i].roll<<endl;
	cout<<"Division = "<<s[i].div<<endl;
	cout<<"Marks = "<<s[i].marks<<endl;
	cout<<"----------------------------------"<<endl;
	}
}
int main(){
	stud s[5];
	for(int i=0;i<5;i++){
		cout<<"Enter student name ="<<endl;
		cin>> s[i].name;
		cout<<"Enter student division ="<<endl;
		cin>> s[i].div;
		cout<<"Enter student roll number ="<<endl;
		cin>> s[i].roll;
		cout<<"Enter marks ="<<endl;
		cin>> s[i].marks;
	}
	display(s);
	return 0;
}
