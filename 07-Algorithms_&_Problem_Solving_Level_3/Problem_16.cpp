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


int CountNumberInMatrix(int Number, int arr[3][3], int Rows, int Cols) {
	short Count = 0;
	for (short i = 0; i < Rows; i++) {
		for (short j = 0; j < Cols; j++) {
			if (arr[i][j] == Number)
				Count++;
		}
	}
	return Count;
}

bool IsparceMatrix(int arr[3][3], int Rows, int Cols) {
	short NumberOfElements = Rows * Cols;

	return (CountNumberInMatrix(0,arr,Rows,Cols) >= (NumberOfElements / 2));
}


int main() {
	int Matrix1[3][3] = { {0,0,0},{1,0,0},{0,0,1} };
	cout << "\nMatrix:\n";
	PrintMatrix(Matrix1, 3, 3);
	if (IsparceMatrix(Matrix1, 3, 3)) {
		cout << "Yes: It is Sparse\n";
	}
	else {
		cout << "No: It's Not Sparce\n";
	}
	system("pause>0");

}