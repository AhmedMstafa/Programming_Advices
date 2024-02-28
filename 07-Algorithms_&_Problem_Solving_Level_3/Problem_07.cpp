#include <iostream>
#include <iomanip>
using namespace std;

void FillMatrixWithOrderedNumbers(int arr[3][3], short Rows, short Cols) {
	short Count = 0;
	for (short i = 0; i < Rows; i++) {
		for (short j = 0; j < Cols; j++) {
			Count++;
			arr[i][j] = Count;
		}
	}
}
void TransPoseMatrix(int arr[3][3], int TPM[3][3], short Rows, short Cols) {
	for (short i = 0; i < Rows; i++) {
		for (short j = 0; j < Cols; j++) {
			TPM[i][j] = arr[j][i];
		}
	}
}

void PrintMatrix(int arr[3][3], short Rows, short Cols) {
	cout << "\nThe following is a 3x3 ordered matrix: \n";
	for (short i = 0; i < Rows; i++) {
		for (short j = 0; j < Cols; j++) {
			cout << setw(3) << arr[i][j] << "   ";
		}
		cout << endl;
	}
	cout << endl;
}



int main()
{
	int arr2D[3][3], TPM[3][3];
	FillMatrixWithOrderedNumbers(arr2D, 3, 3);
	PrintMatrix(arr2D, 3, 3);
	TransPoseMatrix(arr2D, TPM, 3, 3);
	PrintMatrix(TPM, 3, 3);
}
