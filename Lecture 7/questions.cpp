#include <iostream>

using namespace std;

int countTargetSumPair(int arr[],int n,int sum){

	int count = 0;
	int left = 0;
	int right = n-1;

	while(left<right){

		if(arr[left] + arr[right]<sum){

			left++;

		}else if(arr[left] + arr[right] > sum){

			right--;

		}else{

			int start = left;
			int first = arr[left];

			while(left<right and arr[left]==first){
				left++;
			}

			int a = (left - start);

			int end = right;
			int second = arr[right];
			while(right>=left and arr[right]==second){
				right--;
			}

			int b = (end - right);

			if(first==second){
				int r = a+b;
				count+= r*(r-1)/2;
			}else{
				count+=a*b;
			}
		}
	}

	return count;
}

int sanketAndStrings(int arr[],int n,int k){

	int left = 0;
	int count[2] = {0};

	int ans = 0; 

	for(int i=0;i<n;i++){
		if(arr[i]==0){
			count[0]++;
		}else{
			count[1]++;
		}

		if(min(count[0],count[1]) <= k){
			ans++;
		}else{
			if(arr[left]==0){
				count[0]--;
			}else{
				count[1]--;
			}

			left++;
		}
	}

	return ans;
}

void printKSubarrayValue(int arr[],int n,int k){
	
	int sum = 0;

	for(int i=0;i<k;i++){
		sum+=arr[i];
	}

	cout<<sum<<" ";

	for(int i=k; i < n;i++){

		sum+=arr[i];
		sum=sum - arr[i - k]; 
		cout<<sum<<" ";
	}
	cout<<endl;
}

int buyingPlots(int arr[],int n,int k){

	int left = 0;
	int right = 0;

	int maxLength = 0;

	int sum = arr[left] + arr[right];

	while(right<n){

		if(sum>k){
			sum = sum - arr[left];
			left++;

		}else if(sum<k){
			right++;
			sum = sum + arr[right];
		}else{

			int diff = right - left + 1;

			if(diff > maxLength){
				maxLength = diff;
			}

			// TODO
			right++;
			sum = sum + arr[right];
		}

	} 

	return maxLength;
}

int main(){

	// int arr[] = {1,1,2,2,3,3,3,4};
	// int n = 8;
	// int sum = 5;

	// cout<<countTargetSumPair(arr,n,sum)<<endl;

	// int arr[] = {0,0,0,1,1,1,1,0,0,1};
	// int n = 10;
	// int k = 3;

	// cout<<sanketAndStrings(arr,n,k)<<endl;

	// int arr[] = {1,2,3,4,5,6};
	// int n = 6;
	// int k = 3;

	// printKSubarrayValue(arr,n,k);

	int arr[] = {1,1,1,1,4,4,6,2};
	int n = 7;
	int k = 8;

	cout<<buyingPlots(arr,n,k)<<endl;

	return 0;
}