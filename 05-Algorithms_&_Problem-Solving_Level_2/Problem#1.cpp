#include <iostream>
using namespace std;
#include <string>


// Try
/*
string PrintString(string Letter, bool InLoop =false, int Counter = 0) {
	string LetterInLoop = Letter;
	if (InLoop)
		for (int i = 1; i <= Counter; i++) {
			LetterInLoop += Letter;
		}
	else
		return Letter;

	return LetterInLoop;
	
}

string PrintRow() {
	string Row ;
	for (int i = 1; i <= 10; i++) {
		Row += PrintString(" ", true, 6) + to_string(i);
	}
	return Row;
}

string PrintColomn(int Number , int Space, bool Sign = true)
{
	string Col;
	if (Sign)
		Col = to_string(Number) + PrintString(" ", true, Space - 3 - to_string(Number).length()) + "|  ";
	else
		Col = to_string(Number) + PrintString(" ", true, Space - to_string(Number).length());

	return Col;
	
}

void PrintTabel() {
	for (int i = 1; i <= 10; i++) {
		cout << PrintColomn(i, 6, true);
		for (int j = 1; j <= 10; j++) {
			cout << PrintColomn((i * j), 7, false);
		}
		cout << endl;
	}
}

void MultipliTable()
{
	string Title = PrintString("Multiplication Table From 1 to 10");
	string Space = PrintString(" ", true,30);
	cout << endl << Space << Title << endl << endl;
	cout << PrintRow();
	cout << endl << endl << PrintString("-", true, PrintRow().length()) << endl;
	PrintTabel();
}
*/

//# Solution 


void PrintTableHeader() {
	cout << "\n\n\t\t\t Mutipliaction Table From 1 to 10\n\n";
	cout << "\t";

	for (int i = 1; i <= 10; i++) {
		cout << i << "\t";
	}

	cout << "\n-----------------------------------------------------------------------------------\n";
}


string ColumSperato(int i)
{
	if (i < 10) 
		return "    |";
	else
		return "   |";
}


void PrintMultiplicationTabel()
{
	PrintTableHeader();
	for (int i = 1; i <= 10; i++)
	{
		cout << "" << i << ColumSperato(i) << "\t";
		for (int j = 1; j <= 10; j++)
		{
			cout << i * j << "\t";
		}
		cout << endl;
	}
}


int main()
{
	//MultipliTable();
	PrintMultiplicationTabel();
	return 0;
}
