#include <iostream>
using namespace std;

int ReadYear() {
	int Year = 0;
	cout << "Please Enter A Year: ";
	cin >> Year;
	return Year;
}

bool IsLeapYear(int Number) {
	return (!(Number % 400) || ((Number % 100) && !(Number % 4)));
}

int main()
{
	int Year = ReadYear();
	if (IsLeapYear(Year)) {
		cout << Year << " is Leap Year \n";
	}
	else {
		cout << Year << " is not Leap Year \n";

	}
}