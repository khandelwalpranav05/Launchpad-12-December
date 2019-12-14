 #include <iostream>

using namespace std;

int main(){

	int a,b,c,d;

	cout<<"Input first number"<<endl;
	cin>>a;

	cout<<"Input second number"<<endl;
	cin>>b;

	cout<<"Input third number"<<endl;
	cin>>c;

	cout<<"Input fourth number"<<endl;
	cin>>d;


	float avg = ((float)(a+b+c+d))/4;

	cout<<"Average value is "<<avg<<endl;


	return 0;
}