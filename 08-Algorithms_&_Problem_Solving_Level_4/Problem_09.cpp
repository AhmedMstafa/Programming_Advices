
#include <iostream>
#include <iomanip>
using namespace std;

short ReadYear() {
    short Year;
    cout << "Please Enter a Year to Chick? ";
    cin >> Year;
    return Year;
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
    string DaysOfWeek[7]{ "Sun","Mon","Tues","Wed","thurs","Fri","Sat" };
    return DaysOfWeek[DayNumber];
}

string MonthsShortName(short MonthNumber) {
    string Months[12]{ "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul","Aug", "Sep", "Oct", "Nov", "Dec" };
    return Months[MonthNumber - 1];
}

void PrintMonthCalender(short Year, short Month) {
    short Courrent = DayOfWeekOrder(Year, Month, 1);
    short MonthDays = NumberOfDaysInMonth(Year, Month);





    printf("\n   ________________%s______________\n\n"
        , MonthsShortName(Month).c_str());

    printf("   Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

    int i = 0;
    for (; i < Courrent; i++) {
        printf("     ");
    }

    for (int j = 1; j <= MonthDays; j++) {
        printf("%5d", j);

        if (++i == 7) {
            i = 0;
            printf("\n");
        }

    }
    printf("\n   _________________________________\n");



}

void PrintYearCalneder(short Year) {
    printf("\n   _________________________________\n");
    printf("\n            Calender %d",Year);
    printf("\n   _________________________________\n");

    for (short i = 1; i <= 12; i++) {
        PrintMonthCalender(Year, i);
    }
}

int main() {
    short Year = ReadYear();

    PrintYearCalneder(Year);

    return 0;
}