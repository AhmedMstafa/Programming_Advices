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

    clsPerson()
    {

    }

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
        return FirstName() + " " + LastName();
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
    int _Salary;
    string _Department;

public:

    void SetTitle(string Title)
    {
        _Title = Title;
    }

    string Title()
    {
        return _Title;
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



};


int main()
{
    clsEmployee Employee1;

    Employee1.SetFirstName("Ahemd");
    Employee1.SetLastName("Mostafa");
    Employee1.SetEmail("a@a.com");
    Employee1.SetSalary(1000);
    Employee1.SetPhoneNumber("01060600100");
    Employee1.Print();

    Employee1.SendEmail("Hi", "How Are You? ");
    Employee1.SendSMS("How Are You? ");


    return 0;
}