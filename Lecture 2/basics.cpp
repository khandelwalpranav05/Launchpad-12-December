#include <iostream>

using namespace std;

int main(){

	int n;

	cout<<"Enter n"<<endl;
	cin>>n;

	int pos = 1;

	int sum = 0;

	while(pos<=n){

		sum = sum + pos;

		cout<<pos<<endl;
		pos = pos+1;
	}

	cout<<"Sum is "<<sum<<endl;

	return 0;
}