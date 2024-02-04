#include <iostream>
using namespace std;


int main()
{
	float* ptr;
	int Num;
	cout << "Please Enter Number of Elements? ";
	cin >> Num;

	ptr = new float[Num];
	cout << endl;

	for (short i = 0; i < Num; i++) {
		cout << "Please Enter a Number: ";
		cin >> *(ptr + i);
	}
	cout << endl;
	cout << "The Numbers in Array is : ";
	for (short i = 0; i < Num; i++) {
		cout << *(ptr + i) << " ";
	}
	cout << endl;
}
