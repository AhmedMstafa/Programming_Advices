#include <iostream>
#include <string>
using namespace std;

short ReadYear() {
    short Year = 0;
    cout << "Please Enter a Year? ";
    cin >> Year;
    return Year;
}

short ReadMonth() {
    short Month = 0;
    cout << "Please Enter a Month? ";
    cin >> Month;
    return Month;
}

short ReadDay() {
    short Day = 0;
    cout << "Please Enter a Day? ";
    cin >> Day;
    return Day;
}
short GetOrderOfTheDay(short Year, short Month, short Day) {
    short a, y, m;
     a = (14 - Month) / 12;
     y = Year - a;
     m = Month + (12 * a) - 2;

    short d = (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
    return d;
}

string DateOfTheDay(short Year, short Month, short Day) {
    return to_string(Day) + "/" + to_string(Month) + "/" + to_string(Year);
}

string DayName(short Day) {

    string Days[7]{ "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };
    return Days[Day];
}

void PrintDayInformation(short Year, short Month, short Day) {
    cout << "\nDate       : " << DateOfTheDay(Year, Month, Day) << endl;
    cout << "Day Order  : " << GetOrderOfTheDay(Year, Month, Day) << endl;
    cout << "Day Name   : " << DayName(GetOrderOfTheDay(Year, Month, Day)) << endl;
}


int main()
{
    short Year = ReadYear();
    short Month = ReadMonth();
    short Day = ReadDay();
    PrintDayInformation(Year, Month, Day);
}
