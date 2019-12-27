#include <iostream>

using namespace std;

int lastIndex(int arr[],int n,int si,int data){
	if(si==n){
		return -1;
	}

	int indexFound = lastIndex(arr,n,si+1,data);

	if(indexFound==-1){
		if(arr[si]==data){
			return si;
		}else{
			return -1;
		}
	}
	else{
		return indexFound;
	}
}

int fib(int n){
	if(n==0 or n==1){
		return n;
	}


	int fibn1 = fib(n-1);
	int fibn2 = fib(n-2);

	int fibn = fibn1 + fibn2;
	return fibn;
}

int countBinaryString(int n){
	if(n==1 or n==2){
		return n+1;
	}

	int zero = countBinaryString(n-1);
	int one = countBinaryString(n-2);

	int total = one + zero;
	return total;
}

int pairingProblem(int n){
	if(n==1 or n==2){
		return n;
	}

	int single = pairingProblem(n-1);
	int pair = pairingProblem(n-2);

	int total = single + (n-1)*pair;
	return total;
}

int countBoardPath(int start,int end){
	//Base Case
	if(start==end){
		return 1;
	}

	if(start>end){
		return 0;
	}

	//Recursive Case
	int count = 0;

	for(int dice = 1;dice<=6;dice++){
		count+= countBoardPath(start+dice,end);
	}

	return count;
}

int countMazePath(int sr,int sc,int er,int ec){
	//Base Case
	if(sr==er and sc==ec){
		return 1;
	}

	if(sr>er or sc>ec){
		return 0;
	}

	//Recursive Case

	int horizontal = countMazePath(sr,sc+1,er,ec);
	int vertical = countMazePath(sr+1,sc,er,ec);

	int total = horizontal + vertical;
	return total;
}

string moveXToEnd(string str){
	if(str.length()==0){
		// return str;
		return "";
	}

	char ch = str[0];
	string ros = str.substr(1);

	string recursionResult = moveXToEnd(ros);

	string result;

	if(ch=='x'){
		result = recursionResult + ch;
	}else{
		result = ch + recursionResult;
	}

	return result;
}

int main(){

	// int arr[] = {2,3,4,5,4,3,2,3,4,54};
	// int n = 10;
	// int data = 2;

	// cout<<lastIndex(arr,n,0,data)<<endl;

	// cout<<fib(7)<<endl;

	// cout<<countBinaryString(5)<<endl;

	// cout<<countBoardPath(0,10)<<endl;

	// cout<<countMazePath(1,1,3,4)<<endl;

	cout<<moveXToEnd("abxpx")<<endl;
	cout<<moveXToEnd("xbhxxk")<<endl;

	return 0;
}