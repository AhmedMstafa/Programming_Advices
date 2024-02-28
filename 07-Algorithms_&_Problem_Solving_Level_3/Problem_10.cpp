#include <iostream>
#include <iostream>
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

int SumMatrix(int arr[3][3], short Rows, short Cols) {
	int Sum = 0;
	for (short i = 0; i < Rows; i++) {
		for (short j = 0; j < Cols; j++) {
			Sum += arr[i][j];
		}
	}

	return Sum;
}



int main()
{

	srand((unsigned)time(NULL));
	int Matrix[3][3];
	FillMatrixWithRandomNumbers(Matrix, 3, 3);
	cout << "Matrix1:\n";
	PrintMatrix(Matrix, 3, 3);
	cout << "Sum of Matrix is: " << SumMatrix(Matrix, 3, 3) << endl;
	return 0;
}