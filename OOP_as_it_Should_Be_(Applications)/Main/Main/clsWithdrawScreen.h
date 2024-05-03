#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsBankClient.h"
using namespace std;

class clsWithdraw : protected clsScreen
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

public:

	static void ShowWithdrawScreen()
	{

		_DrawScreenHeader("\t Deposti Screen");

		cout << "\nPlease Enter Account Number: ";
		string AccountNumber = "";
		AccountNumber = clsInputValidate::ReadString();
		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nClient with [" << AccountNumber << "] does not exsit.";
			cout << "\nPlease Enter Account Number: ";
			AccountNumber = clsInputValidate::ReadString();
		}

		clsBankClient Client = clsBankClient::Find(AccountNumber);

		_Print(Client);

		double Amount = 0;
		cout << "\nPlease enter withdraw amount: ";
		Amount = clsInputValidate::ReadNumber<double>();

		char Answer = 'n';
		cout << "Are you sure to perform this transaction? ? y/n?";
		cin >> Answer;

		if (Answer == 'y' || Answer == 'Y')
		{
			if (Client.Withdraw(Amount))
			{
				cout << "\nAmount Withdrawed Successfully.\n";
				cout << "\nNew Balance Is: " << Client.AccountBalance;
			}
			else
			{
				cout << "\nCannot withdraw, Insufficient Balance!";

				cout << "\nAmount to withdraw is: " << Amount;
				cout << "\nYour Balance is: " << Client.AccountBalance;
			}
		}
		else
		{
			cout << "\nWithdraw was cancelled.\n";

		}
	}
};