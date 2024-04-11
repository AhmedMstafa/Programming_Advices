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
        return FirstName + LastName;
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
    void SendEmail(string Subject,string Body) 
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

    __declspec(property(get = GetFirstName, put = SetFirstName)) string FirstName;
    __declspec(property(get = GetLastName, put = SetLastName)) string LastName;
    __declspec(property(get = GetEmail, put = SetEmail)) string Email;
    __declspec(property(get = GetPhone, put = SetPhoneNumber)) string Phone;
};

int main()
{
    clsPerson Person1(10, "Ahmed", "Mostafa", "Ahmed.Mostafa.mail.1@gmil.com", "01060600100");
    Person1.Print();

    Person1.SendEmail("Hi", "How are you?");
    Person1.SendSMS("How are you?");
    return 0;
}
