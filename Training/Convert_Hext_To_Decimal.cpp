#include <iostream>
#include <string>
using namespace std;

short DecimalNumber(char Hexadecimal)
{
    Hexadecimal = toupper(Hexadecimal);
  
    if (Hexadecimal == 'F')
        return 15;

    if (Hexadecimal == 'E')
        return 14;

    if (Hexadecimal == 'D')
        return 13;

    if (Hexadecimal == 'C')
        return 12;

    if (Hexadecimal == 'B')
        return 11;

    if (Hexadecimal == 'A')
        return 10;

    Hexadecimal = tolower(Hexadecimal);

    return int(Hexadecimal) - 48;
}

string ReadHexNumber()
{
    string Hex = "";
    cout << "Enter Hexadecimal Number: ";
    cin >> ws >> Hex;
    return Hex;
}

int ConvertHexadecimalToDecimal(string Hexadecimal)
{
    // First Number * 16^0 , Second Number * 16^1 etx..
    short p = 0;
    int Number = 0;

    for (short i = Hexadecimal.length() -1; i >= 0; i--)
    {
        Number += DecimalNumber(Hexadecimal[i]) * pow(16,p);
        p++;
    }

    return Number;
}

int main()
{

    int Number = ConvertHexadecimalToDecimal(ReadHexNumber());

    cout << Number << '\n';

    system("pause>0");
    return 0;
}
