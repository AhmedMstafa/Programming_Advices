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

short ReadDay() {
    short Day;
    cout << "Please Enter a Day to Chick? ";
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

short DayOfWeekOrder(short Year, short Month, short Day) {
    short a = 0, y = 0, m = 0;

    a = (14 - Month) / 12;
    y = Year - a;
    m = Month + (12 * a) - 2;

    return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;

}

string DayShortName(short DayNumber) {
    string DaysOfWeek[7] { "Sun","Mon","Tues","Wed","thurs","Fri","Sat" };
    return DaysOfWeek[DayNumber];
}

int main()
{
    short Year = ReadYear();
    short Month = ReadMonth();
    short Day = ReadDay();
    short DayOrder = DayOfWeekOrder(Year, Month, Day);


    cout << "\nDay        :" << Day << "/" << Month << "/" << Year << endl;
    cout << "Day Order  :" << DayOrder << endl;
    cout << "Day Nume   :" << DayShortName(DayOrder) << endl;

}
