

#include <iostream>
using namespace std;

// Home Work

void PrintNumbersTo()
{
	int num;
	cout << "Enter Number : \n";
	cin >> num;
	for (int i = 1; i <= num; i++) {
		cout << i << endl;
	}
}

void PrintNumbersFrom()
{
	int num;
	cout << "Enter Number : \n";
	cin >> num;
	for (int i = num; i >= 1; i--) {
		cout << i << endl;
	}
}

void PrintOddNumbers() {
	int num;
	cout << "Enter Number : \n";
	cin >> num;
	for (int i = 1; i <= num; i++) {
		if (i % 2 == 0) {
			cout << i << endl;
		}
	}
}

void PrintEvenNumbers() {
	int num;
	cout << "Enter Number : \n";
	cin >> num;
	for (int i = 1; i <= num; i++) {
		if (i % 2 != 0) {
			cout << i << endl;
		}
	}
}

void FactorialOf() {
	int num;
	cout << "Enter Number :";
	cin >> num ;
	int fact  = num;
	for (int i = num - 1  ; i > 0 ; i--) {
		cout << i << endl;
		num *= i;
	};
	cout << num;
}


void PowerOf() {
	int num, m;
	cout << "Enter Number: ";
	cin >> num;
	cout << "Power of Number: ";
	cin >> m;
	int result = 1;
	for (int i = m; i > 0; i--) {
			result *= num;
	}
		cout << result;
}


enum Letters {FirstCharA = 65, LastCharA = Letters::FirstCharA + 26, FristChara = 97, LastChara = 97 + 26};


void PrintLitters()
{
	int CharType;
	cout << "(1) Samll \n(2) Capital ";
	cin >> CharType;
	if (CharType == 1) {
		for (int i = Letters::FristChara; i < Letters::LastChara; i++) {
			cout << char(i) << endl;
		}
	}
	else if (CharType == 2){
		for (int i = Letters::FirstCharA; i < Letters::LastCharA; i++) {
			cout << char(i) << endl;
		}
	}
	else {
		cout << "Wrong Litters Tray Agein!" << endl;
	}

	
}


int main()
{

	//PrintNumbersTo();
	//PrintNumbersFrom();
	//PrintOddNumbers();
	//PrintEvenNumbers();
	//FactorialOf();
	//PowerOf();
	PrintLitters();
}

