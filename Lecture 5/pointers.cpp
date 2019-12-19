#include <iostream>

using namespace std;

int main(){

	// int x = 10;
	// cout<<(&x)<<endl;

	// int *xptr = &x;

	// cout<<xptr<<endl;

	// cout<<(&xptr)<<endl;

	// cout<<(*xptr)<<endl;
	// cout<<x<<endl;
	// cout<<10<<endl;

	// cout<<"******Float******"<<endl;

	// float f = 10.78;
	// float* fptr = &f;

	// cout<<&f<<endl;
	// cout<<fptr<<endl;

	// cout<<(*fptr)<<endl;

	// char ch = 'A';
	// char* cptr;
	// cptr = &ch;

	// cout<<(void*)cptr<<endl;
	// cout<<&ch<<endl;

	// cout<<"********INT*******"<<endl;

	// int x = 10;
	// int* xptr = &x;

	// cout<<xptr<<endl;
	// cout<<(xptr+1)<<endl;

	// cout<<"********LONG*******"<<endl;

	// long l = 20;
	// long*lptr = &l;

	// cout<<lptr<<endl;
	// cout<<(lptr + 1)<<endl;

	int x = 10;
	int &z = x; // z is alloted same location as x

	z++;

	cout<<x<<endl;

	return 0;
}