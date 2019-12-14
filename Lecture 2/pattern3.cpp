#include <iostream> 

using namespace std;


// N = 5
// *
// * *
// * * *
// * * * *
// * * * * *

int main(){

	int n = 5;

	int row = 1;

	while(row<=n){

		int col = 1;

		while(col<=row){
			cout<<col<<" ";
			col = col + 1;
		}

		cout<<endl;

		// cout<<row<<endl;

		row = row+1;
	}


	return 0;
}