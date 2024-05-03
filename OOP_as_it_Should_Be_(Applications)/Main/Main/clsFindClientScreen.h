#pragma once
#include <iostream>
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsScreen.h"
using namespace std;

class clsFindClient : protected clsScreen
{
private:

	static void _PrintClient(clsBankClient Client)
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

	static void ShowFindClientScreen()
	{
		if (!CheckAccessRights(clsUser::enPermissions::pFindClient))
		{
			return;
		}
		_DrawScreenHeader("\t Find Client Screen");
		cout << "\nPlease Enter Account Number: ";
		string AccountNumber = "";
		AccountNumber = clsInputValidate::ReadString();
		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nAccount Number is not found , choose another one: ";
			AccountNumber = clsInputValidate::ReadString();
		}
		clsBankClient Client = clsBankClient::Find(AccountNumber);


		if (!Client.IsEmpty())
		{
			cout << "\nClient Found :-)\n";
		}
		else
		{
			cout << "\nClient Not Found :-(\n";
		}

		_PrintClient(Client);
	}
};