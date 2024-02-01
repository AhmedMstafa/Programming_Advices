#pragma once
#include <iostream>
#include "MyLib.h"
using namespace std;

namespace Nums {
	void PrintNumbers(short Num) {
		short Remainder = 0;
		while (Num != 0) {
			Remainder = Num % 10;
			cout << Remainder << "\n";
			Num /= 10;
		}
	}

	void PrintRevesedNumbers(short Num) {
		short Remainder = 0, Num2 = 0;

		while (Num != 0) {
			Remainder = Num % 10;
			Num2 = Num2 * 10 + Remainder;
			Num /= 10;
		}
		cout << Num2 << endl;
	}


	int Avg2Numbers(int Num1, int Num2) {
		return MyLib::Sum2Numbers(Num1, Num2) / 2;
	}

	int PowerOf(int Number, int Power) {
		for (int i = 1; i <= Power; i++) {
			Number *= Power;
		}
		return Number;
	}

}
