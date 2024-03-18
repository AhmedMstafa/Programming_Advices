#include <iostream>
using namespace std;


short ReadYear() {
	short Year = 0;
	cout << "Please Enter a year to check? ";
	cin >> Year;
	return Year;
}

bool IsLeapYear(short Number) {
	return (!(Number % 400) || ((Number % 100) && !(Number % 4)));
}



short NumberOfDaysInYear(short Year) {
	return IsLeapYear(Year) ? 366 : 365;
}

short NumberOfHoursInYear(short Year) {
	return NumberOfDaysInYear(Year) * 24;
}

int NumberOfMinutesInYear(short Year) {
	return NumberOfHoursInYear(Year) * 60;
}

int NumberOfSecondesInYear(short Year) {
	return NumberOfMinutesInYear(Year) * 60;
}

int main()
{
	short Year = ReadYear();
	cout << "\nNumber of Days    in Year [" << Year << "] is " << NumberOfDaysInYear(Year) << endl;
	cout << "Number of Hours   in Year [" << Year << "] is " << NumberOfHoursInYear(Year) << endl;
	cout << "Number of Minutes in Year [" << Year << "] is " << NumberOfMinutesInYear(Year) << endl;
	cout << "Number of Seconds in Year [" << Year << "] is " << NumberOfSecondesInYear(Year) << endl;


}