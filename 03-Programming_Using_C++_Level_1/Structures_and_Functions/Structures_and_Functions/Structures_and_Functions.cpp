
#include <iostream>
#include <string>
using namespace std;
// Home Work
struct strInfo {
    string Name,City,Country;
    int Age,MonthlySalary,YearlySalary;
    char Gender;
    bool Marride;
};

void ReadInfo(strInfo &Info) 
{
    cout << "Enter Yoru Name? \n";
    getline(cin, Info.Name);
    cout << "Enter Your Age? \n";
    cin >> Info.Age;
    cout << "Enter Your City? \n";
    cin >> Info.City;
    cout << "Enter Your Country? \n";
    cin >> Info.Country;
    cout << "Enter Your Monthly Salary? \n";
    cin >> Info.MonthlySalary;
    cout << "Enter Your Yearly Salary? \n";
    cin >> Info.YearlySalary;
    cout << "Enter Your Gender? \n";
    cin >> Info.Gender;
    cout << "Are You Marred? \n";
    cin >> Info.Marride;
}

void PrintInfo(strInfo &Info)
{
    cout << "\n************************\n";
    cout << "Name: " << Info.Name << endl;
    cout << "Age: " << Info.Age << endl;
    cout << "City: " << Info.City << endl;
    cout << "Country: " << Info.Country << endl;
    cout << "Monthly Salary: " << Info.MonthlySalary << endl;
    cout << "Yearly Salary: " << Info.YearlySalary << endl;
    cout << "Gender: " << Info.Gender << endl;
    cout << "Marred: " << Info.Marride;
    cout << "\n************************\n";
}

int main()
{
    strInfo Person1;
    ReadInfo(Person1);
    PrintInfo(Person1);


    return 0;
}

