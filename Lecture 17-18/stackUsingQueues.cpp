#include <iostream>
#include <stack>

using namespace std;

class Queue{

	stack<int> primary;
	stack<int> secondary;

public:
	void enqueue(int data){
		primary.push(data);
	}

	bool isEmpty(){
		return primary.empty();
	}

	void dequeue(){

		while(primary.size()!=1){
			secondary.push(primary.top());
			primary.pop();
		}

		primary.pop();

		while(!secondary.empty()){
			primary.push(secondary.top());
			secondary.pop();
		}
	}

	int getFront(){
		while(primary.size()!=1){
			secondary.push(primary.top());
			primary.pop();
		}

		int val = primary.top();

		while(!secondary.empty()){
			primary.push(secondary.top());
			secondary.pop();
		}

		return val;
	}

};

int main(){

	Queue q;

	q.enqueue(43);
	q.enqueue(13);
	q.enqueue(4);
	q.enqueue(9);

	cout<<q.getFront()<<endl;

	q.dequeue();
	q.dequeue();

	cout<<q.getFront()<<endl;

	cout<<q.isEmpty()<<endl;

	return 0;
}