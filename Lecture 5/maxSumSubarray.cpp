#include <iostream>
#include <climits>

using namespace std;

int main(){

	int arr[] = {1,2,3,4};
	int n = 4;

	int max = INT_MIN;

	for(int i = 0;i<n;i++){

		int sum = 0;

		for(int j=i;j<n;j++){
			sum+=arr[j];

			if(max<sum){
				max = sum;
			}
		}

	}

	cout<<"Max subarray value is "<<max<<endl;

	return 0;
}