#include <iostream>
using namespace std;

short ReadYear() {
    short Year = 0;
    cout << "Please Enter a Year? ";
    cin >> Year;
    return Year;
}


bool IsLeapYear(short Year) {
    if (Year % 400 == 0) {
        return true;
    }
    if (Year % 100 != 0 && Year % 4 == 0) {
        return true;
    }
    return false;
}

int main()
{
    short Year = ReadYear();

    if (IsLeapYear(Year))
        cout << "\nYes " << Year << " is Leap Year.\n";
    else
        cout << "\nNo " << Year << " is NOT Leap Year.\n";

    return 0;
}
