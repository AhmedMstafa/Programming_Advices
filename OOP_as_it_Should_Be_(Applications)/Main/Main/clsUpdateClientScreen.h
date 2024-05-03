#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
using namespace std;

class clsUpdateClient : protected clsScreen
{

private:

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

	static void _ReadClientInfo(clsBankClient& Client)
	{
		cout << "\nEnter FirstName : ";
		Client.FirstName = clsInputValidate::ReadString();
		cout << "\nEnter LastName : ";
		Client.LastName = clsInputValidate::ReadString();
		cout << "\nEnter Email : ";
		Client.Email = clsInputValidate::ReadString();
		cout << "\nEnter Phone : ";
		Client.Phone = clsInputValidate::ReadString();
		cout << "\nEnter PinCode : ";
		Client.PinCode = clsInputValidate::ReadString();
		cout << "\nEnter Account Balance : ";
		Client.AccountBalance = clsInputValidate::ReadNumber<float>();
	}

public:

	static void ShowUpdateClientScreen()
	{
		if (!CheckAccessRights(clsUser::enPermissions::pUpdateClient))
		{
			return;
		}

		_DrawScreenHeader("\t Update Client Screen");

		string AccountNumber = "";

		cout << "\nPlease Enter Account Number : ";

		AccountNumber = clsInputValidate::ReadString();

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nAccount number is not found, choose another one: ";
			AccountNumber = clsInputValidate::ReadString();
		}

		clsBankClient Client = clsBankClient::Find(AccountNumber);

		_Print(Client);

		cout << "\nAre you soure you want to update this Client y/n? ";

		char Answer = 'n';
		cin >> Answer;

		if (Answer == 'y' || Answer == 'Y')
		{
			cout << "\n\nUpdate Client Info:";
			cout << "\n____________________\n";

			_ReadClientInfo(Client);


			clsBankClient::enSaveResults SaveResult;

			SaveResult = Client.Save();

			switch (SaveResult)
			{
			case clsBankClient::svSaveSucceded:
				cout << "\nAccount Updated Successfully.\n";
				_Print(Client);

				break;
			case clsBankClient::svFaildEmptyObject:
				cout << "\nError account was not saved because it's Empty\n";
				break;
			}

		}

	}

};