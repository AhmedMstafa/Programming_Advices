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

int CountDigitsFrequency(int Frequency, int Number) {
	int Remainder = 0, FrequencyTimes = 0;
	while (Number > 0)
	{
		Remainder = Number % 10;
		Number = Number / 10;
		if (Frequency == Remainder)
			FrequencyTimes++;
	}
	 return FrequencyTimes;
}


void PrintAllDigitsFrequencey(int Number)
{
	cout << endl;
	for (int i = 0; i < 10; i++)
	{
		short DigitFrequency = 0;
		DigitFrequency = CountDigitsFrequency(i, Number);

		if (DigitFrequency > 0)
		{
			cout << "Digit " << i << " Frequency is " << DigitFrequency << " Times" << endl;
		}
	}
}



int main()
{
	int Number = ReadPosistiveNumber("Enter a Positive Number? ");
	PrintAllDigitsFrequencey(Number);
}
