#include <iostream>
#include <iomanip>
using namespace std;

int RandomNumber(int From, int To) {
    return rand() % (To - From + 1) + From;
}

void FillMatrixWithRandomNumbers(int arr[3][3], int Rows, int Cols) {
    for (int i = 0; i < Rows; i++) {
        for (int j = 0; j < Cols; j++) {
            arr[i][j] = RandomNumber(1, 100);
        }
    }
}

void PrintMatrix(int arr[3][3], int Rows, int Cols) {
    for (int i = 0; i < Rows; i++) {
        for (int j = 0; j < Cols; j++) {
            cout << setw(3) << arr[i][j] << "   ";
        }
        cout << endl;
    }
}

int RowSum(int arr[3][3], int RowNumber, int cols) {
    int Sum = 0;
    for (int i = 0; i < cols; i++) {
        Sum += arr[RowNumber][i];
    }
    return Sum;
}

void PrintEachRowSum(int arr[3][3], int Rows, int Cols) {
    cout << "\nThe following are the sum of each row in the matrix: " << endl;
    for (int i = 0; i < Rows; i++) {
        cout << "Row" << i + 1 << " = " << RowSum(arr, i, Cols) << endl;
    }
}

int main()
{
    srand((unsigned)time(NULL));
    int Array[3][3];
    FillMatrixWithRandomNumbers(Array, 3, 3);
    PrintMatrix(Array, 3, 3);
    PrintEachRowSum(Array, 3, 3);

}
