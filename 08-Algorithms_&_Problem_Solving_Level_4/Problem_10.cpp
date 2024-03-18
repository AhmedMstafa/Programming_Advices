#include <iostream>
#include <iomanip>
using namespace std;

short ReadDay() {
		short Year = 0;
		cout << "Please Enter a Day? ";
		cin >> Year;
		return Year;
}

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


bool IsLeapYear(short Year) {
	if (!(Year % 400))
		return !0;

	if ((Year % 100) && !(Year % 4))
		return !0;

	return 0;
}

short DaysOfMonth(short Year, short Month) {
	if (Month <= 0 || Month > 12)
		return 0;

	short arrOfDays[12]{ 31,28,31,30,31,30,31,31,30,31,30,31 };
	return (Month == 2) ? IsLeapYear(Year) ? 29 : 28 : arrOfDays[Month - 1];
}




short GetOrderOfTheDay(short Year, short Month, short Day) {
	short a, y, m;
	a = (14 - Month) / 12;
	y = Year - a;
	m = Month + (12 * a) - 2;

	short d = (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
	return d;
}

short TotalDaysFromBeginingOfTheYear(short Day, short Month, short Year) {

	short NumberOfDays = 0;

	for (short i = 1; i <= Month -1; i++) {
		NumberOfDays += DaysOfMonth(Year, i);
	}
	NumberOfDays += Day;
	return NumberOfDays;
}


int main()
{
	short Day = ReadDay();
	short Month = ReadMonth();
	short Year = ReadYear();

	cout << "\nNumber of Days from the begining of the year is ";
	cout << TotalDaysFromBeginingOfTheYear(Day, Month, Year);
}
