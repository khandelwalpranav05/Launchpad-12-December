#include <iostream>

using namespace std;

// Hi everyone !

int main(){

	cout<<"Variables are declared"<<endl;

	int location,p;
	
	// cout<<"Enter the starting point"<<endl;
	// cin>>p;

	// cout<<"Enter the location"<<endl;
	// cin>>location;

	location = 7;
	p = 1;

	while(p!=location){
		p = p + 1;
		cout<<"Value of p as if now "<<p<<endl;
	}

	cout<<"Value of p is "<<p<<endl;

	if(p==location){
		cout<<"Reached***********"<<endl;
	}

	cout<<"End"<<endl;

	// int var = 10;

	// cout<<"This is the value of var"<<var<<endl;

	// cout<<"Hello World!"<<endl;

	// cout<<var<<endl;

	return 0;
	// cout<<"Hello"<<endl;
}