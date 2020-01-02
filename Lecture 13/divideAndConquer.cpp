#include <iostream>

using namespace std;

int binarySearch(int arr[],int n,int data){

	int start = 0;
	int end = n-1;

	while(start<=end){

		int mid = (start + end)/2;

		if(data==arr[mid]){
			return mid;
		}else if(arr[mid] > data){
			end = mid - 1;
		}else{
			start = mid + 1;
		}
	}

	return -1;
}

int upperBound(int arr[],int n,int data){



}

int main(){

	int arr[] = {1,2,3,4,5,6,7,8,9};
	int n = 9;
	int data = 8;

	// cout<<binarySearch(arr,n,data)<<endl;

	cout<<upperBound(arr,n,data)<<endl;

	return 0;
}