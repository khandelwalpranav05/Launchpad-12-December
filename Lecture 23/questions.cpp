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

}

int main(){

	int arr[] = {1,1,1,1,-4};
	int n = 6;

	cout<<subarrayWithSumZero(arr,n)<<endl;

	return 0;
}