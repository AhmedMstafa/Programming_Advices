#include <iostream>
#include <string>
using namespace std;


//# Try
/*
float ReadPosistiveNumber(string Message)
{
	float Number;
	do {
		cout << Message << endl;
		cin >> Number;

	} while (Number <= 0);
	return Number;
}

void ReversedNumber(int Number) {
	string Reversed = to_string(Number);
	for (int i = Reversed.length(); i > 0; i--) {
		cout << Reversed[i - 1] << endl;
	}
}
*/

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
	while (Number > 0)
	{
		Remainder = Number % 10;
		Number = Number / 10;
		cout << Remainder << endl;
	}
}


int main()
{
//	ReversedNumber(ReadPosistiveNumber("Please Enter a Positive Number? "));

	PrintDigits(ReadPosistiveNumber("Please Enter Number Will Reversed! "));
}
