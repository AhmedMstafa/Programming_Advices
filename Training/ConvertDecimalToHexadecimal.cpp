#include <iostream>
#include <string>
using namespace std;

int ReadNumber()
{
	int Number = 0;
	do
	{
		cout << "Please Enter a bosative Number:  ";
		cin >> Number;
	} while (Number <= 0);

	return Number;
}

char HexNumber(short Number)
{
	char HexNum[16]{'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};

	return HexNum[Number];
}

double GetfractionalPart(double Number)
{
	int Num = Number;
	double Frac = Number - Num;

	return Frac;
}

string ConvertDecimalToHexadecimal(float Number)
{
		// Dec        Number    Remainder      Hex  
	// Number / 16 = Number2.Remainder = (Remainder * 16)
	// Number2 / 16 = Number3.Remainder = (Remainder * 16)
	//...etc

	float Remainder = 0;
	string Hex = "";
	while (Number >= 1)
	{
		Remainder = Number / 16;

		Hex += HexNumber(GetfractionalPart(Remainder) * 16);

		Number /= 16;

	}
	return Hex;
}

string ConvertDecimalToHexadecimal(int Number)
{

	string  Hexadecimal = "";

	short Remainder = 0;

	while (Number > 0)
	{
		Remainder = Number % 16;

		Hexadecimal +=	HexNumber(Remainder);

		Number /= 16;
	}

	return  Hexadecimal;
}

int main()
{
	int Number = ReadNumber();

	cout << ConvertDecimalToHexadecimal(Number);
	
	system("pause>0");

	return 0;
}
