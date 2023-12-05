#include <iostream>
using namespace std;


int main()
{
	for (int i = 1; i <= 10; i++) {
		cout << "i = " << i << endl;
		for (int j = 1; j <= 10; j++) {
			cout << i << " * " << j << " = " << i * j << endl;
			
		}
		cout << "------------------------------\n";
	}
	for (int i = 1; i <= 10; i++) {
		for (int j = 1; j <= 10; j++) {
			cout << "*";
		}
		cout << "\n";
	}

	for (int i = 65; i <= 65 + 25; i++) {
		for (int j = 65; j <= 65 + 25; j++) {
			cout << char(i) << char(j);
		cout << "\n";
		}

	}

	for (int i = 1; i <= 10; i++) {
		for (int j = 10; j >= i; j--) {
			cout << "*";
		}
		cout << "\n";
	}

	for (int i = 10; i >= 1; i--) {
		for (int j = 1; j <= i; j++) {
			cout << j;
		}

		cout << "\n";
	}
	for (int i = 1; i <= 10; i++) {
		for (int j = 1; j <= i; j++) {
			cout << j;
		}

		cout << "\n";
	}

	for (int i = 1; i <= 25; i++) {
		for(int j = 1; j <= i; j++) {
			cout << char(j + 64);
		}
		cout << endl;
	}
}
