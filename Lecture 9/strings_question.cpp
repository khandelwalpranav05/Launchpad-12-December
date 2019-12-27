#include <iostream>

using namespace std;

bool isPalindrome(string str){
	int left = 0;
	int right = str.length() - 1;

	while(left<=right){
		if(str[left]!=str[right]){
			return false;
		}
		left++;
		right--;
	}

	return true;
}

void printSubstrings(string str){

	int n = str.length();

	for(int i=0;i<n;i++){

		for(int j= 1;j<=(n-i);j++){

			cout<<str.substr(i,j)<<endl;

		}

	}

}

int main(){

	cout<<isPalindrome("abbba")<<endl;
	cout<<isPalindrome("abha")<<endl;

	printSubstrings("abcd");

	return 0;
}