#include <iostream>
using namespace std;

short ReadYear() {
    short Year = 0;
    cout << "\nPlease Enter a Year To Chick? ";
    cin >> Year;
    return Year;
}

bool IsLeapYear(short Year) {
    return !(Year % 400) || (!(Year % 4) && (Year % 100));
}

short NumberOfDays(short Year) {
    return IsLeapYear(Year) ? 366 : 365;
}

short NumberOfHours(short Year) {
    return NumberOfDays(Year) * 24;
}

int NumberOfMinutes(short Year) {
    return NumberOfHours(Year)* 60 ;
}

int NumberOfSeconds(short Year) {
    return NumberOfMinutes(Year) * 60;
}

int main()
{
    short Year = ReadYear();

    cout << "\nNumber Of Days     in Year [" << Year << "] is " << NumberOfDays(Year) << endl;
    cout << "\nNumber Of Hours    in Year [" << Year << "] is " << NumberOfHours(Year) << endl;
    cout << "\nNumber Of Minutes  in Year [" << Year << "] is " << NumberOfMinutes(Year) << endl;
    cout << "\nNumber Of Seconds  in Year [" << Year << "] is " << NumberOfSeconds(Year) << endl;

}
