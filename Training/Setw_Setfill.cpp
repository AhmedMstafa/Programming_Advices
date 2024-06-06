#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	// setfill(char);

	int Col1 = 10, Col2 = 2, Col3 = 10;
	cout << // Row One
		setw(Col1) << left << "Name" <<
		setw(Col2) << left << "|"    <<
		setw(Col3) << left << "Age" <<
		setw(Col2) << left << "|" <<
		setw(Col3) << left << "Salary" << endl;

	cout << // Row Two
		setw(Col1) << left << "Ahemd" <<
		setw(Col2) << left << "|" <<
		setw(Col3) << left << "26" <<
		setw(Col2) << left << "|" <<
		setw(Col3) << left << "10000" << endl;

	cout << // Row Three
		setw(Col1) << left << "Mohamed" <<
		setw(Col2) << left << "|" <<
		setw(Col3) << left << "Khaled" <<
		setw(Col2) << left << "|" <<
		setw(Col3) << left << "2000" << endl;
}
