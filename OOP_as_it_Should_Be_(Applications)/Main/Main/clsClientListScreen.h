#pragma once 
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsBankClient.h"
#include "clsUtil.h"

class clsListClients : protected clsScreen
{

private:

    static void _PrintClientRecordLine(clsBankClient Client)
    {

        cout << setw(8) << "" << "| " << setw(15) << left << Client.AccountNumber();
        cout << "| " << setw(20) << left << Client.FullName();
        cout << "| " << setw(12) << left << Client.Phone;
        cout << "| " << setw(20) << left << Client.Email;
        cout << "| " << setw(10) << left << Client.PinCode;
        cout << "| " << setw(12) << left << Client.AccountBalance;

    }

public:
    static void ShowClientsScreen()
    {
        if (!CheckAccessRights(clsUser::enPermissions::pListClients))
        {
            return;
        }
        vector<clsBankClient> vClients = clsBankClient::GetClientsList();

        string Title = "\t Clients List Screen";
        string SubTitel = "\t   (" + to_string(vClients.size()) + ") Client(s).";

        _DrawScreenHeader(Title, SubTitel);
        cout << setw(8) << "" << "_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << setw(8) << "" << "| " << left << setw(15) << "Accout Number";
        cout << "| " << left << setw(20) << "Client Name";
        cout << "| " << left << setw(12) << "Phone";
        cout << "| " << left << setw(20) << "Email";
        cout << "| " << left << setw(10) << "Pin Code";
        cout << "| " << left << setw(12) << "Balance";
        cout << endl << setw(8) << "" << "_______________________________________________________";
        cout << "_________________________________________\n" << endl;


        double TotalBalances = clsBankClient::GetTotalBalances();

        if (vClients.size() == 0)
            cout << "\t\t\t\tNo Clients Available In the System!";
        else

            for (clsBankClient Client : vClients)
            {

                _PrintClientRecordLine(Client);
                cout << endl;
            }

        cout << setw(8) << "" << "_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << "\t\t\t\t\t Total Balances = " << TotalBalances << endl;
        cout << "\t\t\t\t\t    (" << clsUtil::NumberToText(TotalBalances) << endl;

    }
};