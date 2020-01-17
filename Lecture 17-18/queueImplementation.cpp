#include <iostream>

using namespace std;

class Queue{
	int *arr;
	int front;
	int rear;
	int currSize;
	int maxSize;

public:
	Queue(int defaultSize = 6){
		this->maxSize = defaultSize;
		this->arr = new int[this->maxSize];
		this->front = 0;
		this->rear = -1;
		this->currSize = 0;
	}

	bool empty(){
		return this->currSize == 0;
	}

	int size(){
		return this->currSize;
	}

	void push(int data){
		if(this->currSize==this->maxSize){
			cout<<"Queue is full"<<endl;
			return;
		}

		this->rear = (this->rear + 1)%this->maxSize;
		arr[this->rear] = data;
		this->currSize++;
	}

	void pop(){
		if(empty()){
			cout<<"Queue is empty"<<endl;
			return;
		}

		this->front = (this->front + 1)%this->maxSize;
		this->currSize--;
	}

	int getFront(){
		return this->arr[this->front];
	}
};

int main(){

	Queue q;

	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	q.push(5);

	cout<<q.getFront()<<endl;

	cout<<q.size()<<endl;


	q.pop();
	q.pop();
	q.pop();

	cout<<q.getFront()<<endl;

	q.pop();
	q.pop();
	q.pop();

	return 0;
}