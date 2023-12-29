#include <iostream>
#include <cstdlib>
using namespace std;


int Random(int From, int To)
{
    return rand() % (To - From + 1) + From;
}

int ReadPositiveNumber(string Message)
{
    int Number = 0;
    do
    {
        cout << Message << endl;
        cin >> Number;
    } while(Number < 0);
    return Number;
}

void FillArrayWithRandomNumbers(int Array[100], int Length)
{
    for (int i = 0; i < Length; i++)
        Array[i] = Random(1, 100);
}




void PrintArray(int Array[100], int Length)
{
    for (int i = 0; i < Length; i++)
        cout << Array[i] << " ";
    cout << "\n";
}

void CopyArray(int sourceArr[100], int DistenationArr[100], int Length) {
    for (int i = 0; i < Length; i++) {
        DistenationArr[i] = sourceArr[i];

    }
}


void SumTowArrays(int Arr1[100], int Arr2[100], int Arr3[100], int Length)
{
    for (int i = 0; i < Length; i++)
    {
        Arr3[i] = Arr1[i] + Arr2[i];
    }
}




int main()
{
    srand((unsigned)time(NULL));

    int Array[100], Array2[100],Array3[100];
    int Length = ReadPositiveNumber("Enter Number Of Elements: ");
    FillArrayWithRandomNumbers(Array, Length);

    cout << "\nArray Elements: ";
    PrintArray(Array, Length);

    cout << "\nArray 2 elements: ";
    CopyArray(Array, Array2,Length);
    PrintArray(Array2, Length);

    SumTowArrays(Array, Array2, Array3, Length);
    cout << "\nSum of Array1 And Array2 elements; ";
    PrintArray(Array3, Length);


}