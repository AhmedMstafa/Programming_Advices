// Variables.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
int main()
{
    /*
    int myNumber;
    myNumber = 32;
    float myFloatNumber = 7.84;
    double myDoubelNumber = 21.89822;
    char myLetter = 'M';
    string myText = "Mohamed";
    bool myBoolean = true;
     
    cout << myNumber << endl;
    cout << myFloatNumber << endl;
    cout << myDoubelNumber << endl;
    cout << myLetter << endl;
    cout << myText << endl;
    cout << myBoolean << endl;

    int x = 4, y = 10, sum = x + y;
    cout << sum; 
    */

                              // Home Work 1//
    /*
    Age = yes 
    My-Age = No => special characters 
    My_Age = yes
    _Age = yes
    2x = No  => Strat With Number
    X2 = Yes
    My Name = No => Whitespaces
    MyName = Yes
    #Name = No => special characters 
    $Name = No => special characters 
    int = No => Reserved Words
    float = No => Reserved Words
    */
    string Stars = "**************************\n";
    string Name = "Ahemd Mostafa Mansour";
    int Age = 44;
    string City = "Asuit", Country = "Egypt";
    int Monthly_Salary = 5000, Yearly_Salary = 600000;
    char Gender = 'M';
    bool Married = true;
    cout << Stars;
    cout << "Name: " << Name << "\n";
    cout << "Age: " << Age << " Years\n";
    cout << "City: " << City << "\n";
    cout << "Country: " << Country << "\n";
    cout << "Monthly Salary: " << Monthly_Salary << "\n";
    cout << "Yealy Salary: " << Yearly_Salary << "\n";
    cout << "Gender: " << Gender << "\n";
    cout << "Married: " << Married << "\n";
    cout << Stars;
    // Home Work 2//
    int FirstNumber = 20, SecondNumber = 30, LastNumber = 10, Total = 60;
    string Line = "\n*************************\n\n";
    
    cout << FirstNumber << " +\n";
    cout << SecondNumber << " +\n";
    cout << LastNumber << "\n";
    cout << Line;
    cout << "Total = " << Total << "\n\n";

    // Home Work 3//
    int myAge = 25;
    cout << "After 5 Years you will be " << myAge + 5 << " years old\n";
    return 0;
}

