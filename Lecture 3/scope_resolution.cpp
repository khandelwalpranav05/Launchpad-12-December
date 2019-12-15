#include <iostream>

using namespace std;

int x = 1001;

int main(){
	int i = 0;

	int x = 10;

	for(int i=0;i<5;i++){

		int x = 89;
		cout<<x<<endl;
		cout<<"Value of global x is "<<::x<<endl;
		// cout<<"Nothing"<<endl;
	}

	int a = 67;

	for(int i=0;i<6;i++){
		cout<<"Second Loop"<<endl;
	}

	cout<<"Value of x is "<<x<<endl;
	cout<<"Value of global x is "<<::x<<endl;

	return 0;
}