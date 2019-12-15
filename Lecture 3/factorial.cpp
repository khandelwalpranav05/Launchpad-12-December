#include <iostream>

using namespace std;

int main(){

	int product = 1;

	int n;
	cout<<"Enter n"<<endl;
	cin>>n;

	for(int i=1;i<=n;i++){

		product = product*i;
	}	

	cout<<"Factorial is "<<product<<endl;

	return 0;
}