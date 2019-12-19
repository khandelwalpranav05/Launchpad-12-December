#include <iostream>

using namespace std;

int main(){

	// int arr[][2] = {
	// 	{1,2},
	// 	{3,4},
	// 	{5,6},
	// };

	// for(int i=0;i<3;i++){
	// 	for(int j=0;j<2;j++){
	// 		cout<<arr[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }

	// int brr[][4] = {{1,2},{9,8,7,6},{3,4},5,6};

	// for(int i=0;i<4;i++){
	// 	for(int j = 0;j<4;j++){
	// 		cout<<brr[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }

	// arr[1][2]

	int n,m;

	cin>>n>>m;

	int arr[n][m];

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>arr[i][j];
		}
	}

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}

	// int n;
	// cin>>n;

	// int arr[];

	
		

	return 0;
}