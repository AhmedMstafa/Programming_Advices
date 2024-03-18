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
	if (Month <= 0 || Month > 12) {
		return 0;
	}
	if (Month == 2) {
		return (IsLeapYear(Year)) ? 29 : 28;
	}

	short arr31Days[7] = { 1,3,5,7,8,10,12 };
	for (short i = 1; i <= 7; i++) {
		if (arr31Days[i - 1] == Month) {
			return 31;
		}
	}

	return 30;
}

short NumberOfHoursInMonth(short Year,short Month) {
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
	cout << "\nNumber of Days    in Month [" << Month << "] is " << NumberOfDaysInMonth(Year,Month) << endl;
	cout << "Number of Hours   in Month [" << Month << "] is " << NumberOfHoursInMonth(Year,Month) << endl;
	cout << "Number of Minutes in Month [" << Month << "] is " << NumberOfMinutesInMonth(Year,Month) << endl;
	cout << "Number of Seconds in Month [" << Month << "] is " << NumberOfSecondsInMonth(Year,Month) << endl;


}

