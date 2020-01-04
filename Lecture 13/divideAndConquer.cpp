#include <iostream>
#include <vector>

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

	int start = 0;
	int end = n-1;

	int ans = -1;

	while(start<=end){
		int mid = (start + end)/2;

		if(arr[mid] == data){
			ans = mid;
			start = mid +1;
		}else if(arr[mid] > data){
			end = mid - 1;
		}else{
			start = mid + 1;
		}
	}

	return ans;
}

int searchInRotatedArray(int arr[],int start,int end,int data){
	if(start>end){
		return -1;
	}

	int mid = start + (end - start)/2;

	if(arr[mid]==data){
		return mid;
	}

	if(arr[mid]<=arr[end]){
		if(arr[mid] <= data and data <= arr[end]){
			return searchInRotatedArray(arr,mid+1,end,data);
		}else{
			return searchInRotatedArray(arr,start,mid-1,data);
		}
	}

	else{
		if(data>= arr[start] and data<=arr[mid]){
			return searchInRotatedArray(arr,start,mid-1,data);
		}else{
			return searchInRotatedArray(arr,mid+1,end,data);
		}
	}
}

bool isPossible(int arr[],int n,int k,int time){

	int painters = 1;
	int paintingTime = 0;

	for(int i=0;i<n;i++){

		paintingTime+=arr[i];

		if(paintingTime > time){
			painters++;
			paintingTime = arr[i];

			if(painters>k){
				return false;
			}
		}
	}

	return true;
}

int paintersProblem(int arr[],int k,int n){

	int minValue = arr[0];
	int maxValue = arr[0];

	for(int i=1;i<n;i++){
		maxValue+=arr[i];
		minValue = max(minValue,arr[i]);
	}

	int ans = maxValue;

	int start = minValue;
	int end = maxValue;

	while(start<=end){

		int mid = start + (end - start)/2;

		if(isPossible(arr,n,k,mid)){
			ans = mid;
			end = mid - 1;
		}else{
			start = mid + 1;
		}
	}

	return ans;
}

bool isHappening(vector<int> nums, int m,long maxSum){
        
    int splits = 1;
    long abhiTakKaSum = 0;
        
    for(int i=0;i<nums.size();i++){
        abhiTakKaSum+=nums[i];
            
        if(abhiTakKaSum > maxSum){
            splits++;
            abhiTakKaSum = nums[i];
                
            if(splits>m){
                return false;
            }
        }
    }
        
    return true;
}

int splitArray(vector<int>& nums, int m) {
        
    long total = nums[0];
    int maxValue = nums[0];
        
    for(int i=1;i<nums.size();i++){
        total +=nums[i];
        maxValue = max(nums[i],maxValue);
    }
        
    long minRange = maxValue;
    long maxRange = total;
        
    long ans = total;
        
    while(minRange<=maxRange){
            
        long mid = minRange + (maxRange - minRange)/2;
            
        if(isHappening(nums,m,mid)){
            ans = mid;
            maxRange = mid - 1;
        }else{
            minRange = mid + 1;
        }
    }
        
    return (int)ans;
}


int main(){

	// int arr[] = {1,2,3,4,5,6,7,8,9};
	// int n = 9;
	// int data = 8;

	// cout<<binarySearch(arr,n,data)<<endl;

	// int arr[] = {1,1,2,2,2,2,2,4,4};
	// int n = 9;
	// int data = 2;
	// cout<<upperBound(arr,n,data)<<endl;

	// int arr[] = {5,6,7,8,9,1,2,3};
	// int n = 8;
	// int data = 2;

	// cout<<searchInRotatedArray(arr,0,n-1,data)<<endl;

	// int arr[] = {10,20,30,40};
	// int n = 4;
	// int k = 2;

	// cout<<paintersProblem(arr,k,n)<<endl;

	return 0;
}