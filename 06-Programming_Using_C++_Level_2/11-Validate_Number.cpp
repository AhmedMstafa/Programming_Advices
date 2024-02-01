#include <iostream>
using namespace std;


int ReadNumber() {
	int Number;
	cout << "Please Enter a Number ? \n";
	cin >> Number;

	while (cin.fail()) {
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "Please Enter a Number ? \n";
		cin >> Number;
	}
	return Number;
}


int main()
{
	cout << "Your Number is: " << ReadNumber();
}

