
#include <iostream>
#include <iomanip>
using namespace std;

short ReadYear() {
    short Year;
    cout << "Please Enter a Year? ";
    cin >> Year;
    return Year;
}


short ReadMonth() {
    short Month;
    cout << "Please Enter a Month? ";
    cin >> Month;
    return Month;
}

short ReadDay() {
    short Day;
    cout << "Please Enter a Day? ";
    cin >> Day;
    return Day;
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





int NumberOfDaysFromTheBeginingOfTheYear(short Year, short Month, short Day) {
    int TotalDays = 0;

    for (short i = 1; i <= Month - 1; i++) {
        if (Month > i) {
            TotalDays += NumberOfDaysInMonth(Year,i);
        }
    }

    TotalDays += Day;

    return TotalDays;
}



int main() {
    short Day = ReadDay();
    short Month = ReadMonth();
    short Year = ReadYear();

    cout << "\nNumber of Days from the begining of the year is "
        << NumberOfDaysFromTheBeginingOfTheYear(Year, Month, Day) << endl;

    return 0;
}