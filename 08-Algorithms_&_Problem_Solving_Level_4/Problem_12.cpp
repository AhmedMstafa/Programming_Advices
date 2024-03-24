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

stDate ReadDate() {
    stDate Date;
    Date.Day = ReadDay();
    Date.Month = ReadMonth();
    Date.Year = ReadYear();
    return Date;
}

int ReadDaysToAdd() {
    int DaysToAdd;
    cout << "Please Enter Days To Add? ";
    cin >> DaysToAdd;
    return DaysToAdd;
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

int NumberOfDaysFromTheBeginingOfTheYear(short Year, short Month, short Day) {
    int TotalDays = 0;

    for (short i = 1; i <= Month - 1; i++) {
        if (Month > i) {
            TotalDays += NumberOfDaysInMonth(Year, i);
        }
    }

    TotalDays += Day;

    return TotalDays;
}

stDate AddDaysToDate(stDate Date, int Days) {


    int Remining = Days + NumberOfDaysFromTheBeginingOfTheYear(Date.Year,Date.Month,Date.Day);
    short MonthDays = 0;

    Date.Month = 1;

    while (1) {
        MonthDays = NumberOfDaysInMonth(Date.Year, Date.Month);
        if (Remining > MonthDays) {
            Remining -= MonthDays;
            Date.Month++;
            if (Date.Month > 12) {
                Date.Year++;
                Date.Month = 1;
                Date.Day = 1;
            }
        }
        else {
            Date.Day = Remining;
            break;
        }
    }


    return Date;
}



int main() {
 
    stDate Date = ReadDate();
    int DaysToAdd = ReadDaysToAdd();

    Date = AddDaysToDate(Date, DaysToAdd);

    cout << "\nDate after adding [" << DaysToAdd << "] Days is:"
        << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

}