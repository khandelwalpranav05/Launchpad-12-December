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

int main(){

	int arr[] = {1,1,2,2,3,3,3,4};
	int n = 8;
	int sum = 5;

	cout<<countTargetSumPair(arr,n,sum)<<endl;

	return 0;
}