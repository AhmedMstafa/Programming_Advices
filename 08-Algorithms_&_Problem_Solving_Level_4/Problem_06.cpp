#include <iostream>
using namespace std;

short ReadYear() {
    short Year;
    cout << "Please Enter a Year to Chick? ";
    cin >> Year;
    return Year;
}

short ReadMonth() {
    short Month;
    cout << "Please Enter a Month to Chick? ";
    cin >> Month;
    return Month;
}

bool IsLeapYear(short Year) {
    return !(Year % 400) || ((Year % 100) && !(Year % 4));
}

short NumberOfDaysInMonth(short Year, short Month) {
    if (Month < 1 || Month > 12)
        return 0;

    int Days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : Days[Month - 1];

}

int main()
{
    short Year = ReadYear();
    short Month = ReadMonth();
    cout << "\nNumber of Days      in Month [" << Month
        << "] is " << NumberOfDaysInMonth(Year, Month) << endl;

    return 0;
}
