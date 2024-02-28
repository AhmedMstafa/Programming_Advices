#include <iostream>
#include <iomanip>
using namespace std;

int Random(int From, int To) {
	return rand() % (To - From + 1) + From;
}


void FillMatrixWithRandomNumbers(int arr[3][3], short Rows, short Cols) {
	short Count = 0;
	for (short i = 0; i < Rows; i++) {
		for (short j = 0; j < Cols; j++) {
			arr[i][j] = Random(1, 100);
		}
	}
}

void PrintMatrix(int arr[3][3], short Cols, short Rows) {
	for (short i = 0; i < Rows; i++) {
		for (short j = 0; j < Cols; j++) {
			printf("%0*d  ", 2, arr[i][j]);
		}
		cout << endl;
	}
	cout << endl;
}

void PrintMiddleRow(int arr[3][3], short Rows, short Cols) {
	short MiddleRow = Rows / 2;
		for (short j = 0; j < Cols; j++) {
			printf("%0*d  ", 2, arr[MiddleRow][j]);
		}
	cout << endl;
}

void PrintMiddleCol(int arr[3][3], short Rows, short Cols) {
	short MiddleCol = Cols / 2;
	for (short i = 0; i < Rows; i++) {
			printf("%0*d  ", 2, arr[i][MiddleCol]);
	}
	cout << endl;
}

int main()
{

	srand((unsigned)time(NULL));
	int Matrix[3][3];
	FillMatrixWithRandomNumbers(Matrix, 3, 3);
	cout << "Matrix1:\n";
	PrintMatrix(Matrix, 3, 3);
	cout << "Middle Row of Matrix is: \n";
	PrintMiddleRow(Matrix, 3, 3);
	cout << "Middle Col of Matrix is: \n";
	PrintMiddleCol(Matrix, 3, 3);
	return 0;
}