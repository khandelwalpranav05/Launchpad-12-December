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

void insertAtIndex(node* &head,int data,int position){
	if(position<=1 or head==NULL){
		insertAtHead(head,data);
		return;
	}

	if(position>=length(head)){
		insertAtTail(head,data);
		return;
	}

	node* temp = head;

	int steps = 1;

	while(steps<position-1){
		temp = temp->next;
		steps++;
	}

	node* n = new node(data);

	n->next = temp->next;
	temp->next = n;
}

void deleteAtHead(node* &head){

	node* toBeDeleted = head;

	head = head->next;
	delete toBeDeleted;
}

void deleteAtAnyIndex(node* &head,int position){
	if(position==1){
		deleteAtHead(head);
		return;
	}

	if(position==length(head)){
		deleteAtTail(head);
	}

	node* temp = head;
	int steps = 1;

	while(steps<position-1){
		temp = temp->next;
		steps++;
	}

	node* toBeDeleted = temp->next;
	temp->next = temp->next->next;
	delete toBeDeleted;
}

node* midPoint(node* head){
	node* slow = head;
	node* fast = head;

	while(fast->next!=NULL and fast->next->next!=NULL){
		slow = slow->next;
		fast = fast->next->next;
	}

	return slow;
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

	insertAtIndex(head,789,5);

	display(head);

	deleteAtAnyIndex(head,5);

	display(head);

	node* mid = midPoint(head);

	cout<<mid->data<<endl;

	cout<<length(head)<<endl;
	// cout<<search(head,30)<<endl;
	// cout<<search(head,3)<<endl;


	return 0;
}