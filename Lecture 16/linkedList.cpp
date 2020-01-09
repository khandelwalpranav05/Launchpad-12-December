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

void reverseIterative(node* &head){

	node* prev = NULL;
	node* curr = head;

	while(curr!=NULL){
		node* n = curr->next;

		curr->next = prev;
		prev = curr;
		curr = n;
	}

	head = prev;	
}

node* reverseRecursive(node* head){
	if(head==NULL or head->next==NULL){
		return head;
	}

	node* newHead = reverseRecursive(head->next);

	node* curr = head;
	curr->next->next = curr;
	curr->next = NULL;
	return newHead;
}

node* merge(node* a,node* b){
	if(a==NULL){
		return b;
	}

	if(b==NULL){
		return a;
	}

	node* c;

	if(a->data <= b->data){
		c = a;
		c->next = merge(a->next,b);
	}else{
		c = b;
		c->next = merge(a,b->next);
	}

	return c;
}

node* mergeSort(node* head){
	if(head==NULL or head->next==NULL){
		return head;
	}

	node* a = head;

	node* mid = midPoint(head);

	node* b = mid->next;
	mid->next = NULL;

	a = mergeSort(a);
	b = mergeSort(b);

	node* c = merge(a,b);
	return c;
}

node* kReverse(node* head,int k){
	if(head==NULL or head->next==NULL){
		return head;
	}

	int count = 1;

	node* curr = head;
	node* prev = NULL;

	while(count<=k and curr!=NULL){
		node* n = curr->next;
		curr->next = prev;
		prev = curr;
		curr = n;
		count++;
	}

	head->next = kReverse(curr,k);

	return prev;
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

	head = kReverse(head,3);

	display(head);

	// head = mergeSort(head);

	// display(head);

	// deleteAtAnyIndex(head,5);

	// display(head);

	// reverseIterative(head);

	// display(head);

	// head = reverseRecursive(head);

	// display(head);

	// node* mid = midPoint(head);

	// cout<<mid->data<<endl;

	// cout<<length(head)<<endl;
	// cout<<search(head,30)<<endl;
	// cout<<search(head,3)<<endl;

	// node* head1 = NULL;
	// insertAtTail(head1,1);
	// insertAtTail(head1,2);
	// insertAtTail(head1,5);
	// insertAtTail(head1,7);
	// insertAtTail(head1,8);
	// insertAtTail(head1,10);

	// node* head2 = NULL;
	// insertAtTail(head2,3);
	// insertAtTail(head2,4);
	// insertAtTail(head2,6);

	// display(head1);
	// display(head2);
	
	// node* mergesList = merge(head1,head2);
	// display(mergesList);

	return 0;
}