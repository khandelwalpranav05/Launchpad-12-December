#include <iostream>

using namespace std;

void insertionSort(int arr[],int n){

	int divider = 1;

	while(divider<n){
		for(int i=divider;i>0;i--){
			if(arr[i-1] > arr[i]){
				swap(arr[i],arr[i-1]);
			}else{
				break;
			}
		}

		divider++;

		cout<<"**************"<<endl;

		for(int i=0;i<n;i++){
			cout<<arr[i]<<" ";
		}
		cout<<endl;
		cout<<"**************"<<endl;
	}
}

int main(){

	int arr[] = {5,7,2,3,1};
	int n = 5;

	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;

	insertionSort(arr,n);

	// for(int i=0;i<n;i++){
	// 	cout<<arr[i]<<" ";
	// }
	// cout<<endl;	

	return 0;
}