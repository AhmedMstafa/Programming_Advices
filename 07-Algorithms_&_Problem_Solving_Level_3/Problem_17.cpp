#include <iostream>
using namespace std;

struct stIndex {
    int RowIndex = -1;
    int ColIndex = -1;
};

stIndex PositionNumberInMatrix(int Number, int arr[3][3], short Rows, short Cols) {
    stIndex IndexNumber;
    for (short i = 0; i < Rows; i++) {
        for (short j = 0; j < Cols; j++) {
            if (arr[i][j] == Number) {
                IndexNumber.RowIndex = i;
                IndexNumber.ColIndex = j;
                return IndexNumber;
            }
        }
    }
    return IndexNumber;
}

bool IsNumberInMatrix(int Number, int arr[3][3], short Rows, short Cols) {
    return (PositionNumberInMatrix(Number, arr, Rows, Cols).RowIndex != -1 && PositionNumberInMatrix(Number, arr, Rows, Cols).ColIndex != -1);
}

void PrintMatrix(int arr[3][3], short Rows, short Cols) {
    for (short i = 0; i < Rows; i++) {
        for (short j = 0; j < Cols; j++) {
            printf("%d  ", arr[i][j]);
        }
        cout << endl;
    }
    cout << "\n";
}

int main()
{
    int Matrix[3][3] = { {1,1,1},{2,2,2},{3,3,3} };
    PrintMatrix(Matrix, 3, 3);
    int Number;
    cout << "Please Enter the number to look for in matrix?";
    cin >> Number;

    if (IsNumberInMatrix(Number,Matrix, 3, 3)) {
        cout << "\nYes: it is there\n";
    }
    else {
        cout << "\nNo: it is'nt there\n";
    }

}

