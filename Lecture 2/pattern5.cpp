#include <iostream>

using namespace std;

int main(){

	int n = 5;

	for(int row =1;row<=n;row++){

		for(int space = 1;space<=n-row;space++){
			cout<<" ";
		}

		for(int dec = row;dec>=1;dec--){
			cout<<dec;
		}

		for(int inc=2;inc<=row;inc++){
			cout<<inc;
		}

		cout<<endl;

	}	

	return 0;
}