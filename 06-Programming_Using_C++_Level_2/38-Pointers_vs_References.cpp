#include <iostream>
using namespace std;
int main()
{
// can not change reference in run time !
	int a = 10;
	int &x = a;
	
	cout << &a << endl;
	cout << &x << endl;

	cout << a << endl;
	cout << x << endl;

	int* p = &a;

	cout << p << endl;
	cout << *p << endl;

	int b = 20;
	p = &b;


	cout << p << endl;
	cout << *p << endl;
}
