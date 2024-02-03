#include <iostream>
using namespace std;

int main()
{
	int arr[4] = { 10, 20, 30, 40 };
	int* ptr;
	ptr = arr;

	cout << "Addresses are: \n";

	for (short i = 0; i < 4; i++) {
		cout << ptr + i << endl;
	}

	cout << "\nValues are: \n";

	for (short i = 0; i < 4; i++) {
		cout << *(ptr + i) << endl;
	}
}
