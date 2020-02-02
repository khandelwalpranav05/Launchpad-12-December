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
    
int distinctSubseq(string s,int si,string t,int ti,vector<vector<int> > &dp){
    if(ti==t.length()){
     dp[si][ti] = 1;
        return 1;
    }
        
    if(si==s.length()){
     dp[si][ti] = 0;
        return 0;
    }
        
    if(dp[si][ti]!=-1){
        return dp[si][ti];
    }
        
    int count = 0;
        
    if(s[si]==t[ti]){
        count+=distinctSubseq(s,si+1,t,ti+1,dp);   
    }
    count+=distinctSubseq(s,si+1,t,ti,dp);
        
    dp[si][ti] = count;

    for(int i=0;i<=s.length();i++){
    	for(int j=0;j<=t.length();j++){
    		cout<<dp[i][j]<<"\t";
    	}
    	cout<<endl;
    }
    cout<<"*********************"<<endl;
        
    return count;
}

int numDistinct(string s, string t) {
        
    int rows = s.length() + 1;
    int col = t.length() + 1;
    vector<vector<int> > dp(rows,vector<int> (col,-1)); 
        
    return distinctSubseq(s,0,t,0,dp);
}

int distinctSubseqDP(string s, string t) {
        
    int col = s.length() + 1;
    int rows = t.length() + 1;
    vector<vector<long> > dp(rows,vector<long> (col,0));
        
    for(int i=0;i<=t.length();i++){
        dp[i][s.length()] = 0;
    }
        
    for(int i=0;i<=s.length();i++){
        dp[t.length()][i] = 1;
    }
        
    for(int i=t.length()-1;i>=0;i--){
        for(int j=s.length()-1;j>=0;j--){
                
           if(s[j]==t[i]){
               dp[i][j] = dp[i][j+1] + dp[i+1][j+1];
           }else{
               dp[i][j] = dp[i][j+1];
           }
        }
    }
        
    return dp[0][0];
}

int longestPalindromeSubseqMemo(string str,int left,int right,vector< vector<int> > &dp){
    if(left>right){
        return 0;
    }
        
    if(left==right){
        return 1;
    }
        
    if(dp[left][right]!=-1){
        return dp[left][right];
    }
        
    char ch1 = str[left];
    char ch2 = str[right];
        
    int result;
        
    if(ch1==ch2){
            
        result = longestPalindromeSubseqMemo(str,left+1,right-1,dp) + 2;
            
    }else{
            
        int first = longestPalindromeSubseqMemo(str,left+1,right,dp);
        int second = longestPalindromeSubseqMemo(str,left,right-1,dp);
            
        result = max(first,second);
            
    }
        
    dp[left][right] = result;
        
    return result;
}

int longestPalindromeSubseqMemo(string s) {
        
    int row = s.length();
    int col = s.length();
        
    vector< vector<int> > dp(row,vector<int> (col,-1));
        
    return longestPalindromeSubseqMemo(s,0,s.length()-1,dp);
}

// Longest Palindromic Subsequence With Pure DP

int longestPalindromeSubseqDP(string s) {
        
    int n = s.length();
        
    int dp[n][n];
        
    memset(dp,0,sizeof(dp));
        
    for(int i=0;i<n;i++){
        dp[i][i] = 1;
    }
        
    for(int col=1;col<n;col++){
        for(int row=col-1;row>=0;row--){
                
            if(s[row]==s[col]){
                dp[row][col] = dp[row+1][col-1] + 2;
            }else{
                dp[row][col] = max(dp[row][col-1],dp[row+1][col]);
            }
        }
    }
        
    return dp[0][n-1];   
}

int countSubstrings(string s) {
        
    int count = 0;
        
    for(int i=0;i<s.length();i++){
            
        // ODD Length
        for(int j=0; i-j>=0 and i+j<s.length() ;j++){
                
            if(s[i-j]==s[i+j]){
                count++;
            }else{
                break;
            }
                
        }
            
        // EVEN Length
        for(int j=0; i-j>=0 and i+j+1<s.length() ;j++){
                
            if(s[i-j]==s[i+j+1]){
                count++;
            }else{
                break;
            }
        }
    }
        
    return count;
}

int knapSack(int value[],int weight[],int si,int capacity,int n){
	if(si==n){
		return 0;
	}

	int include = INT_MIN;
	int exclude = INT_MIN;

	if(capacity>=weight[si]){
		include = value[si] + knapSack(value,weight,si+1,capacity - weight[si],n);
	}

	exclude = knapSack(value,weight,si+1,capacity,n);

	int result = max(exclude,include);

	return result;
}

int knapSackDP[5][9];

int knapSackMemo(int value[],int weight[],int si,int capacity,int n){
	if(si==0){
		knapSackDP[si][capacity] = 0;
		return 0;
	}

	if(knapSackDP[si][capacity]!=-1){
		return knapSackDP[si][capacity];
	}

	int include = INT_MIN;
	int exclude = INT_MIN;

	if(weight[si-1]<=capacity){
		include = value[si - 1] + knapSackMemo(value,weight,si-1,capacity - weight[si-1],n);
	}

	exclude = knapSackMemo(value,weight,si-1,capacity,n);

	int result = max(include,exclude);

	knapSackDP[si][capacity] = result;

	for(int i=0;i<5;i++){
		for(int j=0;j<9;j++){
			cout<<knapSackDP[i][j]<<"\t";
		}
		cout<<endl;
	}
	cout<<"***************************************************"<<endl;

	return result;
}


// int knapSackMemo(int value[],int weight[],int si,int capacity,int n){
// 	if(si==n){
// 		knapSackDP[si][capacity] = 0;
// 		return 0;
// 	}

// 	if(knapSackDP[si][capacity]!=-1){
// 		return knapSackDP[si][capacity];
// 	}

// 	int include = INT_MIN;
// 	int exclude = INT_MIN;

// 	if(weight[si]<=capacity){
// 		include = value[si] + knapSackMemo(value,weight,si+1,capacity - weight[si],n);
// 	}

// 	exclude = knapSackMemo(value,weight,si+1,capacity,n);

// 	int result = max(include,exclude);

// 	knapSackDP[si][capacity] = result;

// 	for(int i=0;i<5;i++){
// 		for(int j=0;j<9;j++){
// 			cout<<knapSackDP[i][j]<<"\t";
// 		}
// 		cout<<endl;
// 	}
// 	cout<<"***************************************************"<<endl;

// 	return result;
// }

int knapSackPureDP(int value[],int weight[],int capacity,int n){

	int dp[n+1][capacity+1];

	// Base Case
	for(int i=0;i<=capacity;i++){
		dp[0][i] = 0;
	}

	for(int i=0;i<=n;i++){
		dp[i][0] = 0;
	}

	// Recursive Case

	for(int i=1;i<=n;i++){
		for(int j=1;j<=capacity;j++){

			if(j >= weight[i - 1]){
				dp[i][j] = max(dp[i-1][j],dp[i-1][j - weight[i-1]] + value[i-1]);
			}else{
				dp[i][j] = dp[i-1][j];
			}
		}
	}

	return dp[n][capacity];
}
    
    int coinChange2(vector<int>& coins,int si,int amount,vector< vector<int> > &dp){
        if(amount==0){
            return 1;
        }
        
        if(si==coins.size()){
            return 0;
        }
        
        if(dp[si][amount]!=-1){
            return dp[si][amount];
        }
        
        int count = 0;
        
        if(amount>=coins[si]){
            count+=coinChange2(coins,si,amount-coins[si],dp);
        }
        count+=coinChange2(coins,si+1,amount,dp);
        
        dp[si][amount] = count;

        for(int i=0;i<=3;i++){
        	for(int j=0;j<=5;j++){
        		cout<<dp[i][j]<<"\t";
        	}
        	cout<<endl;
        }
        cout<<"****************************"<<endl;

        
        return count;
    }

int change(int amount, vector<int>& coins) {
        if(amount==0){
            return 1;
        }
        
        if(coins.size()==0){
            return 0;
        }
        
        int rows = coins.size() + 1;
        int col = amount + 1;
        vector< vector<int> > dp(rows,vector<int> (col,-1));
        
        return coinChange2(coins,0,amount,dp);
    }

    int coinChange2PureDP(int amount, vector<int>& coins) {
        if(amount==0){
            return 1;
        }
        
        if(coins.size()==0){
            return 0;
        }
        
        int rows = coins.size() + 1;
        int col = amount + 1;
        vector< vector<int> > dp(rows,vector<int> (col,0));
        
        for(int i=0;i<=amount;i++){
            dp[coins.size()][i] = 0; 
        }
        
        for(int i=0;i<=coins.size();i++){
            dp[i][0] = 1;
        }
        
        for(int i=coins.size()-1;i>=0;i--){
            for(int j=1;j<=amount;j++){
                
                if(j>=coins[i]){
                    dp[i][j] = dp[i+1][j] + dp[i][j - coins[i]];
                }else{
                    dp[i][j] = dp[i+1][j];
                }
                
            }
        }
        
        return dp[0][amount];   
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

	// cout<<lcsPureDP("apgeh","paefh")<<endl;

	// cout<<numDistinct("bbagg","bag")<<endl;

	// int value[] = {50,40,70,40};
	// int weight[]= {5, 4, 6, 3};
	// int capacity = 8;

	// int n = 4;

	// memset(knapSackDP,-1,sizeof(knapSackDP));
	// cout<<knapSackMemo(value,weight,n,capacity,n)<<endl;

	// cout<<knapSackPureDP(value,weight,capacity,n)<<endl;


	vector<int> coins({1,2,5});
	int amount = 5;
	cout<<change(amount,coins)<<endl;
	return 0;
}

// unordered_map<string,int> h;

// string key = "2" + "->" + "0";

// h[key] = 1;

// int si = 2;
// int sum = 0;

// string k = to_string(2) + "->" + to_string(0);

// cout<<h.count(k)<<endl;