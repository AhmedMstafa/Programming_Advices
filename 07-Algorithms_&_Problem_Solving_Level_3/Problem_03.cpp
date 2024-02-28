#include <iostream>
#include <iomanip>
using namespace std;

int RandomNumber(int From, int To) {
    return rand() % (To - From + 1) + From;
}

void FillMatrixWithNumbers(int arr[3][3], int Rows, int Cols) {
    for (int i = 0; i < Rows; i++) {
        for (int j = 0; j < Cols; j++) {
            arr[i][j] = RandomNumber(1, 100);
        }
    }
}

int SumRows(int arr[3][3], int RowNumber, int Cols) {
    int Sum = 0;
    for (int i = 0; i < Cols; i++) {
        Sum += arr[RowNumber][i];
    }
    return Sum;
}

void FillArrayWithRows(int arr2D[3][3], int arr1D[3],int Rows ,int Cols) {
    for (int i = 0; i < Cols; i++) {
        arr1D[i] = SumRows(arr2D, i, Cols);
   }
}

void PrintMatrix(int arr[3][3], int Rows, int Cols) {
    cout << "The following is a 3x2 random matrix: \n\n";
    for (int i = 0; i < Rows; i++) {
        for (int j = 0; j < Cols; j++) {
            cout << setw(3) << arr[i][j] << "  ";
        }
        cout << endl;
    }
}

void PrintArray(int arr[3], int Length) {
    cout << "\nThe following are the sum of each row in the matrix: \n";
    for (int i = 0; i < Length; i++) {
        cout << "\nRow 1 Sum = " << arr[i] << "\n";
    }
}

int main()
{
    srand((unsigned)time(NULL));
    int arr2D[3][3], arr1D[3];
    FillMatrixWithNumbers(arr2D, 3, 3);
    FillArrayWithRows(arr2D, arr1D, 3, 3);
    PrintMatrix(arr2D, 3, 3);
    PrintArray(arr1D, 3);   

}
