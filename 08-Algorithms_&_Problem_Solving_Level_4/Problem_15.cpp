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



bool IsLeapYear(short Year) {
    return !(Year % 400) || ((Year % 100) && !(Year % 4));
}

short NumberOfDaysInMonth(short Year, short Month) {
    if (Month < 1 || Month > 12)
        return 0;

    int Days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : Days[Month - 1];

}


bool IsLastDayInMonth(short Year,short Month, short Day) {
    return (Day == NumberOfDaysInMonth(Year, Month));
}

bool IsLastMonthInYear(short Month) {
    return (Month == 12);
}


int main() {
    short Day = ReadDay();
    short Month = ReadMonth();
    short Year = ReadYear();

    if (IsLastDayInMonth(Year, Month, Day))
        cout << "\nYes, Day is Last Day In Month.\n" << endl;
    else 
        cout << "\No, Day is Not Last Day In Month.\n" << endl;

    
    if(IsLastMonthInYear(Month)) 
        cout << "\nYes, Month is Last Month In Year.\n" << endl;
    else
        cout << "\No, Month is Not Last Month In Year.\n" << endl;

}