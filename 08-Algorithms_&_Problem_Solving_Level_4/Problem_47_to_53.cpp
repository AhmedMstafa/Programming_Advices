#pragma warning(disable: 4996)
#include <iostream>
#include <ctime>
using namespace std;

struct stDate {
    short Year;
    short Month;
    short Day;
};


bool IsLeapYear(short Year) {
    return !(Year % 400) || ((Year % 100) && !(Year % 4));
}

short NumberOfDaysInMonth(short Year, short Month) {
    if (Month < 1 || Month > 12)
        return 0;

    int Days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : Days[Month - 1];

}


bool IsLastDayInMonth(short Year, short Month, short Day) {
    return (Day == NumberOfDaysInMonth(Year, Month));
}

bool IsLastMonthInYear(short Month) {
    return (Month == 12);
}

stDate IncreaseDateByOneDay(stDate Date) {

    if (IsLastDayInMonth(Date.Year, Date.Month, Date.Day)) {

        if (IsLastMonthInYear(Date.Month)) {
            Date.Year++;
            Date.Month = 1;
            Date.Day = 1;
        }
        else {
            Date.Month++;
            Date.Day = 1;
        }

    }
    else {
        Date.Day++;
    }

    return Date;
}

bool IsDateOneBeforeDateTwo(stDate Date1, stDate Date2) {
    return (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month) ? true : ((Date1.Month == Date2.Month) ? (Date1.Day < Date2.Day) : 0) : 0);
}


stDate DateNow() {
    stDate Date;
    time_t t = time(0);
    tm* now = localtime(&t);

    Date.Year = (now->tm_year + 1900);
    Date.Month = (now->tm_mon + 1);
    Date.Day = (now->tm_mday);

    return Date;
}


short DayOfWeekOrder(short Year, short Month, short Day) {
    short a = 0, y = 0, m = 0;

    a = (14 - Month) / 12;
    y = Year - a;
    m = Month + (12 * a) - 2;

    return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;

}

short DayOfWeekOrder(stDate Date) {
  return DayOfWeekOrder(Date.Year,Date.Month,Date.Day);
}

string DayShortName(short DayNumber) {
    string DaysOfWeek[7]{ "Sun","Mon","Tues","Wed","thurs","Fri","Sat" };
    return DaysOfWeek[DayNumber];
}

bool IsEndOfWeek(stDate Date) {
   return DayOfWeekOrder(Date) == 6;
}

bool IsWeekEnd(stDate Date) {
    short DayIndex = DayOfWeekOrder(Date);
    return (DayIndex == 5) || (DayIndex == 6);
}

bool IsBusinessDay(stDate Date) {
    short DayIndex = DayOfWeekOrder(Date);
    //return (DayIndex > 5 || DayIndex <= 4);
    return !IsWeekEnd(Date);
}

short DaysUntilTheEndOfWeek(stDate Date) {
    return 6 - DayOfWeekOrder(Date);
}

short GitDiffernceinDays(stDate Date1, stDate Date2, bool IncludeEndDay = false) {
    short Day = 0;
    while (IsDateOneBeforeDateTwo(Date1, Date2)) {
        Day++;
        Date1 = IncreaseDateByOneDay(Date1);
    }

    return (IncludeEndDay) ? Day++ : Day;
}

short DaysUntilTheEndOfMonth(stDate Date) {
    stDate EndOfMonthDate;
    EndOfMonthDate.Day = NumberOfDaysInMonth(Date.Year, Date.Month);
    EndOfMonthDate.Month = Date.Month;
    EndOfMonthDate.Year = Date.Year;

    return GitDiffernceinDays(Date, EndOfMonthDate, true);
}



short DaysUntilTheEndOfYear(stDate Date) {
    stDate EndOfMonthDate;
    EndOfMonthDate.Day = 31;
    EndOfMonthDate.Month = 12;
    EndOfMonthDate.Year = Date.Year;

    return GitDiffernceinDays(Date, EndOfMonthDate, true);
}


int main() {

    stDate Date = DateNow();
    cout << "\nToday is " << DayShortName(DayOfWeekOrder(Date));
    cout << " , " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    if (IsEndOfWeek(Date))
        cout << "Yes it is End Of Week\n";
    else
        cout << "No it is NOT End Of Week\n";

    if (IsWeekEnd(Date))
        cout << "Yes it is a Week End\n";
    else
        cout << "No it is NOT a Week End\n";

    if (IsBusinessDay(Date))
        cout << "Yes it is a BusinessDay\n";
    else
        cout << "No it is NOT BusinessDay\n";

    cout << "Days untill end of week : " << DaysUntilTheEndOfWeek(Date) << " Day(s).\n";
    cout << "Days untill end of Month : " << DaysUntilTheEndOfMonth(Date) << " Day(s).\n";
    cout << "Days untill end of Year : " << DaysUntilTheEndOfYear(Date) << " Day(s).\n";


}