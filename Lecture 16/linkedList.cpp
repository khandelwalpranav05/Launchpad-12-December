#include <iostream>

using namespace std;

class node{
public:
	int data;
	node* next;

	node(int newData){
		this->data = newData;
		this->next = NULL;
	}
};

void display(node*head){
	// node* temp = head;

	while(head!=NULL){
		cout<<head->data<<"->";
		head = head->next;
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


void insertAtHead(node* &head,int data){
	node* n = new node(data);
	n->next = head;
	head = n;
}

void insertAtTail(node* &head,int data){
	if(head==NULL){
		insertAtHead(head,data);
		return;
	}

	node* temp = head;

	while(temp->next!=NULL){
		temp = temp->next;
	}

	node* n = new node(data);
	temp->next = n;
}

void deleteAtTail(node*head){

	node* temp = head;

	while(temp->next->next!=NULL){
		temp = temp->next;
	}

	node* toBeDeleted = temp->next;
	temp->next = NULL;
	delete toBeDeleted;
}

void insertAtIndex(node* head,int data,int position){

}

void deleteAtIndex(node* head,int position){

}

node* midPoint(node* head){

}

int main(){

	node* head = NULL;

	insertAtHead(head,10);
	insertAtHead(head,20);
	insertAtHead(head,30);
	insertAtHead(head,40);

	display(head);

	insertAtTail(head,5);
	insertAtTail(head,15);
	insertAtTail(head,25);

	display(head);

	cout<<length(head)<<endl;
	// cout<<search(head,30)<<endl;
	// cout<<search(head,3)<<endl;

	return 0;
}