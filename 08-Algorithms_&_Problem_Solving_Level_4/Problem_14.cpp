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

bool IsDateOneEqualsDateTwo(stDate Date1, stDate Date2) {
    return (Date1.Day == Date2.Day) ? (Date1.Month == Date2.Month) ? (Date1.Year == Date2.Year) : 0 : 0;
}


int main() {
    stDate Date1 = ReadDate();
    stDate Date2 = ReadDate();

    if (IsDateOneEqualsDateTwo(Date1, Date2))
        cout << "\nYes, Date1 is Equal Date2.\n" << endl;
    else
        cout << "\nNo, Date1 is Not Not Equal Date2.\n" << endl;


}