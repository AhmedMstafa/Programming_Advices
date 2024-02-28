#include <iostream>
using namespace std;

void PrintMatrix(int arr[3][3], short Rows, short Cols) {
	for (short i = 0; i < Rows; i++) {
		for (short j = 0; j < Cols; j++) {
			printf("%d  ", arr[i][j]);
		}
		cout << endl;
	}
	cout << endl;
}



bool IsIdentityM(int arr[3][3], short Rows, short Cols) {
	for (short i = 0; i < Rows; i++) {
		for (short j = 0; j < Cols; j++) {
			if (i == j && arr[i][j] != 1) {
				return false;
			}
			else if (i != j && arr[i][j] != 0) {
				return false;
			}
		}
	}
	return true;
}


int main()
{

	srand((unsigned)time(NULL));
	int Matrix[3][3] = { {1,0,0},{0,1,0},{0,0,1} };
	PrintMatrix(Matrix, 3, 3);
	if (IsIdentityM(Matrix, 3, 3))
		cout << "YES: Matrix is identity.\n";
	else
		cout << "No: Matrix is Not identity.\n";

}