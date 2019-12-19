#include <iostream>

using namespace std;

void addOn(int &a){

	a = a +1;
	cout<<"Inside function "<<a<<endl;
}

int main(){

	int a = 10;
	addOn(a);

	// int &z = x;

	cout<<"Inside Main "<<a<<endl;

	return 0;
}