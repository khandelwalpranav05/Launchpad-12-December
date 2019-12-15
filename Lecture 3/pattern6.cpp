#include <iostream>

using namespace std;

int main(){

	int n = 5;

	int var = 1;

	int num = 1;

	for(int row =1;row<=n;row++){

		for(int col=1;col<=var;col++){

			cout<<num<<" ";
			num++;

			if(num>9){
				num=1;
			}

		}

		cout<<endl;

		var = var*2;

	}

	return 0;
}
