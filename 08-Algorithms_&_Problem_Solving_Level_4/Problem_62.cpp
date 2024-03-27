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


bool IsValidDate(stDate Date) {

    if (Date.Day < 1 && Date.Day > 31)
        return false;

    if (Date.Month < 1 || Date.Month > 12)
        return false;

    if (Date.Month == 2) {
        if (Date.Day > 29) {
            return false;
        }
        else {
            if (Date.Day > 28)
                return false;
        }
        
    }

    short DaysInMonth = NumberOfDaysInMonth(Date.Year, Date.Month);

    if (Date.Day > DaysInMonth)
        return false;

    return true;

}


int main() {

    stDate Date = ReadDate();

    if (IsValidDate(Date))
        cout << "\nYes, Date is a valid date." << endl;
    else
        cout << "\nNo, Date is NOT a valid date." << endl;


    return 0;
}