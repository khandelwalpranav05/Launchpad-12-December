#include <iostream>

using namespace std;

void selectionSort(int arr[],int n){

	int firstPosition = 0;	
	while(firstPosition<n-1){
		
		for(int i=firstPosition+1;i<n;i++){
			if(arr[firstPosition] > arr[i]){
				swap(arr[firstPosition],arr[i]);
			}
		}

		firstPosition++;

		// cout<<"**************"<<endl;

		// for(int i=0;i<n;i++){
		// 	cout<<arr[i]<<" ";
		// }
		// cout<<endl;
		// cout<<"**************"<<endl;
	}

}

int main(){

	int arr[] = {5,7,2,3,1};
	int n = 5;

	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;

	selectionSort(arr,n);

	// for(int i=0;i<n;i++){
	// 	cout<<arr[i]<<" ";
	// }
	// cout<<endl;

	return 0;
}