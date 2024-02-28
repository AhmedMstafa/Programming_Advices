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
    int Count = 0;
    for (short i = 0; i < Rows; i++) {
        for (short j = 0; j < Cols; j++) {
            if (arr[i][j] == Number)
                Count++;
        }
    }
    return Count;
}






int main()
{
    int Matrix[3][3] = { {9,1,12 }, {0,9,1}, {0,9,9} };
    int Number;
    cout << "\nEnter the number to count in Matrix?";
    cin >> Number;
    PrintMatrix(Matrix, 3, 3);
    cout << "\nNumber " << Number << " count in Matrix is ";
    cout << CountNumberInMatrix(Number, Matrix, 3, 3) << endl;;
}
