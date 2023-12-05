

#include <iostream>
using namespace std;


void PrintNumbersTo() {
	int i = 1, N;
	cout << "Please Enter A Number: ";
	cin >> N;
	while (i <= N) {
		cout << i << endl;
		i++;
	}
}

void PrintNumbersFrom() {
	int i = 1, N;
	cout << "Please Enter A Number: ";
	cin >> N;
	while (i <= N) {
		cout << N << endl;
		N--;
	}
}

void PrintSumOddNumbersFrom() {
	int i = 1, N ,Sum = 0;
	cout << "Plese Enter A Number: ";
	cin >> N;
	while (i <= N) {
		if (i % 2 != 0) {
		Sum += i;
		}
		i++;
	}
	cout << Sum;
}

void PrintSumEvenNumbersFrom() {
	int i = 1, N, Sum = 0;
	cout << "Plese Enter A Number: ";
	cin >> N;
	while (i <= N) {
		if (i % 2 == 0) {
			Sum += i;
		}
		i++;
	}
	cout << Sum;
}

void PrintFactorialOfN() {
	int i = 1, N, Fact = 1;
	cout << "Enter A Number:";
	cin >> N;
	while (N < 0) {
		cout << "Plase Enter A Positive Number: ";
		cin >> N;
	}
	while (i <= N) {
		Fact *= N;
		N--;
	}
	cout << Fact;
}

void PrintPowerOfM() {
	int Number , p =1, M, i = 1;
	cout << "Enter Number: ";
	cin >> Number;
	cout << "Enter M: ";
	cin >> M;
	while (M == 0) {
		cout << Number << endl;
	}
	while (i <= M) {
		p = p * Number;
		i++;
	}
	cout << p;
}

void SumUntil() {
	int Num, Sum = 0;
	cout << "Enter A Number: ";
	cin >> Num;
	while (Num != -99) {
	cout << "Enter A Number: ";
	Sum += Num;
	cin >> Num;
	}
	cout << Sum << endl;
}

void PrintLitters() {
	int i = 65;
	while (i <= 90) {
		cout << char(i) << endl;
		i++;
	}
}

void ATMPIN3() {
	int PIN, Balance = 7500,  counter = 1;
	cout << "Enter PIN Code: ";
	cin >> PIN;
	while (PIN != 1234 && counter <= 2) {
		cout << "Wrong PIN Code Try Agein !\n";
		cout << "Enter PIN Code: ";
		cin >> PIN;
		counter++;
	}
	while (counter >= 2) {
	while (counter >= 2) {
		cout << "Card Is Locked!" << endl;
		return;
	}
	cout << "Your Balance is : " << Balance << endl;
}


int main()

{
	//PrintNumbersTo();
	//PrintNumbersFrom();
	//PrintSumOddNumbersFrom();
	//PrintSumEvenNumbersFrom();
	//PrintFactorialOfN();
	//PrintPowerOfM();
	//SumUntil();
	//PrintLitters();
	ATMPIN3();
}

