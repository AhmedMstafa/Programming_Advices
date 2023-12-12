#include <iostream>
using namespace std;

// #26

/*
int ReadNumber() {
	int N = 0;
	cout << "Enter a Number: \n";
	cin >> N;
	return N;
}

void PrintRangeFrom1toN_UsingWhile(int N)
{
	int counter = 0;
	while (counter < N) {
		counter++;
		cout << counter << endl;
	}
}


void PirntRagngeFrom1toNUsingDoWhile(int N)
{
	int counter = 0;

	do
	{	
		counter++;
		cout << counter << endl;
	} while (counter < N);
}

void PrintRangeFrom1toN_UsingFor(int N)
{
	for (int i = 1; i <= N; i++) {
		cout << i << endl;
	}
}
*/


// #27

/*
int ReadNumber() {
	int N = 0;
	cout << "Enter a Number: \n";
	cin >> N;
	return N;
}

void PrintRangeFromNto_1_UsingWhile(int N)
{
	int counter = N + 1;
	while (1 < counter) {
		counter--;
		cout << counter << endl;

	}
}

void PrintRangeFromNto_1UsingDoWhile(int N)
{
	int counter = N + 1;

	do
	{
		counter--;
		cout << counter << endl;
	} while (counter > 1);
}

void PrintRangeFromNto1_UsingFor(int N)
{
	for (int i = N ; i >= 1; i--) {
		cout << i << endl;
	}
}
*/

// #28

/*

enum enOddOrEven { Odd = 1, Even = 2 };

int ReadNumber()
{
	int Num;
	cout << "Plase Enter a Number: \n";
	cin >> Num;
	return Num;
}

enOddOrEven CheckOddOrEven(int Number)
{
	if (Number % 2 == 0)
		return enOddOrEven::Even;
	else
		return enOddOrEven::Odd;
}

int SumOddNumbersFrom1toN_UsingWhile(int N)
{
	int Sum = 0;
	int counter = 0;
	while (counter < N)
	{
		counter++;
		if (CheckOddOrEven(counter) == enOddOrEven::Odd) {
			Sum += counter;
		}
	}

	return Sum;
}

int SumOddNumbersFrom1toN_UsingDoWhile(int N)
{
	int counter = 0;
	int Sum = 0;

	do
	{
		counter++;
		if (CheckOddOrEven(counter) == enOddOrEven::Odd)
			Sum += counter;
	} while (counter < N);

	return Sum;
}

int SumOddNumbersFrom1toN_UsingFor(int N)
{
	int Sum = 0;
	for (int i = 1; i <= N; i++) {
		if (CheckOddOrEven(i) == enOddOrEven::Odd)
			Sum += i;
	}

	return Sum;
}

*/

//#29

/*

int ReadNumber()
{
	int N;
	cout << "Please Enter a Number: \n";
	cin >> N;
	return N;
}

enum enOddOrEven { Odd = 1, Even = 2 };

enOddOrEven CheckEvenNumber(int Number) {
	if (Number % 2 == 0)
		return enOddOrEven::Even;
	else
		return enOddOrEven::Odd;
}

int SumEvenNumberFrom1toN_UsingWhile(int N)
{
	int counter = 0;
	int sum = 0;
	while (counter < N) {
		counter++;
		if (CheckEvenNumber(counter) == enOddOrEven::Even)
			sum += counter;
	}

	return sum;
}

int SumEvenNumberFrom1toN_UsingDoWhlie(int N)
{
	int counter = 0;
	int sum = 0;
	do
	{	
		counter++;
		if (CheckEvenNumber(counter) == enOddOrEven::Even)
			sum += counter;
	} while (counter < N);
	return sum;
}


int SumEvenNumberFrom1toN_UsingFor(int N)
{
	int sum = 0;
	for (int i = 1; i <= N; i++) {
		if (CheckEvenNumber(i) == enOddOrEven::Even)
			sum += i;
	}

	return sum;
}
*/


// #30

int ReadPisitiveNumber(string Massage)
{
	int N;
	do {
		cout << Massage << endl;
		cin >> N;
	} while (N < 0);

	return N;
}

int Factorial(int N)
{
	int F = 1;

	for (int i = N; i >= 1; i--)
	{
		F *= i;
	}
	return F;
};



int main()
{
//	int N = ReadNumber(); 
//	PrintRangeFrom1toN_UsingWhile(N);
//	PirntRagngeFrom1toNUsingDoWhile(N);
//	PrintRangeFrom1toN_UsingFor(N);

//	int N = ReadNumber();
//	PrintRangeFromNto_1_UsingWhile(N);
//	PrintRangeFromNto_1UsingDoWhile(N);
//	PrintRangeFromNto1_UsingFor(N);

//	int N = ReadNumber();
//	cout << SumOddNumbersFrom1toN_UsingWhile(N) << endl;
//	cout << SumOddNumbersFrom1toN_UsingDoWhile(N) << endl;
//	cout << SumOddNumbersFrom1toN_UsingFor(N) << endl;

//	int N = ReadNumber();
//	cout << SumEvenNumberFrom1toN_UsingWhile(N) << endl;
//	cout << SumEvenNumberFrom1toN_UsingDoWhlie(N) << endl;
//	cout << SumEvenNumberFrom1toN_UsingFor(N) << endl;


	cout << Factorial(ReadPisitiveNumber("Please Enter A Positive Number :")) << endl;

	return 0;

}
