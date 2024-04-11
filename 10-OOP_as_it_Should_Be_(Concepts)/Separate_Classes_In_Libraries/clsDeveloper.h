#pragma once
#include <iostream>
#include "clsPerson.h"
#include "clsEmployee.h"
using namespace std;

class clsDeveloper : public clsEmployee
{
    string _MainProgrammingLanguage;

public:
    clsDeveloper(short Id, string FirstName, string LastName, string Email, string Phone, string Title, string Department, int Salary, string MainProgrammingLanguage) :
        clsEmployee(Id, FirstName, LastName, Email, Phone, Title, Department, Salary) {

        _MainProgrammingLanguage = MainProgrammingLanguage;
    }

    void SetMainProLang(string MainProLang)
    {
        _MainProgrammingLanguage = MainProLang;
    }

    string GetMainProLang()
    {
        return _MainProgrammingLanguage;
    }

    void Print()
    {
        //clsPerson::Print();
        cout << "\nInfo:";
        cout << "\n_________________________\n\n";
        cout << "ID           : " << ID() << endl;
        cout << "FirstName    : " << GetFirstName() << endl;
        cout << "LastName     : " << GetLastName() << endl;
        cout << "FullName     : " << FullName() << endl;
        cout << "Email        : " << GetEmail() << endl;
        cout << "Phone        : " << GetPhone() << endl;
        cout << "Tiltle       : " << GetTitle() << endl;
        cout << "Department   : " << GetDepartment() << endl;
        cout << "Salary       : " << GetSalary() << endl;

        cout << "Main Programming Language: " << GetMainProLang() << endl;
        cout << "_________________________" << endl;
    }

};

