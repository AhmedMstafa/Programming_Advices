#include <iostream>
using namespace std;

int ReadNumber() {
    int Number = 0;
    cout << "\nEnter a Number? ";
    cin >> Number;
    return Number;
}

string NumberToText(int Number) {
    if (Number == 0) {
        return "";
    }
    if (Number >= 1 && Number <= 10) {
        string Numbers[]{ "","one ", "two ", "three ", "four ", "five ", "six ", "seven ", "eight ", "nine ", "ten "  };
        return Numbers[Number];
    }
    if (Number >= 11 && Number <= 19) {
        string Numbers[]{ "","eleven ", "twelve ", "thirteen ", "fourteen ", "fifteen ", "sixteen ", "seventeen ", "eighteen " , "nineteen " };
        return Numbers[Number % 10];
    }
    if (Number >= 20 && Number <= 99) {
        string Numbers[]{ "","","twonty ", "thirty ", "fourty ", "fifty ", "sixty ", "seventy ", "eighty ", "ninety ",};
        return Numbers[Number / 10] + " " + NumberToText(Number % 10);
    }
    if (Number >= 100 && Number <= 199) {
        return  "one hundred " + NumberToText(Number % 100);
    }
    if (Number >= 200 && Number <= 999) {
        return NumberToText(Number / 100) + "handreds " + NumberToText(Number % 100);
    }
    if (Number >= 1000 && Number <= 1999) {
        return  "one thousand " + NumberToText(Number % 1000);

    }
    if (Number >= 2000 && Number <= 999999) {
        return NumberToText(Number / 1000) + "thousands " + NumberToText(Number % 1000);

    }
    if (Number >= 1000000 && Number <= 1999999) {
        return "one million " + NumberToText(Number % 1000000);
    }
    if (Number >= 2000000 && Number <= 999999999) {
        return NumberToText(Number / 1000000) + "millions " + NumberToText(Number % 1000000);
    }
    if (Number >= 1000000000 && Number <= 1999999999) {
        return  "one billion " + NumberToText(Number % 1000000000);
    }
    if (Number >= 2000000000 && Number <= 999999999999) {
        return NumberToText(Number / 1000000000) + "billions " + NumberToText(Number % 1000000000);
    }
    if (Number >= 100000000000000 && Number <= 1999999999999999) {
        return "one trillion " + NumberToText(Number % 1000000000000);
    }
    if (Number >= 2000000000000000 && Number <= 999999999999999999) {
        return NumberToText(Number / 1000000000000) + "trillions " + NumberToText(Number % 1000000000000);
    }
    return "..";
}

int main()
{
    int Number = ReadNumber();
    cout  << NumberToText(Number) << endl;
}

