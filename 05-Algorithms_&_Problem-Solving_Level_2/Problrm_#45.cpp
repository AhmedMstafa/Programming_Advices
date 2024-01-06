#include <iostream>
using namespace std;
int Random(int From, int To) {
	return rand() % (To - From + 1) + From;
}


void FillArrayWithRandomNumbers(int arr[100], int& Length) {
	cout << "Enter Number Of Elements: ";
	cin >> Length;
	for (int i = 0; i < Length; i++) {
		arr[i] = Random(-100, 100);
	}
}

int NegativeCount(int arr[100], int Length) {
	int Count = 0;
	for (int i = 0; i < Length; i++) {
		if (arr[i] < 0)
			Count++;
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
	cout << "\Negative Numbers count is: ";
	cout << NegativeCount(Array, Length) << endl;
}
