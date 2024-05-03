#pragma once
#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include "clsScreen.h"
#include "clsUser.h"

class clsListUsers : protected clsScreen
{

private:

	static void _PrintUserLineRecord(clsUser User)
	{

		cout << setw(8) << left << "" << "| " << setw(12) << left << User.UserName;
		cout << "| " << setw(25) << left << User.FullName();
		cout << "| " << setw(12) << left << User.Phone;
		cout << "| " << setw(20) << left << User.Email;
		cout << "| " << setw(10) << left << User.Password;
		cout << "| " << setw(12) << left << User.Permissions;


	}

public:

	static void ShowUsersList()
	{
		vector<clsUser> vUsers = clsUser::GetUsersList();

		string Title = "\t  User List Screen";
		string SubTitle = "\t   (" + to_string(vUsers.size()) + ") User(s).";

		_DrawScreenHeader(Title, SubTitle);

		cout << setw(8) << left << "" << "\n\t____________________________________________________" <<
			"__________________________________________________" << endl;
		cout << setw(8) << left << "" << "| " << setw(12) << left << "User Name";
		cout << "| " << setw(25) << left << "Full Name";
		cout << "| " << setw(12) << left << "Phone";
		cout << "| " << setw(20) << left << "Email";
		cout << "| " << setw(10) << left << "Password";
		cout << "| " << setw(12) << left << "Permissions";
		cout << setw(8) << left << "" << "\n\t____________________________________________________" <<
			"__________________________________________________" << endl;

		if (vUsers.size() == 0)
			cout << "\nNo Users Available In The System! \n";
		else
			for (clsUser User : vUsers)
			{
				_PrintUserLineRecord(User);
				cout << endl;
			}

		cout << setw(8) << left << "" << "\n\t____________________________________________________" <<
			"__________________________________________________" << endl;
	}
};