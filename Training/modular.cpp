#include <iostream>
using namespace std;

short GetRemainder(int number,short divisor)
{
	short remainder = number / divisor;

	short qd = remainder * divisor;

	return number - qd;
}

int main()
{
	int number = 0;
	short divisor = 0;

	cout << "please enter number\n";
	cin >> number;
	cout << "please enter divisor\n";
	cin >> divisor;
	cout << number << " % " << divisor << " = "
		<< GetRemainder(number, divisor) << endl;

	system("pause > 0");
	return 0;
}