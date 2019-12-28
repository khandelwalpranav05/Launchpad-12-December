#include <iostream>

using namespace std;

string replacePi(string str){
	if(str.length()==0){
		return str;
	}

	char ch = str[0];
	string ros = str.substr(1);

	string recursionResult = replacePi(ros);

	if(ch=='p' and recursionResult[0]=='i'){

		return "3.14" + recursionResult.substr(1);

	}else{
		return ch + recursionResult;
	}
}

void printSubsequence(string str,string ans){
	if(str.length()==0){
		cout<<ans<<endl;
		return;
	}

	char ch = str[0];
	string ros = str.substr(1);

	printSubsequence(ros,ans+ch);
	printSubsequence(ros,ans);
}

void printPermuatations(string str,string ans){
	if(str.length()==0){
		cout<<ans<<endl;
		return;
	}

	for(int i=0;i<str.length();i++){

		char ch = str[i];

		string ros = str.substr(0,i) + str.substr(i+1);

		printPermuatations(ros,ans+ch);
	}
}

void mappedString(string str){



}

int main(){

	// cout<<replacePi("xxpiipxxipi")<<endl;
	// cout<<replacePi("pixxippixx")<<endl;

	// printSubsequence("abc","");

	// printPermuatations("abc","");


	char ch = '7';


	int ch_int = ch - '0';
	cout<<ch_int<<endl;


	char assignedAlphabet = ch - '0' + 'A' - 1;

	cout<<assignedAlphabet<<endl;


	return 0;
}