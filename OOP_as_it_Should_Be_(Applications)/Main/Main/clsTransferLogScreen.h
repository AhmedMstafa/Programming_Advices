#pragma once
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include "clsScreen.h"
#include "clsBankClient.h"

class clsTransferLogScreen : protected clsScreen
{
private:

	static void _PrintRecordLine(clsBankClient::stTransferLogRecord TransferLog)
	{
		cout << setw(8) << left << "" << "| " << setw(23) << TransferLog.DateTime;
		cout << "| " << setw(8) << TransferLog.SourceAccountNumber;
		cout << "| " << setw(8) << TransferLog.DestinationAccountNumber;
		cout << "| " << setw(8) << TransferLog.Amount;
		cout << "| " << setw(10) << TransferLog.SrcBalaceAfter;
		cout << "| " << setw(10) << TransferLog.desBalanceAfter;
		cout << "| " << setw(8) << TransferLog.UserName;

	}

public:
	static void ShowTransFferLogScreen()
	{
		vector<clsBankClient::stTransferLogRecord> vTransferLogs = clsBankClient::GetTransferLogList();

		string Title = "\tTransfer Log List Screen";
		string SubTitle = "\t   (" + to_string(vTransferLogs.size()) + ") Record(s).";

		_DrawScreenHeader(Title, SubTitle);

		cout << setw(8) << left << "" << "\n\t_________________________________________________";
		cout << "____________________________________________________\n" << endl;
		cout << setw(8) << left << "" << "| " << setw(23) << "Date/Time";
		cout << "| " << setw(8) << "s.Acct";
		cout << "| " << setw(8) << "d.Acct";
		cout << "| " << setw(8) << "Amount";
		cout << "| " << setw(10) << "s.Balance";
		cout << "| " << setw(10) << "d.Balance";
		cout << "| " << setw(8) << "User";
		cout << setw(8) << left << "" "\n\t_________________________________________________";
		cout << "____________________________________________________\n" << endl;

		if (vTransferLogs.size() == 0)
			cout << "\nNo Logs yet in system";
		else
			for (clsBankClient::stTransferLogRecord T : vTransferLogs)
			{
				_PrintRecordLine(T);
				cout << endl;
			}
		cout << setw(8) << left << "" "\n\t_________________________________________________";
		cout << "____________________________________________________\n" << endl;

	}
};