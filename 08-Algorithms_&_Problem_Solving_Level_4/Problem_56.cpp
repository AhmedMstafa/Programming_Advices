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

short ReadVacationDays() {
    short VacationDay = 0;
    cout << "Please Enter Vacation Day? ";
    cin >> VacationDay;
    return VacationDay;
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


bool IsDateOneBeforeDateTwo(stDate Date1, stDate Date2) {
    return (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month) ? true : ((Date1.Month == Date2.Month) ? (Date1.Day < Date2.Day) : 0) : 0);
}

bool IsDateOneEqualDateTwo(stDate Date1, stDate Date2) {
    return (Date1.Day == Date2.Day)? ((Date1.Month == Date2.Month)? Date1.Year == Date2.Year : 0 ): 0;
}

bool IsDateOneAfterDateTwo(stDate Date1, stDate Date2) {
    return (!IsDateOneBeforeDateTwo(Date1, Date2)) && (!IsDateOneEqualDateTwo(Date1, Date2));
}



int main() {

    cout << "\nEnter Date1:\n";
    stDate Date1 = ReadDate();

    cout << "\nEnter Date2:\n";
    stDate Date2 = ReadDate();

    if (IsDateOneAfterDateTwo(Date1, Date2))
        cout << "\nYes, Date1 is After Date2." << endl;
    else
        cout << "\nNo, Date1 is NOT After Date2." << endl;

}