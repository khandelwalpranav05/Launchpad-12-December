#include <iostream>
#include <list>

using namespace std;

class Queue{
	list<char> storage;

public:
	void push(char data){
		storage.push_back(data);
	}

	void pop(){
		storage.pop_front();
	}

	int size(){
		return storage.size();
	}

	bool empty(){
		return storage.size()==0;
	}

	char getFront(){
		return storage.front();
	}
};

int main(){

	Queue q;

	q.push('a');
	q.push('b');
	q.push('C');
	q.push('R');
	q.push('p');

	cout<<q.getFront()<<endl;

	cout<<q.size()<<endl;

	q.pop();
	q.pop();
	q.pop();

	cout<<q.getFront()<<endl;

	q.pop();
	q.pop();
	// q.pop();

	return 0;
}