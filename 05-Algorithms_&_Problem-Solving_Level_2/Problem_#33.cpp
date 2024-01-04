#include <iostream>
#include <cstdlib>
using namespace std;

enum enCharType { CapitalLitter = 1, SmallLitter = 2, Simple = 3, Digit = 4 };

int RaedPositiveNumber(string Message) {
	int Number = 0; 
	do
	{
		cout << Message << endl;
		cin >> Number; 
	}while(Number <= 0);
	return Number;
}

int Random(int From, int To) {
	return rand() % (To - From + 1) + From;
}

char CreateChar(enCharType CharType)
{
	switch (CharType)
	{
	case enCharType::CapitalLitter:
		return char(Random(65,90));
		break;
	case enCharType::SmallLitter:
		return char(Random(97, 122));
		break;
	case enCharType::Simple:
		return char(Random(33, 47));
		break;
	case enCharType::Digit:
		return char(Random(48, 57));
	}
}

string CreateWord()
{
	string Word = "";
	for (int i = 0; i <= 4; i++) {
		Word += CreateChar(enCharType::CapitalLitter);
	}
	return Word;
}

string CreateKey() {
	string Key = "";
	Key += CreateWord() + "-";
	Key += CreateWord() + "-";
	Key += CreateWord() + "-";
	Key += CreateWord() ;
	return Key;
}

void FillArrayWithKeys(string arr[100], int Length) {
	for (int i = 0; i < Length; i++) {
		arr[i] = CreateKey();
	}
}

void PrintStringArray(string arr[100], int Length) {
	cout << "\nArray Elemnets: \n\n";
	for (int i = 0; i < Length; i++) {
		cout << "Array[" << i << "] : " << arr[i] << "\n";
	}
}




int main()
{
	srand((unsigned)time(NULL));
	string Array[100];
	int Length = RaedPositiveNumber("Please Enter Number of Elements: ");
	FillArrayWithKeys(Array, Length);
	PrintStringArray(Array, Length);

}
