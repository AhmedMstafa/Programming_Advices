#include <iostream>
using namespace std;



void FillArray(int arr[100], int& arrLength) {
    arrLength = 10;
    arr[0] = 10;
    arr[1] = 10;
    arr[2] = 10;
    arr[3] = 50;
    arr[4] = 50;
    arr[5] = 70;
    arr[6] = 70;
    arr[7] = 70;
    arr[8] = 70;
    arr[9] = 90;

}


void AddArrayElement(int Number, int arr[100], int& Length)
{
    Length++;
    arr[Length - 1] = Number;
}

void PrintArray(int arr[100], int Length) {
    for (int i = 0; i < Length; i++) 
        cout << arr[i] << " ";
    cout << "\n";
}

short FindNumberPostionInArray(int Number, int arr[100], int arrLength) {
    for (int i = 0; i < arrLength;i++) {
        if (Number == arr[i])
             return i ;
    }
    return - 1;
}

bool IsNumberInArray(int Number, int arr[100], int arrLength) {
    return FindNumberPostionInArray(Number, arr, arrLength) != - 1;
}


void CopyDistinctNumbersToArray(int arrSource[100], int arrDestination[100], int SourceLength, int& DestinationLength) {
    for (int i = 0; i < SourceLength; i++) {
        if (!IsNumberInArray(arrSource[i], arrDestination, DestinationLength)) {
            AddArrayElement(arrSource[i], arrDestination, DestinationLength);
        }
    }
}



int main()
{
    int arrSource[100], SourceLength = 0, arrDestination[100], DestinationLength = 0;
    FillArray(arrSource, SourceLength);

    cout << "\nArray 1 elements: \n";
    PrintArray(arrSource, SourceLength);

    CopyDistinctNumbersToArray(arrSource, arrDestination, SourceLength, DestinationLength);
    cout << "\nArray 2 elements: \n";
    PrintArray(arrDestination, DestinationLength);
    
}
