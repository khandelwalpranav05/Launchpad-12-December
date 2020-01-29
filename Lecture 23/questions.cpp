#include <iostream>
#include <unordered_map>

using namespace std;

bool subarrayWithSumZero(int arr[],int n){

	unordered_map<int,char> h;

	int sum = 0;

	h[0] = 'A';

	for(int i=0;i<n;i++){
		sum+=arr[i];

		if(h.count(sum)){
			return true;
		}else{
			h[sum] = 'A';
		}
	}

	return false;
}

bool subarrayWithSumK(int arr[],int n,int k){

	unordered_map<int,char> h;

	int sum = 0;

	h[0] = 'A';

	for(int i=0;i<n;i++){
		sum+=arr[i];

		if(h.count(sum - k)){
			return true;
		}else{
			h[sum] = 'A';
		}
	}

	return false;
}

int longestSubarrayWithSumZero(int arr[],int n){

	unordered_map<int,int> h;

	int sum = 0;

	h[0] = -1;

	int maxLength = -1;

	for(int i=0;i<n;i++){
		sum+=arr[i];

		if(h.count(sum)){
			int currLength = i - h[sum];
			maxLength = max(maxLength,currLength);

		}else{
			h[sum] = i;
		}
	}

	return maxLength;
}

int main(){

	// int arr[] = {1,1,1,1,-4};
	// int n = 6;

	// cout<<subarrayWithSumZero(arr,n)<<endl;

	// int arr[] = {1,12,3,3,4,5,6};
	// int n = 7;
	// int k = 13;

	// cout<<subarrayWithSumK(arr,n,k)<<endl;

	int arr[] = {0,5,3,3,9,8};
	int n = 6;

	cout<<longestSubarrayWithSumZero(arr,n)<<endl;

	return 0;
}

// [4,0,-4,-2,2,5,2,0,-8,-8,-8,-8,-1,7,4,5,5,-4,6,6,-3]