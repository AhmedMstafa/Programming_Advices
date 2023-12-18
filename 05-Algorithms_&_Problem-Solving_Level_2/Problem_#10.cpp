#include <iostream>
using namespace std;

//#Selution


float ReadPosistiveNumber(string Message)
{
	float Number;
	do {
		cout << Message << endl;
		cin >> Number;

	} while (Number <= 0);
	return Number;
}

void PrintDigits(int Number) {
	int Remainder = 0, Number2 = 0;

	while (Number > 0) {
		Remainder = Number % 10;
		Number /= 10;
		Number2 = Number2 * 10 +Remainder;
	}

	while (Number2 > 0)
	{
		cout << Number2 % 10 << endl;
		Number2 /= 10;
	}
	
}





int main()
{
	PrintDigits(ReadPosistiveNumber("Please Enter Positive Number: "));
}
