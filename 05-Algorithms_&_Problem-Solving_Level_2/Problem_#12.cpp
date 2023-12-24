#include <iostream>
using namespace std;

int ReadPositiveNumber(string Message)
{
    int Number = 0;

    do {
        cout << Message << endl;
        cin >> Number;
    } while (Number <= 0);
    return Number;
}



void invertedPattern(int Number)
{
    for (int i = Number; i >= 1; i--) {
        for (int j = i; j >= 1; j--) {
            cout << i;
        }
        cout << "\n";
    }
}


int main()
{
    invertedPattern(ReadPositiveNumber("Please Enter a Number ? "));

    return 0;
}
