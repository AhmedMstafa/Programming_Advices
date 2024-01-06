#include <iostream>
using namespace std;
int Random(int From, int To) {
	return rand() % (To - From + 1) + From;
}

int ReadNumber() {
	int Number;
	cout << "Enter Number Of Elements: ";
	cin >> Number;
	return Number;
}

void FillArrayWithRandomNumbers(int arr[100], int& Length) {
	Length = ReadNumber();
	for (int i = 0; i < Length; i++) {
		arr[i] = Random(1, 100);
	}
}

int EvenCount(int arr[100], int Length) {
	int Count = 0;
	for (int i = 0; i < Length; i++) {
		if (arr[i] % 2 == 0)
			Count++;
		else
			continue;
	}
	return Count;
}

void PrintArray(int arr[100], int Length) {
	for (int i = 0; i < Length; i++)
		cout << arr[i] << " ";
	cout << "\n";
}

int main()
{
	srand((unsigned)time(NULL));
	int Array[100], Length = 0;
	FillArrayWithRandomNumbers(Array, Length);
	cout << "\nArray Elements: ";
	PrintArray(Array, Length);
	cout << "\nEven Numbers count is: ";
	cout << EvenCount(Array, Length) << endl;
}
