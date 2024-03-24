#pragma warning(disable: 4996)
#include <iostream>
#include <ctime>
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


void SwapDates(stDate& Date1, stDate& Date2) {
    stDate TempDate;
    TempDate.Day = Date1.Day;
    TempDate.Month = Date1.Month;
    TempDate.Year = Date1.Year;

    Date1.Day = Date2.Day;
    Date1.Month = Date2.Month;
    Date1.Year = Date2.Year;

    Date2.Day = TempDate.Day;
    Date2.Month = TempDate.Month;
    Date2.Year = TempDate.Year;

}

int GetDifferenceInDays(stDate Date1, stDate Date2, bool IncludeEndDay = false) {
    int Days = 0;
    short SwapFlag = 1;
    if (!IsDateOneBeforeDateTwo(Date1, Date2)) {
        SwapFlag = -1;
        SwapDates(Date1, Date2);
    }
    while (IsDateOneBeforeDateTwo(Date1, Date2))
    {
        Days++;
        Date1 = IncreaseDateByOneDay(Date1);
    }
    return (IncludeEndDay) ? ++Days * SwapFlag : Days * SwapFlag;
}




int main() {
    
    stDate Date1 = ReadDate();
    stDate Date2 = ReadDate();

    cout << "\nDiffrence is: " << GetDifferenceInDays(Date1, Date2)
        << " Day(s)." << endl;

    cout << "\nDiffrence (InCluding End Day) is: " <<
        GetDifferenceInDays(Date1, Date2,true) << " Day(s)." << endl;


}