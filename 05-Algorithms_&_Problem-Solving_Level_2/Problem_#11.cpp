#include <iostream>
using namespace std;

int ReadPositiveNumber(string Message) {
    int Number;
    do {
        cout << Message << endl;
        cin >> Number;
    } while (Number < 0);

    return Number;
}

int ReversedNumber(int Number)
{
    int Number2 = 0, Remainder = 0;
    while (Number > 0) {
        Remainder = Number % 10;
        Number = Number / 10;
        Number2 = Number2 * 10 + Remainder;
    }

    return Number2;
}




void PrintPalindromeNumber(int Number)
{
    if (Number == ReversedNumber(Number))
        cout << "Yes , it is a Palindrome Number.\n";
    else
        cout << "No , it is Not a Plandrome Number.\n";

}



int main()
{
    int Number = ReadPositiveNumber("Please Enter a Plandrome Number. ");
    PrintPalindromeNumber(Number);

    return 0;
}

