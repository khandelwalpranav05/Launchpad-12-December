#include <iostream>

using namespace std;

int maxSubarray(int arr[],int n){
	int maxSum = arr[0];
	int curr = arr[0];

	for(int i=1;i<n;i++){

		curr = max(curr+arr[i],arr[i]);

		maxSum = max(maxSum,curr);
	}

	return maxSum;
}

int main(){

	int arr[] = {1,-3,2,1,-1};
	int n = 5;

	cout<<maxSubarray(arr,n)<<endl;

	return 0;
}