#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector <int> vNumbers = { 1,2,3,4,5,6 };

	cout << "Numbers Vector = ";

	// ranged loop
	for (int& Number : vNumbers) {
		cout << Number << " ";
	}
	cout << endl;
}
