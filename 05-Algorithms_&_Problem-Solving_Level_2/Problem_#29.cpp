#include <iostream>
#include <cstdlib>
using namespace std;

enum enPrimeNotPrime { Prime = 1, NotPrime = 2 };

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


enPrimeNotPrime ChickPrime(int Number)
{
   int M = round(Number / 2);
   for (int i = 2; i <= M; i++) {
       if (Number % i == 0)
           return enPrimeNotPrime::NotPrime;
   }
   return enPrimeNotPrime:: Prime;
}

void PrintArray(int Array[100], int Length)
{
    for (int i = 0; i < Length; i++)
            cout << Array[i] << " ";
    cout << "\n";
}

void CopyOnlyPrimeNumbers(int arrSource[100], int arrDestination[100], int arrLength,int& arr2Length)
{
    int Counter = 0;
    for (int i = 0; i < arrLength; i++) {
        if (ChickPrime(arrSource[i]) == enPrimeNotPrime::Prime) {
            arrDestination[Counter] = arrSource[i];
            Counter++;
        }
    }
    arr2Length = --Counter;
}








int main()
{
    srand((unsigned)time(NULL));

    int Array[100],Array2[100], Length,Length2 = 0;
    FillArrayWithRandomNumbers(Array, Length);

    cout << "\nArray Elements: ";
    PrintArray(Array, Length);

    cout << "\nPrime Number in Array2:";
    CopyOnlyPrimeNumbers(Array, Array2, Length,Length2);
    PrintArray(Array2, Length2);


}