#include <iostream>
using namespace std;


void FillArray(int arr[100], int& Length) {
    Length = 6;
    arr[0] = 10;
    arr[1] = 20;
    arr[2] = 30;
    arr[3] = 30;
    arr[4] = 20;
    arr[5] = 10;
}


void PrintArray(int arr[100], int Length) {
    for (int i = 0; i < Length; i++) 
        cout << arr[i] << " ";
    cout << "\n";
}








bool IsPlandromArray(int arr[100], int Length) {
    for (int i = 0; i < Length; i++) {
        if (arr[i] != arr[Length - i - 1]) {
            return false;
        }
  }
    return true;
}

int main()
{
    int Array[100], Length = 0;
    FillArray(Array, Length);
    cout << "\nArray Elements:\n";
    PrintArray(Array, Length);
    if (IsPlandromArray(Array, Length))
        cout << "\n\nYes Is Palindrom Array\n";
    else
        cout << "\n\n No Is Not Palindrom Array\n";
    

}

