#include <iostream>

using namespace std;

int fib(int n){
	if(n==1 or n==0){
		return n;
	}

	int fibn1 = fib(n-1);
	int fibn2 = fib(n-2);

	int fibn = fibn1 + fibn2;
	return fibn;
}

int fibMemo(int n,int dp[]){
	if(n==1 or n==0){
		dp[n] = n;
		return n;
	}

	if(dp[n]!=-1){
		return dp[n];
	}

	int fibn1 = fibMemo(n-1,dp);
	int fibn2 = fibMemo(n-2,dp);

	int fibn = fibn1 + fibn2;

	dp[n] = fibn;

	for(int i = 0;i<=5;i++){
		cout<<dp[i]<<"\t";
	}
	cout<<endl<<"*******************"<<endl;

	return fibn;
}

int fibPureDP(int n){
	int dp[n+1];

	dp[0] = 0;
	dp[1] = 1;

	for(int i=2;i<=n;i++){
		dp[i] = dp[i-1] + dp[i-2];
	}

	return dp[n];
}

int check1 = 0;

int reduceToOne(int n){
	if(n==1){
		return 0;
	}

	int count1 = INT_MAX,count2 = INT_MAX,count3 = INT_MAX;

	if(n%3==0){
		count3 = reduceToOne(n/3) + 1;
	}

	if(n%2==0){
		count2 = reduceToOne(n/2) + 1;
	}

	count1 = reduceToOne(n-1) + 1;

	check1++;

	return min(count1,min(count2,count3));
}

int check2 = 0;

int reduceToOneMemo(int n,int dp[]){
	if(n==1){
		dp[n]= 0;
		return 0;
	}

	if(dp[n]!=-1){
		return dp[n];
	}

	int count1 = INT_MAX,count2 = INT_MAX,count3 = INT_MAX;

	if(n%3==0){
		count3 = reduceToOneMemo(n/3,dp) + 1;
	}

	if(n%2==0){
		count2 = reduceToOneMemo(n/2,dp) + 1;
	}

	count1 = reduceToOneMemo(n-1,dp) + 1;

	dp[n] = min(count1,min(count2,count3));

	check2++;

	// for(int i=1;i<=10;i++){
	// 	cout<<dp[i]<<"\t";
	// }
	// cout<<endl<<"***********************"<<endl;

	return dp[n];
}

int reduceToOnePureDP(int n){
	int dp[n+1];

	dp[0] = 0;
	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 1;

	for(int i=4;i<=n;i++){
		int count1 = INT_MAX,count2 = INT_MAX,count3 = INT_MAX;

		if(i%3==0){
			count3 = dp[i/3] + 1;
		}

		if(i%2==0){
			count2 = dp[i/2] + 1;
		}

		count1 = dp[i-1] + 1;

		dp[i] = min(count1,min(count2,count3));
	}

	return dp[n];
}

int countBoardPath(int start,int end){
	if(start==end){
		return 1;
	}

	if(start>end){
		return 0;
	}

	int count = 0;

	for(int dice = 1;dice<=6;dice++){
		count+=countBoardPath(start+dice,end);
	}

	return count;
}

int countBoardPathMemo(int start,int end,int dp[]){
	if(start==end){
		dp[start] = 1;
		return 1;
	}

	if(start>end){
		return 0;
	}

	if(dp[start]!=-1){
		return dp[start];
	}

	int count = 0;

	for(int dice = 1;dice<=6;dice++){
		count+=countBoardPathMemo(start+dice,end,dp);
	}

	dp[start] = count;

	for(int i=0;i<=end;i++){
		cout<<dp[i]<<"\t";
	}
	cout<<endl<<"**********************"<<endl;

	return count;
}

int main(){

	// int n = 5;

	// cout<<fib(5)<<endl;

	// int dp[n+1];
	// memset(dp,-1,sizeof(dp));
	// cout<<fibMemo(n,dp)<<endl;

	// int n = 10;

	// cout<<"Recursion"<<endl;
	// cout<<reduceToOne(n)<<endl;
	// cout<<check1<<endl;

	// cout<<"DP"<<endl;
	// int dp[n+1];
	// memset(dp,-1,sizeof(dp));
	// cout<<reduceToOneMemo(n,dp)<<endl;
	// cout<<check2<<endl;

	// cout<<reduceToOnePureDP(n)<<endl;

	int start = 0;
	int end = 10;
	int dp[end+1];
	memset(dp,-1,sizeof(dp));
	cout<<countBoardPathMemo(start,end,dp)<<endl;

	return 0;
}