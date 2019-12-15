#include <iostream>
#include <climits>

using namespace std;

int main(){

	int max = INT_MAX;
	int min = INT_MIN;

	// max = max+1;

	// max = max+max;

	cout<<"Max is "<<max<<endl;
	cout<<"Min is "<<min<<endl;

	long val = (long)max + 2;
	cout<<"long is "<<val<<endl;

	cout<<sizeof(int)<<endl;
	cout<<sizeof(max)<<endl;

	cout<<sizeof(val)<<endl;

	cout<<sizeof(float)<<endl;
	cout<<sizeof(double)<<endl;

	// short a = 10;

	// cout<<sizeof(a)<<endl;

	long long t;
	cout<<sizeof(t)<<endl;

	cout<<"******************"<<endl;

	auto a = 10;
	auto p = 'a';
	auto x = true;

	cout<<sizeof(a)<<endl;
	cout<<sizeof(p)<<endl;
	cout<<sizeof(x)<<endl;
	// cout<<sizeof(auto)<<endl; //Error

	return 0;
}