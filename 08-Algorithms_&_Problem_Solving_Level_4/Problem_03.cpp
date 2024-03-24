#include <iostream>
using namespace std;

short ReadYear() {
    short Year = 0;
    cout << "Please Enter a Year ";
    cin >> Year;
    return Year;
}

bool IsLeapYear(short Year) {
    return !(Year % 400) || ( (Year % 100) && !(Year % 4) );
}


int main()
{
    short Year = ReadYear();

    if (IsLeapYear(Year))
        cout << "\nYes " << Year << " is Leap Year \n";
    else
        cout << "\nNo " << Year << " is NOT Leap Year \n";
}
