#pragma once
#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include "clsUser.h"
#include "clsScreen.h"

class clsLoginRegisterScreen : protected clsScreen
{
private:
	static void _PrintLoginRegisterRecordLine(clsUser::stLoginRegisterRecord LoginRegister)
	{
		cout << setw(8) << left << "" << "| " << setw(35) << left << LoginRegister.DateAndTime;
		cout << "| " << setw(20) << left << LoginRegister.UserName;
		cout << "| " << setw(20) << left << LoginRegister.Password;
		cout << "| " << setw(10) << left << LoginRegister.Permissions;

	}

public:
	static void ShowLoginRegisterScreen()
	{
		if (!CheckAccessRights(clsUser::enPermissions::pShowLoginRegister))
		{
			return;
		}

		vector<clsUser::stLoginRegisterRecord> vLoginRegisterRecord = clsUser::GetLoginRegisterList();

		string Title = "\tLogin Register List Screen";
		string SubTitle = "\t(" + to_string(vLoginRegisterRecord.size()) + ") Register(s)";

		_DrawScreenHeader(Title, SubTitle);

		cout << setw(8) << left << "" << "\n\t___________________________________________________";
		cout << "___________________________________________________\n" << endl;
		cout << setw(8) << left << "" << "| " << left << setw(35) << "Date And Time";
		cout << "| " << setw(20) << left << "UserName";
		cout << "| " << setw(20) << left << "Password";
		cout << "| " << setw(10) << left << "Permissions\n";
		cout << setw(8) << left << "" << "\n\t___________________________________________________";
		cout << "___________________________________________________\n" << endl;

		if (vLoginRegisterRecord.size() == 0)
			cout << setw(8) << "" << "No Login Register In The System !\n";
		else
			for (clsUser::stLoginRegisterRecord LoginRegister : vLoginRegisterRecord)
			{
				_PrintLoginRegisterRecordLine(LoginRegister);
				cout << endl;
			}

		cout << setw(8) << left << "" << "\n\t___________________________________________________";
		cout << "___________________________________________________\n" << endl;

	}
};