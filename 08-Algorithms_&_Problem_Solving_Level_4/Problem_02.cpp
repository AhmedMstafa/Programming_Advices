#include <iostream>
using namespace std;

int ReadYear() {
	int Year = 0;
	cout << "Please Enter A Year: ";
	cin >> Year;
	return Year;
}

bool IsLeapYear(int Year) {
	if (!(Year % 400)) {
		return true;
	}
	if ((Year % 100) && !(Year % 4)) {
		return true;
	}
	return false;
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
	cout << 1600 % 100;
}
