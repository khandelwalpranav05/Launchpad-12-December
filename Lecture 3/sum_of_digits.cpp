#include <iostream>

using namespace std;

int main(){

	int n = 765;

	int sum = 0;

	while(n!=0){

		int temp = n%10;

		sum+=temp; // sum = sum + temp

		n/=10;

	}

	cout<<"Sum is "<<sum<<endl;

	return 0;
}