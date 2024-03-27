#include <iostream>
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

stDate ReadDate() {
    stDate Date;
    Date.Day = ReadDay();
    Date.Month = ReadMonth();
    Date.Year = ReadYear();

    return Date;
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

short DayOfWeekOrder(short Year, short Month, short Day) {
    short a = 0, y = 0, m = 0;

    a = (14 - Month) / 12;
    y = Year - a;
    m = Month + (12 * a) - 2;

    return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;

}

short DayOfWeekOrder(stDate Date) {
    return DayOfWeekOrder(Date.Year, Date.Month, Date.Day);
}

string DayShortName(short DayNumber) {
    string DaysOfWeek[7]{ "Sun","Mon","Tues","Wed","thurs","Fri","Sat" };
    return DaysOfWeek[DayNumber];
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


short CalculateVactionDays(stDate DateFrom, stDate DateTo) {
    short Day = 0;
    while (IsDateOneBeforeDateTwo(DateFrom, DateTo)) {

        if (IsBusinessDay(DateFrom))
            Day++;
        
        DateFrom = IncreaseDateByOneDay(DateFrom);
    }

    return  Day;
}

int main() {

    stDate DateFrom;
    stDate DateTo;

    cout << "Vacation Starts:" << endl;
    DateFrom = ReadDate();
    cout << "Vacation Ends:" << endl;
    DateTo = ReadDate();

    cout << "\nVacation From: " << DayShortName(DayOfWeekOrder(DateFrom)) << " , " 
         << DateFrom.Day << "/" << DateFrom.Month << "/" << DateFrom.Year << endl;

    cout << "\nVacation From: " << DayShortName(DayOfWeekOrder(DateTo)) << " , "
         << DateTo.Day << "/" << DateTo.Month << "/" << DateTo.Year << endl;

    cout << "\nActucal Vacation Days is: " << CalculateVactionDays(DateFrom, DateTo) << endl;

}