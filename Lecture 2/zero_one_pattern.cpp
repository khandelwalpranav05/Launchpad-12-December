#include <iostream>

using namespace std;

int main(){

	int n = 5;

	for(int row=1;row<=n;row++){

		bool content;

		if(row%2){
			content = true; 
		}else{
			content = false;
		}

		for(int col = 1;col<=row;col++){

			cout<<content<<" ";

			content = !content;

			// if(content){
			// 	content = false;
			// }else{
			// 	content = true;
			// }

		}

		cout<<endl;

	}


	return 0;
}