#include <iostream>

using namespace std;

int main(){

	int n;
	cin>>n;

	int i = 1;

	while(i*i<=n){
		i++;
	}

	cout<<"Square root is "<<(i-1)<<endl;

	return 0;
}