#include <iostream>
#include <cstdlib>
using namespace std;

enum enPrimeNotPrim { Prime = 1, NotPrime = 2 };

enPrimeNotPrim ChickPrimNumber(int Number) {
    int M = round(Number / 2);
    if (Number <= 1)
        return
        enPrimeNotPrim::Prime;
    for (int i = 2; i < M; i++) {
        if (Number % i == 0)
            return enPrimeNotPrim::NotPrime;
    }
    return enPrimeNotPrim::Prime;
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

void CopyPrimeNumbers(int arr1[100], int arr2[100], int Length1, int& Length2) {
    for (int i = 0; i < Length1; i++) {
        if (ChickPrimNumber(arr1[i]) == enPrimeNotPrim::Prime) {
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
    CopyPrimeNumbers(Array, Array2, Length, Length2);
    cout << "Array 2 only prime elements after copy:\n";
    PrintArray(Array2, Length2);
}