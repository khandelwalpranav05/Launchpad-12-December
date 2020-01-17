#include <iostream>

using namespace std;

template <typename T>
class Stack{

	T *arr;
	int top;
	int maxSize;

public:
	Stack(int default_size = 5){
		this->maxSize = default_size;
		this->arr = new T[this->maxSize];
		this->top = -1;
	}

	void push(T data){
		if(this->top == this->maxSize - 1){
			cout<<"Stack is full"<<endl;
			return;
		}

		this->top++;
		this->arr[top] = data;
	}

	int size(){
		return this->top + 1;
	}

	bool empty(){
		return this->size() == 0;
	}

	void pop(){
		if(this->empty()){
			cout<<"Stack is empty"<<endl;
			return;
		}

		this->top--;
	}

	T getTop(){
		if(this->empty()){
			cout<<"Stack is empty"<<endl;
			return -1;
		}

		return this->arr[this->top];
	}
};

int main(){


	// Stack<int> s;

	// s.push(3);
	// s.push(23);
	// s.push(34);
	// s.push(36);
	// s.pop();

	// cout<<s.getTop()<<endl;

	// s.push(45);
	// s.push(12);

	// cout<<s.size()<<endl;

	// // s.pop();

	// s.push(4);

	// cout<<s.getTop()<<endl;

	// s.pop();

	// cout<<s.empty()<<endl;

	Stack<char> s;

	s.push('A');
	s.push('B');
	s.push('C');

	s.pop();

	s.push('C');
	s.push('Y');

	cout<<s.getTop()<<endl;

	s.push('Q');
	s.push('R');

	cout<<s.getTop()<<endl;

	s.pop();
	s.pop();
	s.pop();
	s.pop();
	s.pop();
	s.pop();

	return 0;
}