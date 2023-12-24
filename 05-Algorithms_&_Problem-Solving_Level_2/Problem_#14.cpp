#include <iostream>
using namespace std;

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


void PrintInvertedLetterPattern(int Number)
{
    for (int i = Number + 65 ; i >= 65; i--) {
        for (int j = 1; j <= Number - (65 + Number - 1 - i); j++) {
            cout << char(i);
        }
        cout << "\n";
    }
}




int main()
{
    PrintInvertedLetterPattern(ReadPositiveNumber("Please Enetr a Number ? "));
    return 0; 
}
