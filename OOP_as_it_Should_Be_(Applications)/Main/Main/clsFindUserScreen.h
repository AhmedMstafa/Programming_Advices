#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include "clsInputValidate.h"
using namespace std;

class clsFindUser : protected clsScreen
{

private:
	static void _PrintUser(clsUser User)
	{
		cout << "\nClient Card:";
		cout << "\n________________________";
		cout << "\nFirst Name      : " << User.FirstName;
		cout << "\nLast Name       : " << User.LastName;
		cout << "\nFull Name       : " << User.FullName();
		cout << "\nEmail           : " << User.Email;
		cout << "\nPhone           : " << User.Phone;
		cout << "\nUser Name       : " << User.UserName;
		cout << "\nPassword        : " << User.Password;
		cout << "\nPermissions     : " << User.Permissions;
		cout << "\n________________________\n";
	}
public:

	static void ShowFindUser()
	{
		_DrawScreenHeader("\t Find User Screen");

		cout << "\nPlease Enter UserName: ";
		string UserName = "";
		UserName = clsInputValidate::ReadString();
		while (!clsUser::IsUserExist(UserName))
		{
			cout << "\nAccountNumber not found, choose another one: ";
			UserName = clsInputValidate::ReadString();

		}

		clsUser User = clsUser::Find(UserName);

		if (User.IsEmpty())
			cout << "\nUser Was Not Not Found :-(\n";
		else
			cout << "\nUser Found ^_^\n";

		_PrintUser(User);



	}
};