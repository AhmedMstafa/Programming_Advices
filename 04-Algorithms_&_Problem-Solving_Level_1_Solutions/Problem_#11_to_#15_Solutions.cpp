#include <iostream>
using namespace std;


// # 11

/*
enum enPassFail { Pass = 1, Faill = 2 };


int SumOf3Numbers(int Num1, int Num2, int Num3)
{
    return Num1 + Num2 + Num3;

}

void PrintResults(int Total)
{
    cout << "The Total sum of Numbers is: " << Total << endl;
}


void ReadMarks(int& Mark1, int& Mark2, int& Mark3)
{
    cout << "Enter Mark 1 : \n";
    cin >> Mark1;
    cout << "Enter Mark 2 : \n";
    cin >> Mark2;
    cout << "Enter Mark 3 : \n";
    cin >> Mark3;
}

float AvrageOf3Marks(int Mark1, int Mark2, int Mark3)
{
    return (float)SumOf3Numbers(Mark1, Mark2, Mark3) / 3;
}


enPassFail CheckAverage(float AvrageOf3Marks)
{
    if (AvrageOf3Marks >= 50)
        return enPassFail::Pass;
    else
        return enPassFail::Faill;
}



void PrintAvrage(int Avrage)
{
    cout << "The Avrage of Marks is: " << Avrage << endl;

    if (CheckAverage(Avrage) == enPassFail::Pass)
        cout << "\n You Passed" << endl;
    else
        cout << "\n You Faild" << endl;
}
*/

//#12

/*

void ReadNumbers(int& Num1, int& Num2)
{
    cout << "Enter First Number :";
    cin >> Num1;
    cout << "Enter Second Number :";
    cin >> Num2;
}

int MaxOfNumers(int Num1, int Num2)
{
    if (Num1 > Num2)
        return Num1;
    else
        return Num2;
}




void PrintResults(int Max)
{
    cout << Max;
}

*/

// #13

/*

void ReadNumbers(int& A, int& B , int& C)
{
    cout << "Enter A: ";
    cin >> A;
    cout << "Enter B: ";
    cin >> B;
    cout << "Enter C: ";
    cin >> C;
}

int MaxOf3Numbers(int A, int B, int C)
{
    if (A > B)
        if (A > C)
            return A;
        else
            return C;
    else
        if (B > C)
            return B;
        else
            return C;

}


void PrintResults(int Max)
{
    cout << Max;
}

*/

//#14

/*

void ReadNumbers(int& Num1, int& Num2)
{
    cout << "Enter First Number: ";
    cin >> Num1;
    cout << "Enter Second Number: ";
    cin >> Num2;
}

void Swap(int& Num1, int& Num2)
{
    int Temp;
    Temp = Num1;
    Num1 = Num2;
    Num2 = Temp;
}

void PrintNumbers(int Num1, int Num2) {
    cout << "First Number is : " << Num1 << endl;
    cout << "Second Number is : " << Num2 << endl;
}

*/

// #15

void ReadNumbers(float& A, float& B)
{
    cout << "Enter A : \n";
    cin >> A;
    cout << "Enter B : \n";
    cin >> B;
}

float CalculateRectangeArea(float A, float B)
{
    return A * B;
}

void PrintResult(float Area)
{
    cout << "Reactange Area is: " << Area << endl;
}


int main()
{
   
//    int Mark1, Mark2, Mark3;
//    ReadMarks(Mark1, Mark2, Mark3);
//    PrintAvrage(AvrageOf3Marks(Mark1, Mark2, Mark3));

//     int Num1, Num2;
//    ReadNumbers(Num1,Num2);
//    PrintResults(MaxOfNumers( Num1,Num2 ));

//    int A, B, C;
//    ReadNumbers(A, B, C);
//    PrintResults(MaxOf3Numbers(A, B, C));


//     int Num1, Num2;
 //     ReadNumbers(Num1, Num2);
 //     PrintNumbers(Num1, Num2);
 //     Swap(Num1, Num2);
 //     PrintNumbers(Num1, Num2);
        
    float A, B;
    ReadNumbers(A, B);
    PrintResult(CalculateRectangeArea(A, B));
    


    return 0;

}