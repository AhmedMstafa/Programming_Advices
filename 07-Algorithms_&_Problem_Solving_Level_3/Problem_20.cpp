#include <iostream>
#include <iomanip>
using namespace std;

bool IsPalindromeMatrix(int arr[3][3], short Rows, short Cols) {
	for (short i = 0; i < Rows; i++) {
		for (short j = 0; j < Cols; j++) {
			if (arr[i][j] != arr[i][Cols - j - 1])
				return false;
		}
	}
	return true;
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
	int Matrix1[3][3] = { {1,2,1},{5,5,5},{7,3,7} };
	int Matrix2[3][3] = { {5,80,90},{22,77,1},{10,8,33} };
	cout << "Matrix1:\n\n";
	PrintMatrix(Matrix1, 3, 3);
	if (IsPalindromeMatrix(Matrix1, 3, 3)) {
		cout << "Yes: Matrix is Palindrome\n";
	}
	else {
		cout << "No: Matrix is Not Palindrome\n";
      system("pause>0");
	}
	return 0;
}
