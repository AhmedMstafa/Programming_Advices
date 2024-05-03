#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
using namespace std;

class clsTransferScreen : protected clsScreen
{
private:
	static void _PrintClient(clsBankClient Client)
	{
		cout << "\nClinet Card: ";
		cout << "\n_____________________";
		cout << "\n\nFullName     : " << Client.FullName();
		cout << "\nAcc. Number  : " << Client.AccountNumber();
		cout << "\nBalance      : " << Client.AccountBalance;
		cout << "\n_____________________\n";

	}

	static string _ReadAccountNumber(string Message)
	{
		cout << Message;
		string AccountNumber = clsInputValidate::ReadString();

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nAccount Not Found Enter Another One: ";
			string AccountNumber = clsInputValidate::ReadString();
		}

		return AccountNumber;
	}

	static float _ReadAmount(clsBankClient SourceClient)
	{
		float Amount = 0;
		cout << "\nEnter Transfer Amount? ";
		Amount = clsInputValidate::ReadNumber<double>();

		while (SourceClient.AccountBalance < Amount)
		{
			cout << "\nAmount Exceeds the available Balace, Enter another Amount? ";
			Amount = clsInputValidate::ReadNumber<double>();
		}

		return Amount;
	}

public:
	static void ShowTransferScreen()
	{
		_DrawScreenHeader("\t Transfer Screen");

		string S1 = "\nPlease Enter Account Number to Transfer From: ";
		clsBankClient SourceClient = clsBankClient::Find(_ReadAccountNumber(S1));
		_PrintClient(SourceClient);


		string S2 = "\nPlease Enter Account Number to Transfer To: ";
		clsBankClient DestinationClient = clsBankClient::Find(_ReadAccountNumber(S2));
		_PrintClient(DestinationClient);


		float Amount = _ReadAmount(SourceClient);

		char Answer = 'n';
		cout << "\nAre you sure you want to perform this Operation? y/n? ";
		cin >> Answer;

		if (Answer == 'y' || Answer == 'Y')
		{
			if (SourceClient.Transfer(Amount, DestinationClient)) {
				cout << "\nTransfer done Successfully.\n";
			}
			else
			{
				cout << "\nTransfer Falid.\n";
			}
		}

		_PrintClient(SourceClient);
		_PrintClient(DestinationClient);

	}
};
