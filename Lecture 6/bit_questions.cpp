#include <iostream>

using namespace std;

int uniqueNumber(int arr[],int n){

	int number = arr[0];

	for(int i=1;i<n;i++){
		number^=arr[i];
	}

	return number;
}

int floor(int n){

	int countBits = 0;

	while(n!=0){
		int temp = n&1;

		countBits+=temp;

		n = n>>1;
	}

	return countBits;
}

void uniqueNumberPair(int arr[],int n){

	int XorPair = arr[0];

	for(int i=1;i<n;i++){
		XorPair ^= arr[i];
	}

	if(XorPair==0){
		return;
	}

	int element = XorPair;
	int position = 0;

	while(true){

		int temp = element&1;

		if(temp){
			break;
		}
		position++;
		element = element>>1;
	}

	int var = XorPair;

	for(int i=0;i<n;i++){
		int check =arr[i];

		check = check>>position;

		if(check&1){
			var = var^arr[i];
		}
	}

	int first = var;

	int second = XorPair^var;

	cout<<"First element is "<<first<<" and second element is "<<second<<endl;
}

int uniqueNumberTriplet(int arr[],int n){

	int bitAdder[32] = {0};

	for(int i=0;i<n;i++){

		int element = arr[i];

		for(int j=31;j>=0;j--){

			int temp =element&1;

			bitAdder[j]+=temp;

			element = element>>1;
		}

	}

	int product = 1;
	int decimal = 0;

	for(int i = 31;i>=0;i--){

		bitAdder[i] = bitAdder[i]%3;

		decimal = decimal + bitAdder[i]*product;
		product = product*2;
	}

	return decimal;
}

// int* func(){

// 	int brr[3] = {1,2,3};

// 	// return &brr[0]
// 	return brr;
// }


int main(){

	// int arr[] = {1,2,4,3,1,2,3};
	// int n = 7;

	// cout<<uniqueNumber(arr,n)<<endl;

	// cout<<floor(13)<<endl;

	// cout<<__builtin_popcount(13)<<endl; // count Set bits

	// int arr[] = {1,2,3,4,5,7,4,3,2,1};
	// int n = 10;

	// uniqueNumberPair(arr,n);

	// int arr[] = {1,2,3,4,3,2,1,1,2,3};
	// int n = 10;

	// cout<<uniqueNumberTriplet(arr,n)<<endl;

	// int* arr= func();

	// for(int i=0;i<3;i++){
	// 	cout<<arr[i]<<" ";
	// }
	// cout<<endl;

	return 0;
}