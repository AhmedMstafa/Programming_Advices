#pragma once
#include <iostream>
#include "clsInputValidate.h"
#include "clsBankClient.h"
#include "clsScreen.h"
using namespace std;

class clsAddNewClient : protected clsScreen
{

private:

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
	static void ShowAddNewClientsScreen()
	{
		if (!CheckAccessRights(clsUser::enPermissions::pAddNewClient))
		{
			return;
		}

		_DrawScreenHeader("\t  Add New Clients");

		string AccountNumber = "";

		cout << "\nPlease Enter Account Number: ";
		AccountNumber = clsInputValidate::ReadString();
		while (clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nAccount Number Is Already Exist Used, Choose another one: ";
			AccountNumber = clsInputValidate::ReadString();
		}

		clsBankClient Client = clsBankClient::GetAddNewClientObject(AccountNumber);

		_ReadClientInfo(Client);

		clsBankClient::enSaveResults SaveResult;
		SaveResult = Client.Save();

		switch (SaveResult)
		{
		case clsBankClient::svSaveSucceded:
			cout << "\nClient Addeded Successfully :-)\n";
			_PrintClient(Client);
			break;
		case clsBankClient::svFaildEmptyObject:
			cout << "\nError account was not saved because it's Empty\n";
			break;
		case clsBankClient::svFalidAccountNumberExists:
			cout << "\nAccount Number is AlreadyExits\n";
			break;
		default:
			break;
		}

	}
};