#include <iostream>
#include <stack>

using namespace std;

int main(){

	stack<char> s;

	s.push('A');
	s.push('B');
	s.push('C');

	s.pop();

	s.push('C');
	s.push('Y');

	cout<<s.top()<<endl;

	s.push('Q');
	s.push('R');

	cout<<s.size()<<endl;

	cout<<s.top()<<endl;

	s.pop();
	s.pop();
	s.pop();
	s.pop();
	s.pop();
	s.pop();

	// s.pop();

	cout<<s.empty()<<endl;

	return 0;
}