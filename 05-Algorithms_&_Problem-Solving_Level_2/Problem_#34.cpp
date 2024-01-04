#include <iostream>
#include <cstdlib>
using namespace std;

int ReadPositiveNumber(string Message) {
	int Number = 0; 
	do {
		cout << Message << endl;
		cin >> Number;
	} while (Number <= 0);
	return Number;
}

int Random(int From, int To) {
	return rand() % (To - From + 1) + From;
}

void FillArrayWithNumbers(int arr[100], int Length) {
	for (int i = 0; i < Length; i++) {
		arr[i] = Random(1, 100);
	}
}

void PrintArray(int arr[100], int Length) {
	for (int i = 0; i < Length; i++) {
		cout << arr[i] << " ";
	}
	cout << "\n";
}

short FindNumberPositionInArray(int Number, int arr[100], int arrLength) {
	for (int i = 0; i < arrLength; i++) {
		if (Number == arr[i])
			return i;
	}
	return -1;
}




int main()
{
	srand((unsigned)time(NULL));
	int Array[100];
	int Length = ReadPositiveNumber("Please Enter Number of Elements: ");
	FillArrayWithNumbers(Array, Length);
	cout << "\nArray 1 elements: \n";
	PrintArray(Array, Length);
	int Number = ReadPositiveNumber("Please Enter a Number to search for? ");
	cout << "Numbe you are looking for is: " << Number << "\n";
	short NumberPosition = FindNumberPositionInArray(Number, Array, Length);
	if (NumberPosition == -1) {

		cout << "The Number is Not Found :-(";
	}
	else {

		cout << "The Number Found at Positon: " << NumberPosition << "\n";
		cout << "The Number Found its Order: " << NumberPosition + 1 << "\n";
	}
	

}
