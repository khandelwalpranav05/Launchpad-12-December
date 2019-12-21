#include <iostream>

using namespace std;

int distinctRectange(int arr[],int n,int k){

	int left = 0;
	int right = n-1;

	int count = 0;

	while(left<=right){
			
		if(arr[left]*arr[right]<k){

			count = count + 2*(right - left) + 1;
			left++;

		}else{
			right--;
		}
	}

	return count;
}

int main(){

	int arr[] = {1,2,3,4,5};
	int n = 5;
	int k = 16;

	cout<<distinctRectange(arr,n,k)<<endl;

	return 0;
}