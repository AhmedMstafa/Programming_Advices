#include <iostream>
using namespace std;

class clsEmployee
{

private:
    int _ID;
    string _FirstName;
    string _LastName;
    string _Title;
    string _Email;
    string _Phone;
    int _Salary;
    string _Department;

public:
    clsEmployee(int ID, string FirstName, string LastName, string Title, string Email, string Phone, int Salary, string Department)
    {
        _ID = ID;
        _FirstName = FirstName;
        _LastName = LastName;
        _Title = Title;
        _Email = Email;
        _Phone = Phone;
        _Salary = Salary;
        _Department = Department;
    }

    int ID()
    {
        return _ID;
    }

    string FullName()
    {
        return _FirstName + _LastName;
    }

    void SetFirstName(string FirstName)
    {
        _FirstName = FirstName;
    }

    string FirstName()
    {
        return _FirstName;
    }

    void SetLastName(string LastName)
    {
        _LastName = LastName;
    }

    string LastName()
    {
        return _LastName;
    }

    void SetTitle(string Title)
    {
        _Title = Title;
    }

    string Title()
    {
        return _Title;
    }

    void SetEmail(string Email)
    {
        _Email = Email;
    }

    string Email()
    {
        return _Email;
    }

    void SetPhone(string Phone)
    {
        _Phone = Phone;
    }

    string Phone()
    {
        return _Phone;
    }

    void SetSalary(int Salary)
    {
        _Salary = Salary;
    }

    int Salary()
    {
        return _Salary;
    }

    void SetDepartment(string Department)
    {
        _Department = Department;
    }

    string Department()
    {
        return _Department;
    }

    void Print() 
    {
        cout << "\n_________________________\n\n";
        cout << "FirstName    : " << _FirstName << endl;
        cout << "LastName     : " << _LastName << endl;
        cout << "FullName     : " << FullName() << endl;
        cout << "Tiltle       : " << _Title << endl;
        cout << "Email        : " << _Email << endl;
        cout << "Phone        : " << _Phone << endl;
        cout << "Salary       : " << _Salary << endl;
        cout << "Department   : " << _Department << endl;
        cout << "_________________________" << endl;
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


int main()
{
    clsEmployee Employee1(10, "Ahmed", "Mostafa", "Salary Employee", "Ahmed@gmil.com", "01060600100", 1000, "xceed");

    Employee1.Print();

    Employee1.SendEmail("Hi", "How Are You? ");
    Employee1.SendSMS("How Are You? ");
    

    return 0;
}
