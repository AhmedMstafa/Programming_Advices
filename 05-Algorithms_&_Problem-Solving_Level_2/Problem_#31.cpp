#include <iostream>
#include <cstdlib>
using namespace std;

int ReadPositiveNumber(string Message) {
    int Number = 0;
    do
    {
        cout << Message << "\n";
        cin >> Number;
    } while (Number <= 0);
    return Number;
}

int RandomNumber(int From, int To) {
    return rand() % (To - From + 1) + From;
}

void FillArrayWith1toN(int arr[100], int Length) {
    for (int i = 0; i < Length; i++) {
        arr[i] = i + 1;
    }
}

void PrintArray(int arr[100], int Length) {
    for (int i = 0; i < Length; i++)
        cout << arr[i] << " ";
        cout << endl;
}

void SwapTwoNumbers(int& Num1, int& Num2) {
    int Temp = 0;
    Temp = Num1;
    Num1 = Num2;
    Num2 = Temp;
}

void ShuffleArray(int arr[100],int Length) {
    for (int i = 0; i < Length; i++) {
        SwapTwoNumbers(arr[RandomNumber(1,Length -1) ], arr[RandomNumber(1, Length -1)]);
    }
}




int main()
{
    srand((unsigned)time(NULL));
    int Array[100];
    int Length = ReadPositiveNumber("Please Enter Number Of Elements: ");
    FillArrayWith1toN(Array, Length);
    cout << "\nArray elemnts before shuffle: \n";
    PrintArray(Array, Length);
    cout << "\nArray elements after shuffle: \n";
    ShuffleArray(Array, Length);
    PrintArray(Array, Length);

}
