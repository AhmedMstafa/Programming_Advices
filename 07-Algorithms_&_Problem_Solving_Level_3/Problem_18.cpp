#include <iostream>
#include <iomanip>
using namespace std;


bool IsNumberInMatrix(short Number, int arr[3][3], short Rows, short Cols) {
	for (short i = 0; i < Rows; i++) {
		for (short j = 0; j < Cols; j++) {
			if (arr[i][j] == Number)
				return true;
		}
	}
	return false;
}
void PrintIntersectedNumbers(int arr1[3][3], int arr2[3][3], short Rows, short Cols) {
	for (short i = 0; i < Rows; i++) {
		for (short j = 0; j < Cols; j++) {
			if (IsNumberInMatrix(arr1[i][j], arr2, Rows, Cols)) {
				cout << setw(3) << arr1[i][j] << "  " ;
			}
		}
	}
		cout << endl;
}

void PrintMatrix(int arr[3][3], short Rows, short Cols) {
	for (short i = 0; i < Rows; i++) {
		for (short j = 0; j < Cols; j++) {
			cout << setw(3) << arr[i][j] << "  ";
		}
		cout << endl;
	}
	cout << "\n";
}

int main()
{
	int Matrix1[3][3] = { {77,5,12},{22,20,1},{1,0,9} };
	int Matrix2[3][3] = { {5,80,90},{22,77,1},{10,8,33} };
	cout << "\nMatrix1:\n";
	PrintMatrix(Matrix1, 3, 3);
	cout << "Matrix2:\n";
	PrintMatrix(Matrix2, 3, 3);
	cout << "Intersected Number are: \n";
	PrintIntersectedNumbers(Matrix1, Matrix2, 3, 3);

}
