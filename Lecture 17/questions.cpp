#include <iostream>
#include <stack>

using namespace std;

bool balancedParanthesis(string str){

	stack<char> s;

	for(int i=0;i<str.length();i++){

		char ch = str[i];

		if(ch=='('){
			s.push(ch);
		}else{

			if(s.empty()){
				return false;
			}else{
				s.pop();
			}

		}
	}

	return s.empty();
}

bool isDuplicate(string str){

	stack<char> s;

	for(int i=0;i<str.length();i++){

		char ch = str[i];

		if(ch!=')'){
			s.push(ch);
		}else{

			if(s.top()=='('){
				return true;
			}

			while(s.top()!='('){
				s.pop();
			}
			s.pop();

		}
	}

	return false;
}

void nextGreater(int arr[],int n){

	stack<int> s;

	for(int i=0;i<n;i++){

		while(!s.empty() and arr[i]>s.top()){
			int val = s.top();
			s.pop();

			cout<<val<<"->"<<arr[i]<<endl;
		}
		s.push(arr[i]);
	}

	while(!s.empty()){
		int val = s.top();
		s.pop();

		cout<<val<<"->"<<(-1)<<endl;
	}
}

void stockSpan(int arr[],int n){

	stack<int> s;

	for(int i=0;i<n;i++){

		while(!s.empty() and arr[i]>=arr[s.top()]){
			s.pop();
		}

		if(!s.empty()){
			int idx = s.top();

			int diff = i - idx;
			cout<<diff<<" ";
		}else{
			cout<<i+1<<" ";
		}

		s.push(i);
	}
	cout<<endl;
}

void nextSmaller(int arr[],int n){

	stack<int> s;

	for(int i=0;i<n;i++){

		while(!s.empty() and arr[i]<=arr[s.top()]){
			int idx = s.top();
			s.pop();

			cout<<arr[idx]<<"->"<<arr[i]<<endl;
		}
		s.push(i);
	}

	while(!s.empty()){
		int idx = s.top();
		s.pop();

		cout<<arr[idx]<<"->"<<(-1)<<endl;
	}
}

int histogramArea(int arr[],int n){

	stack<int> s;

	int maxArea = INT_MIN;

	int i = 0;

	while(i<n){

		if(s.empty() or arr[s.top()]<=arr[i]){
			s.push(i);	
			i++;
		}else{

			int extractedIdx = s.top();
			s.pop();

			int currArea = 0;

			if(s.empty()){
				currArea = arr[extractedIdx]*(i);
			}else{
				currArea = arr[extractedIdx]*(i - s.top() - 1);
			}

			maxArea = max(maxArea,currArea);
		}
	}

	while(!s.empty()){

		int extractedIdx = s.top();
		s.pop();

		int currArea = 0;

		if(s.empty()){
			currArea = arr[extractedIdx]*(i);
		}else{
			currArea = arr[extractedIdx]*(i - s.top() - 1);
		}

		maxArea = max(maxArea,currArea);
	}

	return maxArea;
}

int main(){

	// cout<<balancedParanthesis("(())))((")<<endl;
	// cout<<balancedParanthesis("(())")<<endl;
	// cout<<balancedParanthesis("(())(")<<endl;

	// cout<<isDuplicate("(((a+(b))+c+d))")<<endl;
	// cout<<isDuplicate("((a+b)+(c+d))")<<endl;
	// cout<<isDuplicate("(((a+(b)))+(c+d))")<<endl;

	// int arr[] = {2,3,1,5,10,6,12,4};
	// int n = 8;

	// nextGreater(arr,n);

	// int arr[] = {100,80,60,70,60,75,85};
	// int n = 7;

	// stockSpan(arr,n);

	// int arr[] = {2,3,1,5,6,2,10,4,12};
	// int n = 9;

	// nextSmaller(arr,n);

	int arr[] = {2,3,4,1,3};
	int n = 5;

	cout<<histogramArea(arr,n)<<endl;

	return 0;
}