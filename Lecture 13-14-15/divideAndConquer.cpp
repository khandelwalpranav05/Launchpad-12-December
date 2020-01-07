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

bool isPossibleCows(int arr[],int n,int cows,int minDist){

	int abhiTakKiCows = 1;
	int abhiTakKiPosition = arr[0];

	for(int i=1;i<n;i++){
		int dist = arr[i] - abhiTakKiPosition;

		if(dist>=minDist){

			abhiTakKiCows++;
			abhiTakKiPosition = arr[i];

			if(abhiTakKiCows==cows){
				return true;
			}
		}
	}

	return false;
}

int aggressiveCows(int arr[],int n,int cows){

	sort(arr,arr+n);

	int minRange = 0;
	int maxRange = arr[n-1] - arr[0];

	int ans = minRange;

	while(minRange<=maxRange){

		int mid = minRange + (maxRange-minRange)/2;

		if(isPossibleCows(arr,n,cows,mid)){
			ans = mid;
			minRange = mid + 1;
		}else{
			maxRange = mid - 1;
		}
	}

	return ans;
}

int uniqueElement(int arr[],int start,int end){
	if(start>end){
		return -1;
	}

	int mid = start + (end - start)/2;

	if(arr[mid-1]!=arr[mid] and arr[mid]!=arr[mid+1]){
		return arr[mid];

	}else if(arr[mid]==arr[mid+1]){
		int count = mid - start;

		if(count&1){
			return uniqueElement(arr,start,mid-1);
		}else{
			return uniqueElement(arr,mid+2,end);
		}
	}else{

		int count = mid - start + 1;

		if(count&1){
			return uniqueElement(arr,start,mid-2);
		}else{
			return uniqueElement(arr,mid+1,end);
		}
	}
}

void merge(int arr[],int start,int end){
	
	int n = end-start+1;
	int temp[n];

	int mid = start + (end - start)/2;

	int i = start;
	int j = mid+1;

	int k = 0;

	while(i<=mid and j<=end){

		if(arr[i]<=arr[j]){
			temp[k] = arr[i];
			i++;
			k++;
		}else{
			temp[k] = arr[j];
			k++;
			j++;
		}
	}

	while(i<=mid){
		temp[k] = arr[i];
		i++;
		k++;
	}

	while(j<=end){
		temp[k] = arr[j];
		j++;
		k++;
	}

	int pos = 0;
	for(int x=start;x<=end;x++){
		arr[x] = temp[pos];
		pos++;
	}
}

void mergeSort(int arr[],int start,int end){
	if(start==end){
		return;
	}

	int mid = start + (end - start)/2;

	mergeSort(arr,start,mid);
	mergeSort(arr,mid+1,end);

	merge(arr,start,end);	
}

void quickSort(int arr[],int low,int high){
	if(low>=high){
		return;
	}

	int mid = low + (high - low)/2;
	
	int left = low;
	int right = high;

	int pivot = arr[mid];

	while(left<=right){

		if(arr[left]<pivot){
			left++;
		}

		else if(arr[right]>pivot){
			right--;
		}

		else{
			swap(arr[left],arr[right]);
			left++;
			right--;
		}
	}
	quickSort(arr,low,right);
	quickSort(arr,left,high);
}

int inversionCountMerge(int arr[],int start,int end){

	int count = 0;

	int n = end-start+1;
	int temp[n];

	int mid = start + (end - start)/2;

	int i = start;
	int j = mid+1;

	int k = 0;

	while(i<=mid and j<=end){

		if(arr[i]<=arr[j]){
			temp[k] = arr[i];
			i++;
			k++;
		}else{
			temp[k] = arr[j];
			k++;
			j++;

			count += (mid - i)+1;
		}
	}

	while(i<=mid){
		temp[k] = arr[i];
		i++;
		k++;
	}

	while(j<=end){
		temp[k] = arr[j];
		j++;
		k++;
	}

	int pos = 0;
	for(int x=start;x<=end;x++){
		arr[x] = temp[pos];
		pos++;
	}

	return count;
}

int inversionCount(int arr[],int start,int end){
	if(start==end){
		return 0;
	}

	int count = 0;

	int mid = start + (end - start)/2;

	count+=inversionCount(arr,start,mid);
	count+=inversionCount(arr,mid+1,end);

	count+=inversionCountMerge(arr,start,end);
	return count;
}

bool canGive(long n,long m,long x,long y,long mid){
	return mid*x <= m + (n-mid)*y;
}

long winningCBscholarship(long n,long m,long x,long y){

	long minRange = 0;
	long maxRange = n;

	long ans = 0;

	while(minRange<=maxRange){

		long mid = minRange + (maxRange - minRange)/2;

		if(canGive(n,m,x,y,mid)){
			ans = mid;
			minRange = mid + 1;
		}else{
			maxRange = mid - 1;
		}
	}

	return ans;
}
    
int find(vector<int> nums,int low,int high){
    if(low==high){
        return low;
    }else{
            
        int mid = low + (high -low)/2;
            
        if(nums[mid] > nums[mid+1]){
            return find(nums,low,mid);
        }else{
            return find(nums,mid+1,high);
        }
    }
}

int findPeakElement(vector<int>& nums) {
    return find(nums,0,nums.size()-1);
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

	// int stalls[] = {1,2,9,8,4};
	// int n = 5;
	// int cows = 3;

	// cout<<aggressiveCows(stalls,n,cows)<<endl;

	// int arr[] = {1,1,2,2,3,3,4,5,5};
	// int n = 9;
	// cout<<uniqueElement(arr,0,n-1)<<endl;

	// int arr[] = {9,6,8,1};
	// int n = 4;

	// // mergeSort(arr,0,n-1);
	// // cout<<quickSort(arr,0,n-1)<<endl;

	// cout<<inversionCount(arr,0,n-1)<<endl;

	// for(int i=0;i<n;i++){
	// 	cout<<arr[i]<<" ";
	// }
	// cout<<endl;

	// long n = 5;
	// long m = 8;
	// long x = 3;
	// long y = 2;

	// cout<<winningCBscholarship(n,m,x,y)<<endl;

	// cout<<sizeof(long)<<endl;

	// long long a;
	// cout<<sizeof(a)<<endl;

	return 0;
}