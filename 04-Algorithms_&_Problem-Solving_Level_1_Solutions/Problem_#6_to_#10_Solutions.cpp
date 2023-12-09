#include <iostream>
#include <string>

using namespace std;


// #6
/*
struct strInfo {
    string FirstName;
    string LastName;
};

strInfo ReadInfo()
{
    strInfo Info;
    cout << "Please Enter Your First Name? " << endl;
    cin >> Info.FirstName;
    cout << "Plese Enter Your Last Name? " << endl;
    cin >> Info.LastName;
    return Info;
}

string GetFullName(strInfo Info, bool Reversed = false)
{
    string FullName;
    if(Reversed)
        FullName = Info.LastName + " " + Info.FirstName;
    else
    FullName = Info.FirstName + " " + Info.LastName;
    return FullName;
}

void PrintFullName(string FullName)
{
    cout << "Your Name Is: " << FullName << endl;
}
*/

// #7

/*
int ReadNumber()
{
    int Num;
    cout << "Enter a Number : ";
    cin >> Num;
    return Num;
}

float CalculateHalfNumber(int Num)
{
    return (float)Num / 2;
}

void PrintResult(int Num)
{
    string Result = "Half Number " + to_string(Num) + " is " + to_string(CalculateHalfNumber(Num));
    cout << Result << endl;
}
*/

// #8
/*
enum enPassFail { Pass = 1, Fail = 2 };

int ReadMark()
{
    int Mark;
    cout << "Enter Your Mark: " << endl;
    cin >> Mark;
    return Mark;
}

enPassFail CheckMark(int Mark) {
    if (Mark >= 50)
        return enPassFail::Pass;
    else
        return  enPassFail::Fail;
}

void PrintResult(int Mark)
{
    if (CheckMark(Mark) == enPassFail::Pass)
        cout << "Pass";
    else
        cout << "Fail";
}
*/

// #9

/*

void ReadNumbers(int& Num1, int& Num2, int& Num3) {
    cout << "Enter Number 1 : \n";
    cin >> Num1;
    cout << "Enter Number 2 : \n";
    cin >> Num2; 
    cout << "Enter Number 3 : \n";
    cin >> Num3;
}

*/
int SumOf3Numbers(int Num1, int Num2, int Num3)
{
    return Num1 + Num2 + Num3;
    
}

void PrintResults(int Total)
{
    cout << "The Total sum of Numbers is: " <<  Total << endl;
}

// #10

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
    return (float)SumOf3Numbers(Mark1 , Mark2 , Mark3) / 3;
}



void PrintAvrage(int Total)
{
    cout << "The Avrage of Marks is: " << Total << endl;
}


int main()
{
    // PrintFullName(GetFullName(ReadInfo(),true));
    //PrintResult(ReadNumber());
   // PrintResult(ReadMark());
    /*
    int Num1, Num2, Num3;
    ReadNumbers(Num1,Num2, Num3);
    PrintResults(SumOf3Numbers(Num1, Num2, Num3));
    */
    int Mark1, Mark2, Mark3;
    ReadMarks(Mark1, Mark2, Mark3);
    PrintAvrage(AvrageOf3Marks(Mark1, Mark2, Mark3));

}