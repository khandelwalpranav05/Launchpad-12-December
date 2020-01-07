#include <iostream>

using namespace std;

int findMedian(int arr[3][3],int row,int col){
    int minRange = INT_MAX;
    int maxRange = INT_MIN;

    for(int i=0;i<row;i++){
        minRange = min(minRange,arr[i][0]);
        maxRange = max(maxRange,arr[i][col-1]);
    }

    int ans = 0;

    int check = row*col/2 + 1;

    while(minRange<=maxRange){

        int mid = minRange + (maxRange - minRange)/2;

        int count = 0;

        for(int i=0;i<row;i++){
            count+= upper_bound(arr[i],arr[i]+col,mid) - arr[i];
        }

        if(count<check){
            minRange = mid + 1;
        }else{
            ans = mid;
            maxRange = mid-1;
        }
    }

    return ans;
}

int main(){

    int arr[3][3] = {{1, 3, 5},
                     {3, 6, 8},
                     {2, 6, 8}};

    cout<<findMedian(arr,3,3)<<endl;
}