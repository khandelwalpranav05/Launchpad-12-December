#include <iostream>

using namespace std;

int main(){

	// int n = 5;

	// int pos = 1;

	// int sum = 0;

	// while(pos<=n){

	// 	//Condition
	// 	if(pos%2==0){
	// 		sum = sum + pos;
	// 	}

	// 	cout<<pos<<endl;
	// 	pos = pos+1;
	// }

	// cout<<"Sum is "<<sum<<endl;

	int n = 6;

	int pos = 2;

	int sum = 0;

	while(pos<=n){

		sum = sum + pos;

		// cout<<(pos-1)<<endl;
		cout<<pos<<endl;
		pos = pos+2;
	}

	cout<<"Sum is "<<sum<<endl;

	return 0;
}