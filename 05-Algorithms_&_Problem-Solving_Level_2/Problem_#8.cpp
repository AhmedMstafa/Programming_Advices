#include <iostream>
using namespace std;




float ReadPosistiveNumber(string Message)
{
	float Number;
	do {
		cout << Message << endl;
		cin >> Number;

	} while (Number <= 0);
	return Number;
}

void PrintDigitsFrequency(int Frequency, int Number) {
	int Remainder = 0,FrequencyTimes = 0;
	string T = " Time.";
	while (Number > 0)
	{
		Remainder = Number % 10;
		Number = Number / 10;
		if (Frequency == Remainder)
			FrequencyTimes++;
	}
	if (FrequencyTimes > 1)
		T = " Times.";

	cout << "Digit " << Frequency << " Frequency is " << FrequencyTimes << T << endl;
}


int main()
{
	int Number = ReadPosistiveNumber("Enter a Positive Number? ");
	short DigitToCheck = ReadPosistiveNumber("Enter Frequency");
	PrintDigitsFrequency(DigitToCheck, Number);
}
