#pragma once 
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"

class clsDeleteClient : protected clsScreen
{

protected:

	static void _Print(clsBankClient Client)
	{
		cout << "\nClient Card:";
		cout << "\n________________________";
		cout << "\nFirst Name      : " << Client.FirstName;
		cout << "\nLast Name       : " << Client.LastName;
		cout << "\nFull Name       : " << Client.FullName();
		cout << "\nEmail           : " << Client.Email;
		cout << "\nPhone           : " << Client.Phone;
		cout << "\nAccountNumber   : " << Client.AccountNumber();
		cout << "\nPassword        : " << Client.PinCode;
		cout << "\nAccount Balance : " << Client.AccountBalance;
		cout << "\n________________________\n";

		cout << endl;
	}

public:
	static void ShowDeleteClientScreen()
	{
		if (!CheckAccessRights(clsUser::enPermissions::pDeleteClient))
		{
			return;
		}
		_DrawScreenHeader("\tDelete Client Screen");

		cout << "\nPlease Enter Account Number: ";
		string AccountNumber = "";

		AccountNumber = clsInputValidate::ReadString();
		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nAccount Number is not found , choose another one: ";
			AccountNumber = clsInputValidate::ReadString();
		}

		clsBankClient Client = clsBankClient::Find(AccountNumber);

		_Print(Client);

		char Answer = 'n';

		cout << "\nAre you sure you want delete this client? y/n ? : ";
		cin >> Answer;

		if (Answer == 'y' || Answer == 'Y')
		{
			if (Client.Delete())
			{
				cout << "\nClient Deleted Successfully :-)\n";
				_Print(Client);
			}
			else
			{
				cout << "\nError Client Was not Deleted\n";
			}
		}

	}

};