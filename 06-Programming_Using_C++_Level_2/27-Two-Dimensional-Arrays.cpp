

#include <iostream>
using namespace std;

void FillArrayWithNumbers(int arr[10][10], int Length) {
    for (int i = 0; i < Length; i++) {
        for (int j = 0; j < Length; j++) {
            arr[i][j] = (i +1) * (j + 1);
           
        }
        
    }
}

void PrintNumbersInArray(int arr[10][10], int Length) {
    for (int i = 0; i < Length; i++) {
        for (int j = 0; j < Length; j++) {
            printf("%0*d ", 2,arr[i][j]);

        }
        cout << endl;
    }
}

int main()
{
    int Array[10][10];
    int Length = 10;
    FillArrayWithNumbers(Array,Length);
    PrintNumbersInArray(Array, Length);
}
