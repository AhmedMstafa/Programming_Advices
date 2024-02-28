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

void PrintMatrix(int arr[3][3], short Rows, short Cols) {
	for (short i = 0; i < Rows; i++) {
		for (short j = 0; j < Cols; j++) {
			printf("%0*d  ", 2, arr[i][j]);
		}
		cout << endl;
	}
	cout << endl;
}



bool AreTypicalM(int arr1[3][3], int arr2[3][3], short Rows, short Cols) {
	for (short i = 0; i < Rows; i++) {
		for (short j = 0; j < Cols; j++) {
			if (arr1[i][j] != arr2[i][j])
				return false;
		}
	}
	return true;
}


int main()
{

	srand((unsigned)time(NULL));
	int Matrix1[3][3], Matrix2[3][3];

	FillMatrixWithRandomNumbers(Matrix1, 3, 3);
	cout << "Matrix1:\n";
	PrintMatrix(Matrix1, 3, 3);

	FillMatrixWithRandomNumbers(Matrix2, 3, 3);
	cout << "Matrix2:\n";
	PrintMatrix(Matrix2, 3, 3);

	(AreTypicalM(Matrix1, Matrix2, 3, 3)) ? cout << "Yes Matrices are Typical.\n" : cout << "No Matrices are Not Typical.\n";
	return 0;
}