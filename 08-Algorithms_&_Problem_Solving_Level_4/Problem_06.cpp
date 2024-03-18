#include <iostream>
using namespace std;


#include <iostream>
using namespace std;


short ReadYear() {
	short Year = 0;
	cout << "Please Enter a year to check? ";
	cin >> Year;
	return Year;
}

short ReadMonth() {
	short Year = 0;
	cout << "Please Enter a Month to check? ";
	cin >> Year;
	return Year;
}

bool IsLeapYear(short Number) {
	return (!(Number % 400) || ((Number % 100) && !(Number % 4)));
}

short NumberOfDaysInMonth(short Year, short Month) {
	if (Month <= 0 || Month > 12) 
		   return 0;

	short NumberOfDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31};
//	return (IsLeapYear(Year) && Month == 2) ? NumberOfDays[Month - 1] + 1  : NumberOfDays[Month - 1];
	return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : NumberOfDays[Month - 1];
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

