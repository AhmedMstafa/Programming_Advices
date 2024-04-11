#include <iostream>
using namespace std;

class clsPerson
{

public:

    short _ID = 10;
    string _FirstName;
    string _LastName;
    string _Email;
    string _Phone;

public:

    clsPerson(short Id, string FirstName, string LastName, string Email, string Phone)
    {
        _ID = Id;
        _FirstName = FirstName;
        _LastName = LastName;
        _Email = Email;
        _Phone = Phone;

    }

    short ID()
    {
        return _ID;
    }

    void SetFirstName(string FirstName)
    {
        _FirstName = FirstName;
    }
    void SetLastName(string LastName)
    {
        _LastName = LastName;
    }
    void SetPhoneNumber(string Phone)
    {
        _Phone = Phone;
    }
    void SetEmail(string Email)
    {
        _Email = Email;
    }
    string GetFirstName()
    {
        return _FirstName;
    }
    string GetLastName()
    {
        return _LastName;
    }
    string GetPhone()
    {
        return _Phone;
    }
    string GetEmail()
    {
        return _Email;
    }
    string FullName()
    {
        return _FirstName + " " + _LastName;
    }
    void Print()
    {
        cout << "\nInfo: \n";
        cout << "\n_____________________________\n";
        cout << "FirstName: " << _FirstName << endl;
        cout << "LastName:  " << _LastName << endl;
        cout << "FullName:  " << FullName() << endl;
        cout << "Email:     " << _Email << endl;
        cout << "Phone:     " << _Phone << endl;
        cout << "_____________________________\n" << endl;


    }
    void SendEmail(string Subject, string Body)
    {
        cout << "\nThe following message sent successfully to email: " << _Email << endl;
        cout << "Subject: " << Subject << endl;
        cout << "Body: " << Body << endl;
    }

    void SendSMS(string TextMessage)
    {
        cout << "\nThe following SMS sent successfully to phone: " << _Phone << endl;
        cout << TextMessage << endl;
    }

};

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
        cout << "ID    : "<< ID() << endl;
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

class clsDeveloper : public clsEmployee
{
    string _MainProgrammingLanguage;

public:
    clsDeveloper(short Id, string FirstName, string LastName, string Email, string Phone, string Title, string Department, int Salary,string MainProgrammingLanguage) :
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
        cout << "ID           : " <<  ID() << endl;
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


int main()
{

    clsDeveloper Developer1(10, "Ahemd", "Moatafa", "A@a", "010005050", "Developer Title", "xceed", 1000, "C++");
    Developer1.Print();

    Developer1.SendSMS("Hi Developer :-)");

    return 0;
}