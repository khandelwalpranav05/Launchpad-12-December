#include <iostream>

using namespace std;

int main(){

	int n = 5;

	for(int row=1;row<=n;row++){

		for(int space = 1;space<=row-1;space++){
			cout<<" ";
		}

		cout<<row;

		for(int space = (2*(n-row) - 1);space>=1;space--){
			cout<<" ";
		}

		if(row!=n){
			cout<<row;
		}

		cout<<endl;
	}

	for(int row=n-1;row>=1;row--){

		for(int space = 1;space<=row-1;space++){
			cout<<" ";
		}

		cout<<row;

		for(int space = (2*(n-row) - 1);space>=1;space--){
			cout<<" ";
		}

		if(row!=n){
			cout<<row;
		}

		cout<<endl;
	}


	return 0;
}