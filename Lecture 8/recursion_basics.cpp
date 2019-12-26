#include <iostream>

using namespace std;

void printIncreasing(int n){
	if(n==1){
		cout<<1<<endl;
		return;
	}

	printIncreasing(n-1);

	cout<<n<<endl;
}

int sumTillN(int n){
	if(n==0){
		return 0;
	}

	int sumn1 = sumTillN(n-1);
	int sumn = sumn1 + n;
	return sumn;
}

int main(){

	// printIncreasing(5);

	cout<<sumTillN(5)<<endl;

	return 0;
}