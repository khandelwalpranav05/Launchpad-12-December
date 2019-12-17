#include <iostream>

using namespace std;

void bubbleSort(int arr[],int n){

	int counter = 1;

	while(counter<n){

		for(int i=0;i<n-counter;i++){
			if(arr[i]>arr[i+1]){
				swap(arr[i],arr[i+1]);
			}
		}

		// cout<<(n-counter)<<endl;

		// cout<<"**************"<<endl;

		// for(int i=0;i<n;i++){
		// 	cout<<arr[i]<<" ";
		// }
		// cout<<endl;
		// cout<<"**************"<<endl;

		counter++;
	}

}

int main(){

	int arr[] = {5,7,2,3,1};
	int n = 5;

	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;

	bubbleSort(arr,n);

	// for(int i=0;i<n;i++){
	// 	cout<<arr[i]<<" ";
	// }
	// cout<<endl;

	return 0;
}