#include <iostream>
using namespace std;

void Swap(short& a, short& b)
{
	/*
	 exclusive or swap
	*/
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
}

int main()
{
	short a = 10,b = 20;
	
	cout << "a and b before swap = " << a << " " << b << endl;

	Swap(a, b);

	cout << "a and b after swap = " << a << " " << b << endl;

	return 0;
}
