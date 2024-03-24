#include <iostream>
using namespace std;

short ReadYear() {
    short Year;
    cout << "Please Enter a Year to check? ";
    cin >> Year;
    return Year;
}

short ReadMonth() {
    short Month;
    cout << "Please Enter a Month to check? ";
    cin >> Month;
    return Month;
}

bool IsLeapYear(short Year) {
    return !(Year % 400) || (!(Year % 4) && (Year % 100));
}

short NumberOfDaysInMonth(short Year, short Month) {
    if (Month < 0 || Month > 12)
        return 0;

    if (Month == 2)
     return   IsLeapYear(Year) ? 29 : 28;

    short DaysOfMonth[7]{ 1,3,5,7,8,10,12 };
    for (short i = 0; i < 7; i++) {
        if (DaysOfMonth[i] == Month)
            return 31;
    }
    return 30;
}

short NumberOfHoursInMonth(short Year, short Month) {
    return NumberOfDaysInMonth(Year, Month) * 24;
}

int NumberOfMinutesInMonth(short Year, short Month) {
    return NumberOfHoursInMonth(Year, Month) * 60;
}

int NumberOfSecondsInMonth(short Year, short Month) {
    return NumberOfMinutesInMonth(Year, Month) * 60;
}

int main()
{
    short Year = ReadYear();
    short Month = ReadMonth();

    cout << "\nNumber of Days    in Month [" << Month << "] is " << NumberOfDaysInMonth(Year, Month) << endl;
    cout << "Number of Hours   in Month [" << Month << "] is " << NumberOfHoursInMonth(Year, Month) << endl;
    cout << "Number of Minutes in Month [" << Month << "] is " << NumberOfMinutesInMonth(Year, Month) << endl;
    cout << "Number of Seconds in Month [" << Month << "] is " << NumberOfSecondsInMonth(Year, Month) << endl;

}
