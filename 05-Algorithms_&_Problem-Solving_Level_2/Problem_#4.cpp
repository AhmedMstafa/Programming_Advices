 #include <iostream>
using namespace std;

//Try

float ReadPosistiveNumber(string Message)
{
	float Number;
	do {
		cout << Message << endl;
		cin >> Number;

	} while (Number <= 0);
	return Number;
}

bool isPerfectNumber(int Number) {
	int Sum = 0;
	for (int i = 1; i < Number; i++)
	{
		if (Number % i == 0)
			Sum += i;
	}
	return (Sum == Number);
}

void ReadPerectNumberFrom1ToN(int Number)
{
	for (int i = 1; i <= Number; i++) {
		if (isPerfectNumber(i))
			cout << i << " is Perfect Number. \n";
	}
}

int main()
{
	ReadPerectNumberFrom1ToN(ReadPosistiveNumber("Please Enter a Positive Number? "));
}
 