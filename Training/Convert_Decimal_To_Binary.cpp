#include <iostream>
#include <string>
using namespace std;

string DecimalToBinaray(int number)
{
    string binary = "";

    while (number > 0)
    {
        int remainder = (number % 2);
        binary = to_string(remainder) + binary;
        number = number / 2;
    }

    return binary;
}

int main()
{
    int number = 0;
    cout << "please enter a number\n";
    cin >> number;
    cout << "the number in binary is\n";
    cout << DecimalToBinaray(number);
    return 0;
}
