#include <iostream>
using namespace std;

void PrintMatrix(int arr[3][3], int Rows, int Cols) {
	for (short i = 0; i < Rows; i++) {
		for (short j = 0; j < Cols; j++) {
			printf("%d  ", arr[i][j]);
		}
		cout << endl;
	}
	cout << endl;
}

bool IsScalarM(int arr[3][3], int Rows, int Cols) {
	int FirstDiagElement = arr[0][0];
	for (short i = 0; i < Rows; i++) {
		for (short j = 0; j < Cols; j++) {
			if(i != j && arr[i][j] != 0) {
				return false;
			}
			if (i == j && arr[i][j] != FirstDiagElement) {
				return false;
			}
		}
	}
	return true;
}

void main() {
	int Matrix[3][3] = { {10,0,0},{0,10,0},{0,0,10} };
	PrintMatrix(Matrix, 3, 3);
	if (IsScalarM(Matrix, 3, 3)) {
		cout << "Salar Matrix\n";
	}
	else {
		cout << "Not Scalar Matrix\n";
	}
}