#include <iostream>
#include <stack>

using namespace std;

bool balancedParanthesis(string str){

	stack<char> s;

	for(int i=0;i<str.length();i++){

		char ch = str[i];

		if(ch=='('){
			s.push(ch);
		}else{

			if(s.empty()){
				return false;
			}else{
				s.pop();
			}

		}
	}

	return s.empty();
}

int main(){

	cout<<balancedParanthesis("(())))((")<<endl;
	cout<<balancedParanthesis("(())")<<endl;
	cout<<balancedParanthesis("(())(")<<endl;

	return 0;
}