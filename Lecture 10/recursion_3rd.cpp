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

void mappedString(string str,string ans){
	if(str.length()==0){
		cout<<ans<<endl;
		return;
	}


	char ch1 = str[0];
	string ros1 = str.substr(1);

	int ch1_int = ch1 - '0';

	ch1 = ch1 - '0' + 'A' - 1;

	mappedString(ros1,ans + ch1);	

	if(str.length()>1){

		char ch2 = str[1];

		int ch2_int = ch2 - '0';

		int second_number = ch1_int*10 + ch2_int;

		if(second_number <= 26){

			ch2 = second_number + 'A' - 1;

			string ros2 = str.substr(2);

			mappedString(ros2,ans + ch2);
		}
	}

}

string code[] = {" ",".","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"}; 


int main(){

	// cout<<replacePi("xxpiipxxipi")<<endl;
	// cout<<replacePi("pixxippixx")<<endl;

	// printSubsequence("abc","");

	// printPermuatations("abc","");

	// mappedString("1234","");

	// char ch = '7';


	// int ch_int = ch - '0';
	// cout<<ch_int<<endl;


	// char assignedAlphabet = ch - '0' + 'A' - 1;

	// cout<<assignedAlphabet<<endl;


	return 0;
}