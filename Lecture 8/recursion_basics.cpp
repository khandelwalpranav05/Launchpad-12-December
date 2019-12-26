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

int factorial(int n){
	if(n==1){
		return 1;
	}

	int factn1 = factorial(n-1);
	int factn = n*factn1;
	return factn;
}

void printDecreasing(int n){
	if(n==1){
		cout<<1<<endl;
		return;
	}

	cout<<n<<endl;

	printDecreasing(n-1);
}

int power(int n,int p){
	if(p==0){
		return 1;
	}

	// if(p==1){
	// 	return n;
	// }

	int powern1 = power(n,p-1);
	int powern = powern1*n;
	return powern;
}

int powerBetter(int n,int p){
	if(p==0){
		return 1;
	}

	int powernby2 = powerBetter(n,p/2);

	int powern=1;
	if(p&1){
		powern = powernby2*powernby2*n;
	}else{
		powern = powernby2*powernby2;
	}

	return powern;
}

int linearSearch(int arr[],int si,int n,int data){
	if(si==n){
		return -1;
	}

	if(arr[si]==data){
		return si;
	}else{
		return linearSearch(arr,si+1,n,data);
	}
}

int main(){

	// printIncreasing(5);

	// cout<<sumTillN(5)<<endl;
	// cout<<factorial(5)<<endl;

	// cout<<power(2,5)<<endl;

	// int arr[] = {2,3,4,6,1,2,3,4};
	// int n = 8;
	// int data = 6;

	// cout<<linearSearch(arr,0,n,data)<<endl;

	return 0;
}

// Beginner -> HackerRank
// Practice -> Code Forces
// Interview Specific -> Interview Bit and LeetCode