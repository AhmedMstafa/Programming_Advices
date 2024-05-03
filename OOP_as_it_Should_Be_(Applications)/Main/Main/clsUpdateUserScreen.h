#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include "clsInputValidate.h"
using namespace std;

class clsUpdateUser : protected clsScreen
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

	static void _ReadUserInfo(clsUser& User)
	{
		cout << "\nEnter First Name: ";
		User.FirstName = clsInputValidate::ReadString();
		cout << "\nEnter Last Name: ";
		User.LastName = clsInputValidate::ReadString();
		cout << "\nEnter Email: ";
		User.Email = clsInputValidate::ReadString();
		cout << "\nEnter Phone: ";
		User.Phone = clsInputValidate::ReadString();
		cout << "\nEnter Password: ";
		User.Password = clsInputValidate::ReadString();
		cout << "\nEnter Permissions: ";
		User.Permissions = clsUser::ReadPermissionsToSet();
	}

public:

	static void ShowUpdateUser()
	{
		_DrawScreenHeader("\t Update User Screen");

		cout << "\nPlease Enter UserName: ";
		string UserName = "";
		UserName = clsInputValidate::ReadString();
		while (!clsUser::IsUserExist(UserName))
		{
			cout << "\nUser Name not found, choose another one: ";
			UserName = clsInputValidate::ReadString();
		}

		clsUser User = clsUser::Find(UserName);

		_PrintUser(User);

		cout << "\nAre you sure you want to update this user y/n? ";
		char Answer = 'n';
		cin >> Answer;
		if (Answer == 'Y' || Answer == 'y')
		{
			cout << "\n\nUpdate User Info: ";
			cout << "\n__________________\n";
			_ReadUserInfo(User);

			clsUser::enSaveResults SaveResult;

			SaveResult = User.Save();

			switch (SaveResult)
			{
			case clsUser::svSaveSucceded:
				cout << "\nUser Updated Successfully :-)\n";
				_PrintUser(User);
				break;
			case clsUser::svFaildEmptyObject:
				cout << "\nFaild to update user because is empty :-(\n";

				break;
			}

		}
		else
		{
			cout << "\nUpdated User Was Be Canceld *_*\n";
		}

	}
};