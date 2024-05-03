#pragma once 
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsListUsersScreen.h"
#include "clsAddNewUserScreen.h"
#include "clsDeleteUserScreen.h"
#include "clsUpdateUserScreen.h"
#include "clsFindUserScreen.h"

using namespace std;

class clsManageUsers : protected clsScreen
{
private:

	enum enManageUserMenueOptions
	{
		eListUsers = 1, eAddNewUser = 2, eDeleteUser = 3, eUpdateUser = 4,
		eFindUser = 5, eMainMenue = 7
	};

	static short _ReadMangeUsersOption()
	{
		cout << setw(37) << "" << "Choose What do you want to do [1 to 6]: ";
		short Choice = clsInputValidate::ReadNumberBetween<short>(1, 6, "Please Enter Number between 1 to 6: ");
		return Choice;
	}

	static void _GoBackToManageUsersMenue()
	{
		cout << "\n\nPress Any Key To Go Main Menue..";
		system("pause>0");
		ShowManageUsersMenue();
	}

	static void _ShowAllUsersScreen()
	{
		//cout << "\nAll Users List Will Be Here.";
		clsListUsers::ShowUsersList();
	}

	static void _ShowAddUsersScreen()
	{
		//cout << "\nAdd Users Screen Will Be Here.";
		clsAddUsers::ShowAddUsers();
	}

	static void _ShowDeleteUserScreen()
	{
		//cout << "\nDelete User Screen Will Be Here.";
		clsDeleteUser::ShowDeleteUser();
	}

	static void _ShowUpdateUserScreen()
	{
		//cout << "\nUpdate User Screen Will Be Here.";
		clsUpdateUser::ShowUpdateUser();
	}

	static void _ShowFindUserScreen()
	{
		//cout << "\nFind User Screen Will Be Here.";
		clsFindUser::ShowFindUser();
	}

	static void _PerformManageUsersScreen(enManageUserMenueOptions UserMenueOption)
	{
		switch (UserMenueOption)
		{
		case enManageUserMenueOptions::eListUsers:
			system("cls");
			_ShowAllUsersScreen();
			_GoBackToManageUsersMenue();
			break;
		case enManageUserMenueOptions::eAddNewUser:
			system("cls");
			_ShowAddUsersScreen();
			_GoBackToManageUsersMenue();
			break;
		case enManageUserMenueOptions::eDeleteUser:
			system("cls");
			_ShowDeleteUserScreen();
			_GoBackToManageUsersMenue();
			break;
		case enManageUserMenueOptions::eUpdateUser:
			system("cls");
			_ShowUpdateUserScreen();
			_GoBackToManageUsersMenue();
			break;
		case enManageUserMenueOptions::eFindUser:
			system("cls");
			_ShowFindUserScreen();
			_GoBackToManageUsersMenue();
			break;
		case enManageUserMenueOptions::eMainMenue:
		{
			// Main Menue Will Be Handeled >_*
		}
		}
	}

public:

	static void ShowManageUsersMenue()
	{
		if (!CheckAccessRights(clsUser::enPermissions::pManageUsers))
		{
			return;
		}

		system("cls");

		_DrawScreenHeader("\t Manage Users Screen");

		cout << setw(37) << "" << "=========================================\n";
		cout << setw(37) << "" << "\t\t Manage Users Menue \n";
		cout << setw(37) << "" << "=========================================\n";
		cout << setw(37) << "" << "\t[1] List Users.\n";
		cout << setw(37) << "" << "\t[2] Add Users.\n";
		cout << setw(37) << "" << "\t[3] Delete User.\n";
		cout << setw(37) << "" << "\t[4] Update User.\n";
		cout << setw(37) << "" << "\t[5] Find User.\n";
		cout << setw(37) << "" << "\t[6] Main Menue.\n";
		cout << setw(37) << "" << "=========================================\n";

		_PerformManageUsersScreen((enManageUserMenueOptions)_ReadMangeUsersOption());
	}

};