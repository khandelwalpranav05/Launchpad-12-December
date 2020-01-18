#include <iostream>
#include <stack>
#include <queue>
#include <deque>
#include<vector>

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

void firstNonRepeatingCharacter(){

	queue<char> q;
	int freq[256] = {0};

	char ch;
	cin>>ch;

	while(ch!='!'){

		q.push(ch);
		freq[ch]++;

		while(!q.empty()){
			char check = q.front();

			if(freq[check] > 1){
				q.pop();
			}else{
				cout<<check<<" ";
				break;
			}
		}

		if(q.empty()){
			cout<<(-1)<<" ";
		}

		cin>>ch;
	}

	cout<<endl;
}

void slidingWindow(int arr[],int n,int k){

	deque<int> q;

	int i = 0;

	while(i<k){
		while(!q.empty() and arr[q.back()] < arr[i]){
			q.pop_back();
		}
		q.push_back(i);
		i++;
	}

	for(;i<n;i++){
		cout<<arr[q.front()]<<" ";

		if(!q.empty() and q.front()<= i - k){
			q.pop_front();
		}

		while(!q.empty() and arr[q.back()] < arr[i]){
			q.pop_back();
		}
		q.push_back(i);
	}

	cout<<arr[q.front()]<<endl;
}

bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
     
        stack<int> s;
        int popIdx = 0;
        
        for(int i=0;i<pushed.size();i++){
            s.push(pushed[i]);
            
            while(!s.empty() and s.top()==popped[popIdx]){
                s.pop();
                popIdx++;
            }
        }
        
        return popIdx==popped.size(); 
}

int largestRectangularMatrixOf1s(int arr[4][4],int n,int m){

	int maxSize = INT_MIN;

	maxSize = max(maxSize,histogramArea(arr[0],m));

	for(int i=1;i<n;i++){

		for(int j=0;j<m;j++){

			if(arr[i][j] == 1){
				arr[i][j]+=arr[i-1][j];
			}else{
				arr[i][j] = 0;
			}

			//
		}

		maxSize = max(maxSize,histogramArea(arr[i],m));
	}

	return maxSize;
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

	// int arr[] = {2,3,4,1,3};
	// int n = 5;

	// cout<<histogramArea(arr,n)<<endl;

	// firstNonRepeatingCharacter();

	// int arr[] = {2,3,1,4,6,5,3,0,1};
	// int n = 9;
	// int k = 3;

	// slidingWindow(arr,n,k);

	// int arr[4][4] = { {0, 1, 1, 0}, 
 //                   {1, 1, 1, 1}, 
 //                   {1, 1, 1, 1}, 
 //                   {1, 1, 0, 0}, 
 //                 };

 //    cout<<largestRectangularMatrixOf1s(arr,4,4)<<endl;

	return 0;
}