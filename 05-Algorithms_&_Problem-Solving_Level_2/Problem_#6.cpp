#include <iostream>
using namespace std;


//# Selution 

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
	int Remainder = 0;
	int Sum = 0;
	while (Number > 0)
	{
		Remainder = Number % 10;
		Number /= 10;
		Sum += Remainder;
	}
	cout << Sum << endl;
}

int main()
{
	PrintDigits(ReadPosistiveNumber("Please Enter a Positive Number: "));
}
