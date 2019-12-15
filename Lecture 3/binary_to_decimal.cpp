#include <iostream>

using namespace std;

int main(){
	
	int n = 10101;

	int power = 1;

	int decimal = 0;

	while(n>0){

		int temp = n%10;

		decimal+=power*temp;

		power*=2;

		n = n/10;
	}

	cout<<"Deciaml value "<<decimal<<endl;

	return 0;
}