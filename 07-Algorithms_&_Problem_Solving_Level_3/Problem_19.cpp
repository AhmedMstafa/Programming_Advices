#include <iostream>
#include <iomanip>
using namespace std;

int MaxNumberInMatrix(int arr[3][3], short Rows, short Cols) {
	short MaxNumber = arr[0][0];
	for (short i = 0; i < Rows; i++) {
		for (short j = 0; j < Cols; j++) {
			if (arr[i][j] > MaxNumber)
				MaxNumber = arr[i][j];
		}
	}
	return MaxNumber;
}
int MinNumberInMatrix(int arr[3][3], short Rows, short Cols) {
	short MinNumber = arr[0][0];
	for (short i = 0; i < Rows; i++) {
		for (short j = 0; j < Cols; j++) {
			if (arr[i][j] < MinNumber)
				MinNumber = arr[i][j];
		}
	}
	return MinNumber;
}

void PrintMatrix(int arr[3][3], short Rows, short Cols) {
	for (short i = 0; i < Rows; i++) {
		for (short j = 0; j < Cols; j++) {
			cout << setw(3) << arr[i][j] << "  ";
		}
		cout << endl;
	}
	cout << '\n';
}
int main()
{
	int Matrix[3][3] = { {77,5,12},{22,20,6},{14,3,9} };
	PrintMatrix(Matrix, 3, 3);
	cout << "Minimum Number is: " << MinNumberInMatrix(Matrix, 3, 3) << endl;
	cout << "Max Number is : " << MaxNumberInMatrix(Matrix, 3, 3) << endl;
}
