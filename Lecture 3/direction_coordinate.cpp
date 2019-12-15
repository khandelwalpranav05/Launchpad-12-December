#include <iostream>

using namespace std;

int main(){

	int x=0,y = 0;

	char ch;

	cin>>ch;

	while(ch!='X'){

		if(ch=='N'){
			y++;
		}

		if(ch=='S'){
			y--;
		}

		if(ch=='W'){
			x--;
		}

		if(ch=='E'){
			x++;
		}

		cin>>ch;
	}

	cout<<"Final Location is ("<<x<<", "<<y<<")"<<endl;
	

	return 0;
}