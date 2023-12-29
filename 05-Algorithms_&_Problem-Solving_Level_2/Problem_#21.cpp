#include <iostream>
#include <string>
using namespace std;


enum enCharType { SmallLetter = 1, CapitalLetter = 2, SpecialCaracter = 3, Digit = 4 };

int Random(int From,int To)
{
	return rand() % (To - From + 1) + From;
}

int ReadPositiveNumber(string Message)
{
	int Number = 0;
	do
	{
		cout << Message << endl;
		cin >> Number;
	} while (Number <= 0);

	return Number;
}

char GetRandomCharacter(enCharType CharType)
{
    switch (enCharType(CharType))
    {
    case enCharType::SmallLetter:
        return char(Random(97, 122));
        break;
    case enCharType::CapitalLetter:
        return char(Random(65, 90));
        break;
    case enCharType::SpecialCaracter:
        return char(Random(33, 47));
        break;
    case enCharType::Digit:
        return char(Random(48, 57));
        break;
    }
}

string GenerateWord(enCharType CharType, short Length) {
    string Word = "";
    for (int i = 1; i <= Length; i++) {
        Word += GetRandomCharacter(CharType);
    }
    return Word;
}

string GenerateKey()
{
    string Key = "";
    Key = GenerateWord(enCharType::CapitalLetter, 4) + "-";
    Key += GenerateWord(enCharType::CapitalLetter, 4) + "-";
    Key += GenerateWord(enCharType::CapitalLetter, 4) + "-";
    Key += GenerateWord(enCharType::CapitalLetter, 4) ;


    return Key;
}


void GenerateKeys(short NumberOfKeys) {
    for (int i = 1; i <= NumberOfKeys; i++)
    {
        cout << "Key [" << i << "] " << GenerateKey() << endl;
   }
}


int main()
{
	srand((unsigned)time(NULL));
    GenerateKeys(ReadPositiveNumber("Please Enter Number Of Keys: "));


}


