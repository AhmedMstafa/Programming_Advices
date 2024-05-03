#pragma once
#include <iostream>
#include <vector>
#include <iomanip>
#include "clsBankClient.h"
#include "clsUtil.h"
#include "clsScreen.h"

using namespace std;

class clsTotalBalancesScreen : protected clsScreen
{
protected:

	static void _PrintClientBalance(clsBankClient Client)
	{
		cout << setw(35) << left << "";
		cout << "| " << setw(15) << Client.AccountNumber();
		cout << "| " << setw(20) << Client.FullName();
		cout << "| " << setw(10) << Client.AccountBalance;
		cout << "|";
	}

public:

	static void ShowTotalBalances()
	{

		vector<clsBankClient> vClients = clsBankClient::GetClientsList();

		string Title = "\t Clients List Screen";
		string SubTitle = "\t  (" + to_string(vClients.size()) + ") Client(s).";

		_DrawScreenHeader(Title, SubTitle);

		cout << setw(35) << left << "";
		cout << "----------------------------------------------------\n";

		cout << setw(35) << left << "";
		cout << "| " << setw(15) << "Account Number ";
		cout << "| " << setw(20) << "Client Name";
		cout << "| " << setw(10) << "Balance " << "|" << endl;;

		cout << setw(35) << left << "";
		cout << "----------------------------------------------------\n";

		double TotalBalance = clsBankClient::GetTotalBalances();

		if (vClients.size() == 0)
		{
			cout << setw(35) << left << "";
			cout << "| Not Clients Available In the System!\n";
		}
		else
		{

			for (clsBankClient C : vClients)
			{
				_PrintClientBalance(C);
				cout << endl;
			}

			cout << setw(35) << left << "";
			cout << "----------------------------------------------------\n";

			cout << setw(35) << left << "";
			cout << "|>> Total Balance : " << setw(45)
				<< TotalBalance << endl;

			cout << setw(35) << left << "";
			cout << "----------------------------------------------------\n";

			cout << setw(35) << left << "";
			cout << "|>> " << setw(45) << clsUtil::NumberToText(TotalBalance) << endl;

		}

		cout << setw(35) << left << "";
		cout << "----------------------------------------------------\n";

	}
};