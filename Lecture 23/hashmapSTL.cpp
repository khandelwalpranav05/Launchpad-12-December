#include <iostream>
#include <unordered_map>
#include <vector>
#include <list>

using namespace std;

// class Car{

// }

int main(){

	// Car c;

	unordered_map<string,int> h;

	pair<string,int> p("India",144);
	h.insert(p);

	cout<<p.first<<" ";
	cout<<p.second<<" ";
	cout<<endl;

	h.insert(make_pair("Sweden",2));

	h["China"] = 70;

	int arr[] = {1,2,3,4,5};

	for(int var:arr){
		cout<<var<<" ";
	}	
	cout<<endl;

	vector<int> nums({1,2,3,4});

	auto a = 10;

	cout<<sizeof(a)<<endl;

	auto ch = 'A';
	cout<<sizeof(ch)<<endl;

	for(auto var:nums){
		cout<<var<<" ";
	}
	cout<<endl;

	for(auto node:h){
		cout<<"Key->"<<node.first<<", "<<"Value->"<<node.second<<endl;
	}

	list<int> ll;

	ll.push_back(5);
	ll.push_back(6);
	ll.push_back(7);
	ll.push_back(8);

	for(auto var:ll){
		cout<<var<<" ";
	}
	cout<<endl;

	return 0;
}