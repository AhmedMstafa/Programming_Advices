#pragma once 
#include <iostream>
using namespace std;

class clsPerson
{
private:

	string _FirstName;
	string _LastName;
	string _Email;
	string _Phone;

public:

	clsPerson(string FirstName, string LastName, string Email, string Phone)
	{
		_FirstName = FirstName;
		_LastName = LastName;
		_Email = Email;
		_Phone = Phone;
	}

	string GetFirstName()
	{
		return _FirstName;
	}

	void SetFirstName(string FirstName)
	{
		_FirstName = FirstName;
	}

	__declspec(property(get = GetFirstName, put = SetFirstName)) string FirstName;

	string GetLastName()
	{
		return _LastName;
	}

	void SetLastName(string LastName)
	{
		_LastName = LastName;
	}

	__declspec(property(get = GetLastName, put = SetLastName)) string LastName;

	string GetEmail()
	{
		return _Email;
	}

	void SetEmail(string Email)
	{
		_Email = Email;
	}

	__declspec(property(get = GetEmail, put = SetEmail)) string Email;

	string GetPhone()
	{
		return _Phone;
	}

	void SetPhone(string Phone)
	{
		_Phone = Phone;
	}

	__declspec(property(get = GetPhone, put = SetPhone)) string Phone;

	string FullName()
	{
		return _FirstName + ' ' + _LastName;
	}


	void Print()
	{
		cout << "Person Info:\n\n";
		cout << "____________________________________\n\n";
		cout << "First Name : " << FirstName << '\n';
		cout << "Last Name  : " << LastName << '\n';
		cout << "Full Name  : " << FullName() << '\n';
		cout << "Email      : " << Email << '\n';
		cout << "Phone      : " << Phone << '\n';
		cout << "____________________________________\n";
		cout << endl;
	}

};