#pragma once
#include <iostream>
#include "clsPerson.h"
using namespace std;

class clsEmployee : public clsPerson
{

private:
    string _Title;
    string _Department;
    int _Salary;

public:

    clsEmployee(short Id, string FirstName, string LastName, string Email, string Phone, string Title, string Department, int Salary) :
        clsPerson(Id, FirstName, LastName, Email, Phone)
    {
        _Title = Title;
        _Department = Department;
        _Salary = Salary;
    }

    void SetTitle(string Title)
    {
        _Title = Title;
    }

    string GetTitle()
    {
        return _Title;
    }

    void SetSalary(int Salary)
    {
        _Salary = Salary;
    }

    int GetSalary()
    {
        return _Salary;
    }

    void SetDepartment(string Department)
    {
        _Department = Department;
    }

    string GetDepartment()
    {
        return _Department;
    }

    void Print()
    {
        //clsPerson::Print();
        cout << "\nInfo:";
        cout << "\n_________________________\n\n";
        cout << "ID    : " << ID() << endl;
        cout << "FirstName    : " << GetFirstName() << endl;
        cout << "LastName     : " << GetLastName() << endl;
        cout << "FullName     : " << FullName() << endl;
        cout << "Email        : " << GetEmail() << endl;
        cout << "Phone        : " << GetPhone() << endl;

        cout << "Tiltle       : " << _Title << endl;
        cout << "Department   : " << _Department << endl;
        cout << "Salary       : " << _Salary << endl;
        cout << "_________________________" << endl;
    }


};

