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
			arr[i][j] = Random(1, 10);
		}
	}
}

void PrintMatrix(int arr[3][3], short Cols, short Rows) {
	for (short i = 0; i < Rows; i++) {
		for (short j = 0; j < Cols; j++) {
			printf("%0*d", 2, arr[i][j]); 
			cout << "   ";
		}
		cout << endl;
	}
	cout << endl;
}

void MultiplyMatrix(int FirstMatrix[3][3], int SecondMatrix[3][3], int DistinationMatrix[3][3], int Rows, int Cols) {
	for (short i = 0; i < Rows; i++) {
		for (short j = 0; j < Cols; j++) {
			 DistinationMatrix[i][j] = FirstMatrix[i][j] * SecondMatrix[i][j];
		}
	}
}

int main()
{

	srand((unsigned)time(NULL));
	int Matrix1[3][3],Matrix2[3][3],Matrix3[3][3];
	FillMatrixWithRandomNumbers(Matrix1, 3, 3);
	FillMatrixWithRandomNumbers(Matrix2, 3, 3);
	cout << "Matrix1:\n";
	PrintMatrix(Matrix1, 3, 3);
	cout << "Matrix2:\n";
	PrintMatrix(Matrix2, 3, 3);
	MultiplyMatrix(Matrix1, Matrix2, Matrix3, 3, 3);
	cout << "Results:\n";
	PrintMatrix(Matrix3, 3, 3);
}
