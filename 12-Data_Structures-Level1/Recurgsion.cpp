#include <iostream>
using namespace std;

void PrintNumbers(short N, short M)
{
	if (N <= M)
	{
		cout << N << endl;
		PrintNumbers(N + 1, M);
	}
	// Code After Recurgsion will be here
	// You Can Print Number Revesed
	cout << N << endl;
}

void PrintNumbersReversed(short N, short M)
{
	if (N >= M)
	{
		cout << N << endl;
		PrintNumbersReversed(N - 1, M);
	}
	// Code After Recurgison Will be here 
	// You Can Print Number Reversed
	cout << N << endl;
}

int MyNumber(short Base, short Power)
{
	//cout << Base << " * " << Power << " = " << Base * Power << endl;

	//if (Power == 0)
		//cout << "\nPower is : ";

	if (Power == 0) 
		return 1; // if we not add this line stack call will not ended! value of 1 * power is last fuction
	else
		return (Base * MyNumber(Base, Power - 1));
	// No Code After Return 
}

int main()
{
//	PrintNumbers(1, 5);
//	PrintNumbersReversed(5, 1);
	cout << MyNumber(2, 5) << endl;
	return 0;
}