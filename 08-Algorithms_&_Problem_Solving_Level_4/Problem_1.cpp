#include <iostream>
#include <string>
using namespace std;

string Numbers(int Number) {
	string N[11]{"One","Two", "Three", "Four","Five","Six", "Seven","Eight", "Nine" ,"Ten"};
	return N[Number - 1];
}


int ReadNumber() {
	int Number = 0;
	cout << "Enter a Number ? ";
	cin >> Number;
	return Number;
}

string TextOfNumber(int Count, int Number) {
	if (Number == 0) return "";
	switch (Count)
	{
	case 1:
		return Numbers(Number) + " ";
		break;
	case 2:
		return Numbers(Number) + "ty ";
		break;
	case 3:
		return Numbers(Number) + " Handred ";
		break;
	case 4:
		return Numbers(Number) + " Thousand ";
		break;
	case 5:
	case 6:
		return Numbers(Number) + " Handred Thousand ";
		break;
	case 7:
		return Numbers(Number) + " Million ";
		break;
	}
}



void PrintTextOfNumber(int Number) {
	string Numbers[100];
	int Count = 0;
	int Remainder = 0;
	while (Number > 0) {
		Count++;
		Remainder = Number % 10;
		Number /= 10;
		Numbers[Count -1] = TextOfNumber(Count, Remainder);
	}
	for (int i = Count; i >= 0; i--) {
		cout << Numbers[i];
	}
}


int main()
{
	int Number = ReadNumber();
	cout << Number << endl;
	PrintTextOfNumber(Number);
}
