#include <iostream>

using namespace std;

int main(){

	int arr[6][6] ={{ 1, 2, 3, 4, 5, 6},
					{ 7, 8, 9,10,11,12},
					{13,14,15,16,17,18},
					{19,20,21,22,23,24},
					{25,26,27,28,29,30},
					{31,32,33,34,35,36}};

		int minRow = 0;
		int minCol = 0;
		int maxRow = 5;
		int maxCol = 5;

		int numOfElements = (6*6);

		int count = 0;

		while(count<numOfElements){

			for(int i=minCol;i<=maxCol;i++){
				cout<<arr[minRow][i]<<" ";
				count++;
			}
			minRow++;

			for(int i=minRow;i<=maxRow;i++){
				cout<<arr[i][maxCol]<<" ";
				count++;
			}
			maxCol--;

			for(int i = maxCol;i>=minCol;i--){
				cout<<arr[maxRow][i]<<" ";
				count++;
			}
			maxRow--;

			for(int i = maxRow;i>=minRow;i--){
				cout<<arr[i][minCol]<<" ";
				count++;
			}
			minCol++;
		}
		cout<<endl;

	return 0;
}