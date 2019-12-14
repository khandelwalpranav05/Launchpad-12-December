#include <iostream>

using namespace std;

int main(){

	int n = 5;

	for(int row=1;row<=n;row++){

		for(int space = 1;space<=n-row;space++){
			cout<<" ";
		}

		for(int stars = 1;stars<=2*row - 1;stars++){
			cout<<"*";
		}

		cout<<endl;

	}

	return 0;
}