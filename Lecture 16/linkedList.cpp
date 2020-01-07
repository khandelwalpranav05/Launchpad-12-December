#include <iostream>

using namespace std;

class node{
public:
	int data;
	node* next;

	node(int data){
		this->data = data;
		this->next = NULL;
	}
};

void insertAtHead(node* &head,int data){
	node* n = new node(data);
	// node* n = new node();
	// n->data = data;
	// (*n).next = head;
	n->next = head;
	head = n;
}



void display(node*head){
	node* temp = head;

	while(temp!=NULL){
		cout<<temp->data<<"->";
		temp = temp->next;
	}

	cout<<"NULL"<<endl;
}

int length(node*head){

	int len = 0;

	node* temp = head;

	while(temp!=NULL){
		len++;
		temp = temp->next;
	}

	return len;
}

bool search(node*head,int item){

	node* temp = head;

	while(temp!=NULL){
		if(item==temp->data){
			return true;
		}
		temp = temp->next;
	}

	return false;
}

void insertAtTail(node*head,int data){
	node* temp = head;

	while(temp->next!=NULL){
		temp = temp->next;
	}

	node* n = new node(data);

	temp->next = n;
}

int main(){

	node* head = NULL;

	insertAtHead(head,10);
	insertAtHead(head,20);
	insertAtHead(head,30);
	insertAtHead(head,40);

	display(head);

	cout<<length(head)<<endl;
	cout<<search(head,30)<<endl;
	cout<<search(head,3)<<endl;

	return 0;
}