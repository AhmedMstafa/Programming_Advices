
#include <iostream>
using namespace std;
// Home Work
int main()
{
	int Number, Sum = 0;
	for (int i = 1; i <= 5; i++) {
		cout << "Enter A Number: ";
		cin >> Number;
		if (Number >= 50) {
			continue;
		}
		Sum += Number;
	}
	cout << Sum;
}
 