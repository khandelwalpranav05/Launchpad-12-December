#include <iostream>

using namespace std;

int main(){

	int n = 17;

	int i = 2;

	bool check = true;

	while(i<n){

		if(n%i==0){
			check = false;
			cout<<"Not Prime"<<endl;
			break;
		}

		i = i + 1;
	}

	if(check){
		cout<<"Prime Number"<<endl;
	}


	return 0;
}