#include <iostream>
using namespace std;

// #try


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

enum enPerfectNotPerfect {Perfect = 1, NotPerfect = 2};


enPerfectNotPerfect ChickIsPerfect(int Number) {
	int Sum = 0;

	for (int i = 1; i < Number; i++) {
		if(Number % i == 0)
			Sum += i;
	}
	if(Sum == Number)
		return enPerfectNotPerfect::Perfect;
	else
		return enPerfectNotPerfect::NotPerfect;
}

void PrintPerfectNumber(int Number)
{
	if(ChickIsPerfect(Number) == enPerfectNotPerfect::Perfect)
		cout << Number << " is berfect. \n";
	else
		cout << Number << " is Not berfect. \n";
}
*/

// #Selution

float ReadPosistiveNumber(string Message)
{
	float Number;
	do {
		cout << Message << endl;
		cin >> Number;

	} while (Number <= 0);
	return Number;
}

bool isPerfectNumber(int Number) {
	int Sum = 0;
	for (int i = 1; i < Number; i++)
	{
		if (Number % i == 0)
			Sum += i;
	}
	return (Sum == Number);
}

void PrintResult(int Number) {
	if(isPerfectNumber(Number))
		cout << Number << " is Perfect Number. \n";
	else
		cout << Number << " is Not Perfect Number. \n";
}

int main()
{
	//PrintPerfectNumber(ReadPosistiveNumber("Please Enter A Berfect Number ? "));
	PrintResult(ReadPosistiveNumber("Please Enter a Perfect Number: "));
}
 