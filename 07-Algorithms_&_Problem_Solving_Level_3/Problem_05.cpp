#include <iostream>
#include <iomanip>
using namespace std;

int Random(int From, int To) {
    return rand() % (To - From + 1) + From;
}

void FillMatrixWithRandomNumbers(int arr[3][3], int Rows, int Cols) {
    for (int i = 0; i < Rows; i++) {
        for (int j = 0; j < Cols; j++) {
            arr[i][j] = Random(1, 100);
        }
    }
}

void PrintMatrix(int arr[3][3], int Rows, int Cols) {
    cout << "The Follwing is 3x3 random matrix: \n";
    for (int i = 0; i < Rows; i++) {
        for (int j = 0; j < Cols; j++) {
            cout << setw(3) << arr[i][j] << "   ";
        }
        cout << endl;
    }
    cout << '\n';
}

int SumCols(int arr[3][3], int ColNumber, int Cols) {
    int sum = 0;
    for (int i = 0; i < Cols; i++) {
        sum += arr[i][ColNumber];
    }
    return sum;
}

void AddColsSumInArray(int arr[3][3], int arrSum[3], int Rows, int Cols) {

    for (int i = 0; i < Rows; i++) {
            arrSum[i] = SumCols(arr,i, Rows);
    }
}

void PrintArraySum(int arr[3], int Length) {
    cout << "The following are the sum of each col in the matirx: \n";
    for (int i = 0; i < Length; i++) {
        cout << "Col " << i+1 << " Sum = " << arr[i] << endl;

    }

}

int main()
{
    srand((unsigned)time(NULL));
    int arr2D[3][3], arr1D[3];
    FillMatrixWithRandomNumbers(arr2D, 3, 3);
    PrintMatrix(arr2D, 3, 3);
    AddColsSumInArray(arr2D, arr1D, 3, 3);
    PrintArraySum(arr1D, 3);
}
