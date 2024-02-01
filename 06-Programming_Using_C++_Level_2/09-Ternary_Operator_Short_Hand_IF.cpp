#include <iostream>
using namespace std;
void PrintIsPositiveNumber() {
	short Number = 0;
	cout << "Please Enter a Number? \n";
	cin >> Number;
	(Number < 0) ? cout << "Is Negative\n" : cout << "Is Positive \n";
}

void PrintIsPositiveNumberOrZero() {
	int Number = 0;
	cout << "Please Enter a Number? \n";
	cin >> Number;
	(Number < 0) ? cout << "Is Negative\n" :(Number == 0) ? cout<< "Number Is Zero\n": cout << "Is Positive \n";
}

int main()
{
	PrintIsPositiveNumber();
	PrintIsPositiveNumberOrZero();
	
}
