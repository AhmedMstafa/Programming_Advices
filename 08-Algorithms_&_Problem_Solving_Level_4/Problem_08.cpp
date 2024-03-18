#include <iostream>
#include <iomanip>
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


string MonthName(short Month) {
	string Months[12]{ "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul","Aug", "Sep", "Oct", "Nov", "Dec" };
	return Months[Month - 1];
}

short GetOrderOfTheDay(short Year, short Month, short Day) {
	short a, y, m;
	a = (14 - Month) / 12;
	y = Year - a;
	m = Month + (12 * a) - 2;

	short d = (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
	return d;
}


void PrintMonthCalender(short Year, short Month) {
	short Current = GetOrderOfTheDay(Year, Month, 1);
	short NumberOfTheDay = DaysOfMonth(Year, Month);

	printf("\n  _______________%s_______________\n\n", MonthName(Month).c_str());

	printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

	int i;
	for (i = 0; i < Current; i++)
		printf("     ");

	for (int j = 1; j <= NumberOfTheDay; j++) {
		printf("%5d", j);

		if (++i == 7) {
			i = 0;
			printf("\n");
		}
	}

}



int main()
{
	short Year = ReadYear();
	short Month = ReadMonth();
	PrintMonthCalender(Year, Month);

}
