#include <iostream>
#include <vector>
using namespace std;

void ReadNumbers(vector <int>& vNumbers) {
	int Number = 0;
	char AddNumber = 'Y';
	do{
		cout << "Enter a Number : ";
		cin >> Number;
		vNumbers.push_back(Number);
		cout << "Do you want to add more Numbers Y/N?\n";
		cin >> AddNumber;
	} while (AddNumber == 'Y' || AddNumber == 'y');
}

void PrintNumbers(vector <int>& vNumbers) {
	cout << endl;
	cout << "Numbers Vector = ";
	for (int& Number : vNumbers) {
		cout << Number << " ";
	}
	cout << endl;
}

int main()
{
	/*
	vector <int> vNumbers;

	vNumbers.push_back(10);
	vNumbers.push_back(20);
	vNumbers.push_back(30);
	vNumbers.push_back(40);
	vNumbers.push_back(50);
	vNumbers.push_back(60);
	vNumbers.push_back(70);

	cout << "Numbers Vector : \n\n";

	for (int& Number : vNumbers) {
		cout << Number << " ";
	}
	cout << endl;
	*/

	vector <int> vNumbers;
	ReadNumbers(vNumbers);
	PrintNumbers(vNumbers);
	return 0;
}
