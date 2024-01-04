#include <iostream>
using namespace std;

int ReadNumber() {
	int Number = 0;
		cout<< "Please Enter a Number\n";
		cin >> Number;
	return Number;
}

void AddArrayElement(int Number, int arr[100], int& arrLength) {
	arrLength++;
	arr[arrLength - 1] = Number;
}


void InputUserNumbersInArray(int arr[100], int& Length) {
	bool AddMore = true;
	do
	{
		AddArrayElement(ReadNumber(), arr, Length);
		cout << "\nDo you want to add more numbers? [0]:No,[1]Yes? ";
		cin >> AddMore;
	} while (AddMore);
}

void PrintArray(int arr[100], int Length) {
	for (int i = 0; i < Length; i++) {
		cout << arr[i] << " ";
	}
	cout << "\n";
}


int main()
{
	int Array[100];
	int Length = 0;
	InputUserNumbersInArray(Array, Length);
	cout << "\nArray Length " << Length << "\n";
	cout << "\nArray elements: ";
	PrintArray(Array, Length);


}
