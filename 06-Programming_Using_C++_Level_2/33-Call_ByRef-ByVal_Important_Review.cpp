#include <iostream>
using namespace std;

void Function(int& x) {
	x++;
}

int main()
{
	int a = 10;

	Function(a);
	cout << "\nafter calling function = " << a << endl;
	cout << a << endl;
	cout << &a << endl;
	return 0;
}

