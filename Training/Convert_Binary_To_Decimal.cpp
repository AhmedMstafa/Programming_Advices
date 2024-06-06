#include <iostream>
#include <string>
using namespace std;

int BinaryToDecimal(string binary)
{
	int number = 0;
	short p = 0;
	for (int i = binary.length() - 1; i >= 0; i--)
	{
		if (binary[i] == '1')
			number += pow(2, p);

		p++;
	}

	return number;
}

int main()
{
	string binary = "";
	cout << "please enter binary number\n";
	cin >> binary;
	cout << "number in decimal is \n";
	cout << BinaryToDecimal(binary);

	//system("pause>0");
	return 0;
}
