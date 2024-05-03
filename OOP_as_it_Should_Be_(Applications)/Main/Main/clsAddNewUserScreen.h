#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include "clsInputValidate.h"
using namespace std;

class clsAddUsers : protected clsScreen
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

	static void ShowAddUsers()
	{

		_DrawScreenHeader("\t Add User Screen");

		string UserName = "";
		cout << "\nPlease Enter UserName : ";
		UserName = clsInputValidate::ReadString();
		while (clsUser::IsUserExist(UserName))
		{
			cout << "\nUser Name Is Already Exist ,Enter Another One: ";
			UserName = clsInputValidate::ReadString();
		}

		clsUser User = clsUser::GetAddNewUserObjec(UserName);

		_ReadUserInfo(User);

		clsUser::enSaveResults SaveResult;

		SaveResult = User.Save();

		switch (SaveResult)
		{
		case clsUser::svSaveSucceded:
			cout << "\nUser Addeded Successfully. >_*\n";
			_PrintUser(User);
			break;
		case clsUser::svFaildEmptyObject:
			cout << "\nError User Was Not Saved Because It's Empty. >_<\n";
			break;
		case clsUser::svFalidAccountNumberExists:
			cout << "\nCannot Add User Because Is Already Exist. >_<\n";
			break;
		default:
			break;
		}

	}
};