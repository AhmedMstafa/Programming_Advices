#include <iostream>
#include <cstdlib>
using namespace std;

enum enCharType {SmallLetter = 1, CapitalLetter = 2, SpecialCaracter = 3, Digit = 4};

int Random(int From, int To) {
    int random = rand() % (To - From + 1) + From;
    return random;
}


char GetRandomCharacter(int Number)
{
    switch (enCharType(Number))
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


int main()
{

    srand((unsigned)time(NULL));
    cout << GetRandomCharacter(enCharType::SmallLetter) << endl;
    cout << GetRandomCharacter(enCharType::CapitalLetter) << endl;
    cout << GetRandomCharacter(enCharType::SpecialCaracter) << endl;
    cout << GetRandomCharacter(enCharType::Digit) << endl;

    return 0;

}

