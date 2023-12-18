#include <iostream>
using namespace std;


 enum enPrimNumPrime {Prime = 1 , NotPrime = 2};

 float ReadPosistiveNumber(string Message)
 {
	 float Number;
	 do {
		 cout << Message << endl;
		 cin >> Number;

	 } while (Number <= 0);
	 return Number;
 }


enPrimNumPrime CheckPrime(int Number)
{
	int M = round(Number / 2);
		for (int i = 2; i <= M; i++) {
			if (Number % i == 0)
				return enPrimNumPrime::NotPrime;
	}
		return enPrimNumPrime::Prime;
}

void PrintNumberTypeFrom1ToN(int Number) {
	cout << "\n";
	cout << "Prime Numbers from ";
	cout << " are : " << endl;

	for (int i = 1; i <= Number; i++) {
		if (CheckPrime(i) == enPrimNumPrime::Prime) {
			cout << i << endl;
		}
	}
}



int main()
{
	
	PrintNumberTypeFrom1ToN(ReadPosistiveNumber("Please Enter A Positive Number : "));
}

