#include <iostream>

using namespace std;

void change(int *arr,int n){
	// arr[n-1] = 8374;

	arr = arr+1;
	arr[0] = 48756;

	arr = arr+1;
	arr[0] = 987;

	arr = arr - 1;
	arr[0] = 2;

	arr[12] = 38976;
}

int main(){

	int arr[3] = {1,2,3};
	int n = 3;

	change(arr,n);

	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;


	// cout<<arr<<endl;
	// cout<<&arr[1]<<endl;


	// cout<<arr[n-1]<<endl;
	return 0;
}