#include <iostream>
using namespace std;
int main()
{
	int x = 0, * p;

	//Wrong!
	//p is an address but x is not
	// p = x;

	// Correct!
	// p is an address and so is &x
	p = &x;


	//Wrong!
	//&x id an address
	//*p is the value stored in &x
	//*p = &x;

	//Correct!
	// *p is the value and so x
	*p = x;
	cout << x << endl;
	cout << &x << endl;
	cout << p << endl; // pointer => &x => x value
	cout << *p << endl;// pointer => pointer value = &x =>  x vlaue

	return 0;
}
