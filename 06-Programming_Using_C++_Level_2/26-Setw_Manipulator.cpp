#include <iostream>
#include <iomanip> // this library stored the std::setw
using namespace std;


int main()
{
	cout << "---------|--------------------------------|---------|" << endl;
	cout << "  Code   |                Name            |   Mark  |" << endl;
	cout << "---------|--------------------------------|---------|" << endl;
	cout << setw(9) << "C101" << "|" << setw(32) << "introduction to Programming 1" << "|" << setw(9) << "95" << "|" << endl;
	cout << setw(9) << "C102" << "|" << setw(32) << "Computer HardWare" << "|" << setw(9) << "88" << "|" << endl;
	cout << setw(9) << "C103" << "|" << setw(32) << "Network" << "|" << setw(9) << "75" << "|" << endl;
	cout << "---------|--------------------------------|---------|" << endl;

}

