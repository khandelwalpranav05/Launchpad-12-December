#include <iostream>
#include <unordered_map>
#include <vector>
#include <bits/stdc++.h>
#include <cstring>

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

int countBoardPathDP(int start,int end){
	int dp[end + 1];

	dp[end] = 1;

	for(int i=end - 1;i>=start;i--){
		dp[i] = 0;

		for(int dice = 1;dice<=6;dice++){
			if(i+dice<=end){
				dp[i] += dp[i + dice];
			}
		}

	}

	return dp[start];
}

int numSquaresMemo(int n,int dp[]){
    if(n==0){
        return 0;
    }
        
    if(dp[n]!=-1){
        return dp[n];
    }
        
    int minValue = INT_MAX;
        
    for(int i=1;i*i<=n;i++){
            
        int abhiTakKaAnswer = numSquaresMemo(n - i*i,dp) + 1;
        minValue = min(minValue,abhiTakKaAnswer);
    }
        
    dp[n] = minValue;

    for(int i = 0;i<=12;i++){
		cout<<dp[i]<<"\t";
	}
	cout<<endl<<"*******************"<<endl;
        
    return minValue;  
    
}

int numSquares(int n) {
    int dp[n+1];
    memset(dp,-1,sizeof(dp));
        
    return numSquaresMemo(n,dp);
}

int numSquaresDP(int n){
    int dp[n+1];
        
    dp[0] = 0;
    dp[1] = 1;
        
    for(int i=2;i<=n;i++){

        dp[i] = INT_MAX;

        for(int j=1;j*j<=i;j++){

            int abhiTakKaAnswer = dp[i - j*j] + 1;
            dp[i] = min(dp[i],abhiTakKaAnswer);
        }
    }
        
    return dp[n];
}

// int findTargetSumWays(vector<int>& nums, int S) {
        
        
//         // vector<vector<int> > dp(rows,vector<int> (col,-1)); 
        
//     unordered_map<string,int> dp;
        
//     return countTargetSum(nums,0,0,S,dp);
// }
    
// int countTargetSum(vector<int> nums,int si,int sum,int S,unordered_map<string,int> &dp){
//     if(si==nums.size()){
//         if(sum==S){
//             return 1;
//         }else{
//             return 0;
//         }
//     }
        
//     string key = to_string(si) + "->" + to_string(sum);
        
//     if(dp.count(key)){
//         return dp[key];
//     }
        
        
//     int positive = countTargetSum(nums,si+1,sum + nums[si],S,dp); 
//     int negative = countTargetSum(nums,si+1,sum - nums[si],S,dp);
        
//     int total = positive + negative;
        
//     dp[key] = total;
        
//     return total;
// }

// int lengthOfLIS(vector<int>& nums) {
	
// 	vector<int> dp(nums.size(),1);

// 	for(i = 1;i < nums.size();i++){
// 		for(int j=0;j < i;j++){

// 			if(nums[i]>nums[j]){
// 				dp[i] = max(dp[i],dp[j] + 1);
// 			}
// 		}
// 	}

// 	int maxLength = 1;
// 	for(int var:dp){
// 		maxLength = max(var,maxLength);
// 	}

// 	return maxLength;
// }

    
// int countBST(int n,int dp[]){
//     if(n==0 or n==1){
//         return 1;
//     }
        
//     if(dp[n]!=-1){
//         return dp[n];
//     }
        
//     int ans = 0;
        
//     for(int i=1;i<=n;i++){
//         ans+=countBST(i-1,dp)*countBST(n-i,dp);
//     }
        
//     dp[n] = ans;
        
//     return ans;
// }

// int numTreesMemo(int n) {
//     int dp[n+1];
//     memset(dp,-1,sizeof(dp));
//     return countBST(n,dp);
// }

// int numTrees(int n) {
//     int dp[n+1];
        
//     dp[0] = 1;
//     dp[1] = 1;
        
//     for(int x=2;x<=n;x++){
//         dp[x] = 0;
//         for(int i=1;i<=x;i++){
//             dp[x] += dp[i-1]*dp[x-i];
//         }
//     }
        
//     return dp[n];
// }

int longestCommonSubsequence(string s1,string s2){
	// if(s1.length()==0 or s2.length()==0){
	// 	return 0;
	// }
	if(s1.length()==0){
		return 0;
	}

	if(s2.length()==0){
		return 0;
	}

	char ch1 = s1[0];
	string ros1 = s1.substr(1);

	char ch2 = s2[0];
	string ros2 = s2.substr(1);

	int result;

	if(ch1==ch2){

		result = 1 + longestCommonSubsequence(ros1,ros2);

	}else{

		int firstShift = longestCommonSubsequence(ros1,s2);
		int secondShift = longestCommonSubsequence(s1,ros2);

		result = max(firstShift,secondShift);
	}

	return result;
}
const int MAX = 100;

int dp[MAX][MAX];

int lcsMemo(string s1,string s2){
	if(s1.length()==0 or s2.length()==0){
		dp[s1.length()][s2.length()] = 0;
		return 0;
	}

	if(dp[s1.length()][s2.length()]!=-1){
		return dp[s1.length()][s2.length()];
	}

	char ch1 = s1[0];
	char ch2 = s2[0];

	string ros1 = s1.substr(1); 
	string ros2 = s2.substr(1);

	int result;

	if(ch1==ch2){

		result  = 1 + lcsMemo(ros1,ros2);

	}else{

		int firstChoice = lcsMemo(s1,ros2);
		int secondChoice = lcsMemo(ros1,s2);

		result =  max(firstChoice,secondChoice);
	}

	dp[s1.length()][s2.length()] = result;

	for(int i=0;i<=5;i++){
		for(int j=0;j<=5;j++){
			cout<<dp[i][j]<<"\t";
		}
		cout<<endl;
	}
	cout<<"*********************"<<endl;

	return result;
}

int lcsPureDP(string s1,string s2){
	int lcsDP[s1.length()+1][s2.length()+1];

	for(int i=0;i<=s1.length();i++){
		lcsDP[i][0] = 0;
	}

	for(int i=0;i<=s2.length();i++){
		lcsDP[0][i] = 0;
	}

	for(int i = 1;i<=s1.length();i++){
		for(int j=1;j<=s2.length();j++){

			int idx1 = s1.length() - i; 
			int idx2 = s2.length() - j;

			char ch1 = s1[idx1];
			char ch2 = s2[idx2];

			if(ch1==ch2){
				lcsDP[i][j] = 1 + lcsDP[i-1][j-1];
			}else{
				lcsDP[i][j] = max(lcsDP[i-1][j],lcsDP[i][j-1]);
			}

		}
	}

	return lcsDP[s1.length()][s2.length()];
}

int houseRobbers(vector<int> &nums,int si,int dp[]){
    if(si>=nums.size()){
        return 0;
    }
        
    if(dp[si]!=-1){
        return dp[si];
    }
        
    int include = nums[si] + houseRobbers(nums,si+2,dp);
    int skip = houseRobbers(nums,si+1,dp);
        
    int result = max(include,skip);
        
    dp[si] = result;

    for(int i=0;i<=nums.size();i++){
    	cout<<dp[i]<<"\t";
    }
    cout<<endl<<"**********************"<<endl;
        
    return result;
    
}

int rob(vector<int>& nums) {
    int dp[nums.size() + 1];
    memset(dp,-1,sizeof(dp));
    return houseRobbers(nums,0,dp);
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

	// int start = 0;
	// int end = 10;
	// int dp[end+1];
	// memset(dp,-1,sizeof(dp));
	// cout<<countBoardPathMemo(start,end,dp)<<endl;

	// cout<<countBoardPathDP(start,end)<<endl;

	// cout<<numSquares(12)<<endl;

	// vector<int> v({13,2,2,19});
	// cout<<rob(v)<<endl;

	// memset(dp,-1,sizeof(dp));
	// cout<<lcsMemo("apgeh","paefh")<<endl;

	cout<<lcsPureDP("apgeh","paefh")<<endl;

	return 0;
}

// unordered_map<string,int> h;

// string key = "2" + "->" + "0";

// h[key] = 1;

// int si = 2;
// int sum = 0;

// string k = to_string(2) + "->" + to_string(0);

// cout<<h.count(k)<<endl;