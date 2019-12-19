#include <iostream>

using namespace std;

int main(){

	// char arr[6] = {'a','b','c','d'};
	// arr[4] = 57;
	// cout<<arr<<endl;

	// char ch = 255 + 99;
	// cout<<ch<<endl;

	// char ch = 'u';
	// cout<<(&ch)<<endl;

	// char b = 't';
	// char* bptr = &b;
	// cout<<*bptr<<endl;

	// char arr[100];

	// cout<<"Enter name"<<endl;

	// cin>>arr;

	// cout<<arr<<endl;

	char para[1000];

	cin.getline(para,1000,'!');
	cout<<para<<endl;

	return 0;
}