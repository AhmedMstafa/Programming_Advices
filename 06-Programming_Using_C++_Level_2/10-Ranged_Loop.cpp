#include <iostream>
using namespace std;


int main()
{
	int arr[10] = { 1,2,3,4,5,6,7,8 ,9,10 };
	for (int n : arr) {
		cout << n << "\n";
	}

	for (float f : {1.1, 1.2, 1.3, 1.4, 1.5}) {
		cout << f << endl;
	}

	for (char c : "Hello World") {
		cout << c <<  "\n";
	}
}
