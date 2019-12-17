#include <iostream>
#include <climits>

using namespace std;

int main(){

	int arr[] = {1,2,3,4};
	int n = 4;

	int max = INT_MIN;

	for(int i = 0;i<n;i++){

		for(int j=i;j<n;j++){

			int sum = 0;

			for(int k =i;k<=j;k++){
				cout<<arr[k]<<" ";
				sum+=arr[k];
			}
			cout<<" Sum is "<<sum;
			cout<<endl;

			if(max<sum){
				max = sum;
			}

		}

	}

	cout<<"Max subarray value is "<<max<<endl;

	return 0;
}