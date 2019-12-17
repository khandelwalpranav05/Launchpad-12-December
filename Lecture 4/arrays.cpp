#include <iostream>

using namespace std;

// void swap(int arr[],int i,int j){

// 	int ans = 1;

// 	int temp = arr[i];
// 	arr[i] = arr[j];
// 	arr[j] = temp;
// }

int main(){

	// int arr[5];

	// cout<<arr[4]<<endl;

	// int arr[5] = {1,2,3};

	// for(int i=0;i<5;i++){
	// 	cout<<arr[i]<<endl;
	// }

	// int arr[5];

	// cout<<sizeof(arr)<<endl;

	// int n;
	// cin>>n;
	// int arr[n];

	// // cin>>n;

	// for(int i=0;i<n;i++){
	// 	cin>>arr[i];
	// }

	// for(int i=0;i<n;i++){
	// 	cout<<arr[i]<<" ";
	// }
	// cout<<endl;

	// int arr[5] = {13};

	// for(int i=0;i<5;i++){
	// 	cout<<arr[i]<<" ";
	// }
	// cout<<endl;

	// int arr[4] = {};
	// for(int i=0;i<4;i++){
	// 	cout<<arr[i]<<" ";
	// }
	// cout<<endl;

	int arr[] = {1,2,3};

	for(int i=0;i<3;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;

	swap(arr[0],arr[2]);

	for(int i=0;i<3;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;

	return 0;
}