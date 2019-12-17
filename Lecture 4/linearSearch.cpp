#include <iostream>

using namespace std;

void search(int arr[],int n,int data){

	for(int i=0;i<n;i++){
		if(arr[i]==data){
			cout<<i<<endl;
			return;
		}
	}

	cout<<(-1)<<endl;
	return;
}

int main(){

	int n = 5;

	int arr[] = {5,7,4,9,1};

	int data = 9;

	// cout<<search(arr,n,data)<<endl;	
	search(arr,n,data);

	// cout<<(sizeof(arr)/sizeof(int))<<endl;

	// cout<<arr[3]<<endl;

	return 0;
}