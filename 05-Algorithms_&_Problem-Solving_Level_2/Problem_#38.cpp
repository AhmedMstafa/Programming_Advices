#include <iostream>
#include <cstdlib>
using namespace std;

enum enOddEven {Odd = 1 , Even = 2};

enOddEven ChickOddOrEven(int Number) {
    if (Number % 2 == 0)
        return enOddEven::Even;
    else
        return enOddEven::Odd;
}

int ReadNumber(string Message) {
    int Number = 0;
    do {
        cout << Message << "\n";
        cin >> Number;
    } while (Number <= 0);
    return Number;
}

int Random(int From, int To)
{
    return rand() % (To - From + 1) + From;
}

void FillArray(int arr[100], int Length)
{
    for (int i = 0; i < Length; i++) {
        arr[i] = Random(1, 100);
    }
}

void PrintArray(int arr[100], int Length) {
    for (int i = 0; i < Length; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

void AddArrayElement(int Number, int arr[100], int& Length) {
    Length++;
    arr[Length - 1] = Number;
}

void CopyOddNumbers(int arr1[100], int arr2[100], int Length1, int& Length2) {
    for (int i = 0; i < Length1; i++) {
    if (ChickOddOrEven(arr1[i]) == enOddEven::Odd) {
        AddArrayElement(arr1[i], arr2, Length2);
    }
    }
}






int main()
{
    srand((unsigned)time(NULL));
    int Array[100];
    int Length = ReadNumber("Please Enter Number of Elements: ");
    FillArray(Array, Length);
    cout << "Array 1 elements:\n";
    PrintArray(Array, Length);
    int Array2[100];
    int Length2 = 0;
    CopyOddNumbers(Array, Array2, Length, Length2);
    cout << "Array 2 elements after copy:\n";
    PrintArray(Array2, Length2);
}

