#include <iostream>
#include <cstdlib>
using namespace std;

int Random(int From, int To)
{
    return rand() % (To - From + 1) + From;
}


void FillArrayWithRandomNumbers(int Array[100], int& Length)
{
    cout << "Enter Number Of Elements: ";
    cin >> Length;
    for (int i = 0; i < Length; i++)
        Array[i] = Random(1, 100);
}

void PrintArray(int Array[100], int Length)
{
    for (int i = 0; i < Length; i++)
        cout << Array[i] << " ";
    cout << "\n";
}


void CopyArray(int arrSource[100], int arrDestination[100], int Length)
{
    for (int i = 0; i < Length; i++) {
        arrDestination[i] = arrSource[i];
    }
}

int main()
{
    srand((unsigned)time(NULL));

    int Array1[100],Array2[100], Length;
    FillArrayWithRandomNumbers(Array1, Length);
    cout << "\nArray 1 Elements: ";
    PrintArray(Array1, Length);
    cout << "\nArra 2 Elements After Copy: ";
    CopyArray(Array1, Array2, Length);
    PrintArray(Array2, Length);
}