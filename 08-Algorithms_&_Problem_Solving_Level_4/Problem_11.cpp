#include <iostream>
#include <iomanip>
using namespace std;

struct stDate {
    short Year;
    short Month;
    short Day;
};

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





short NumberOfDaysFromTheBeginingOfTheYear(short Year, short Month, short Day) {
    short TotalDays = 0;

    for (short i = 1; i <= Month - 1; i++) {
        if (Month > i) {
            TotalDays += NumberOfDaysInMonth(Year, i);
        }
    }

    TotalDays += Day;

    return TotalDays;
}


stDate ConvertDaysToDate(short Year, short Days) {
    stDate Date;

    Date.Year = Year;
    Date.Month = 1;

    short RemainingDays = Days;
    short MonthDays = 0;

    while (true) {
        MonthDays = NumberOfDaysInMonth(Year, Date.Month);
        if (RemainingDays > MonthDays) {
            RemainingDays -= MonthDays;
            Date.Month++;
        }
        else {
            Date.Day = RemainingDays;
            break;
        }
    }
    return Date;
}


int main() {
    short Day = ReadDay();
    short Month = ReadMonth();
    short Year = ReadYear();
    stDate Date;

    short TotalDays = NumberOfDaysFromTheBeginingOfTheYear(Year,Month,Day);

    Date = ConvertDaysToDate(Year, TotalDays);

    cout << "\nNumber of Days From The Begining Of The Year is " << TotalDays << endl;

    cout << "\nDate For [" << TotalDays << "] is: " <<
        Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

}