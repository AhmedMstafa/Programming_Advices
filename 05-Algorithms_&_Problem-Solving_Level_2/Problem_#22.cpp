#include <iostream>
#include <string>
using namespace std;

// #try
/*
int ReadPositiveNumber(string Message)
{
    int Number = 0;
    do
    {
        cout << Message ;
        cin >> Number;
    } while (Number <= 0);
    return Number;
}

void ReadElements(int ArrayOfElements[100], int &Length) {
    for (int i = 0; i <= Length - 1; i++) {
        ArrayOfElements[i] = ReadPositiveNumber("Elemant [" + to_string(i + 1) + "] : ");
    }
}

string ReadOrignalArray(int ArrayOfElements[100], int Length)
{
    string OrignalArray = "";
    for (int i = 0; i <= Length - 1; i++) {
        OrignalArray += to_string(ArrayOfElements[i]) + " ";
    }
    return OrignalArray;
}


void ChickNumberOfElements(int ArrayOfElements[100] , int &Length) {
    int Number = ReadPositiveNumber("Enter The Number You Want to check: ");
    int Counter = 0;
    for (int i = 0; i <= Length - 1; i++) {
        if (Number == ArrayOfElements[i])
            Counter++;
        }
    cout << "Orignal array: " + ReadOrignalArray(ArrayOfElements,Length) + "\n";
    cout << Number << "is repeated " << Counter << "time(s)";
}
*/


//#Solution

int ReadPositiveNumber(string Message)
{
    int Number = 0;
    do
    {
        cout << Message;
        cin >> Number;
    } while (Number <= 0);
    return Number;
}


void ReadArray(int Array[100], int& Length)
{
    cout << "Enter Number Of Elements : ";
    cin >> Length;
    for (int i = 0; i < Length; i++) {
        cout << "Enter Element [" << i + 1 << "] :";
        cin >> Array[i];
    }

}

void PrintArray(int Array[100], int Length)
{
    for (int i = 0; i < Length; i++)
        cout << Array[i] << " ";

    cout << "\n";
}

int TimesRepeated(int Number, int Array[100], int Length) {
    int count = 0;
    for (int i = 0; i < Length; i++) {
        if (Array[i] == Number)
            count++;
    }
    return count;
}


int main()
{
 /*
    int ArrayOfElemnts[100];
    int NumberOfElements = ReadPositiveNumber("Enter Number Of Elements \n");
    ReadElements(ArrayOfElemnts, NumberOfElements);
    ChickNumberOfElements(ArrayOfElemnts, NumberOfElements);
 */

    int Array[100], Length ;
    ReadArray(Array, Length);

    int Number = ReadPositiveNumber("Enter The Number You Want to Check: ");

    cout << "Original Array: ";
    PrintArray(Array, Length);

    cout << endl << Number << " is Repeated " << TimesRepeated(Number, Array, Length) << " Time(s).\n";
}
