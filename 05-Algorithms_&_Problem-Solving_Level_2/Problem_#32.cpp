#include <iostream>
#include <cstdlib>
using namespace std;

int ReadPositiveNumber(string Message)
{
    int Number = 0; 
    do
    {
        cout << Message << endl;
        cin >> Number;
    } while (Number <= 0);
    return Number;
}

int Random(int From, int To) {
    return rand() % (To - From + 1) + From;
}

void FillArray(int arr[100], int Length)
{
    for (int i = 0; i < Length; i++) {
        arr[i] = Random(1, 100);
    }
}

void PrintArray(int arr[100], int Length)
{
    for (int i = 0; i < Length; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;
}

void ReversedArray(int arrSource[100], int arrDestination[100], int Length)
{
    for (int i = 0; i < Length; i++) 
        arrDestination[i] = arrSource[Length - i - 1];
}

int main()
{
    srand((unsigned)time(NULL));
    int Array[100];
    int Array2[100];
    int Length = ReadPositiveNumber("Please Enter Number of Elements: ");
    FillArray(Array, Length);
    cout << "\nArray 1 elements: \n";
    PrintArray(Array, Length);
    cout << "\nArray 2 elements after copying array 1 in reversed order: \n";
    ReversedArray(Array, Array2, Length);
    PrintArray(Array2, Length);
}

