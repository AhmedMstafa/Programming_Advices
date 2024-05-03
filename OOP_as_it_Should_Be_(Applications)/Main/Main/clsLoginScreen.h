#include <iostream>
#include <fstream>
#include "clsScreen.h"
#include "clsMainScreen.h"
#include "clsInputValidate.h"
#include "Global.h"
#include "clsUser.h"
#include "clsDate.h"
#include "clsUtil.h"
#include <string>
using namespace std;

class clsLogin : protected clsScreen
{
private:

	static bool  _Login()
	{

		bool LoginFalid = false;
		string UserName, Password;
		short FaildLoginCount = 0;

		do
		{

			if (LoginFalid)
			{
				cout << "\nInvaled UserName/Password \n\n";
				FaildLoginCount++;
				cout << "\nYou have " << (3 - FaildLoginCount) << " Trails to login.\n";

				if (FaildLoginCount == 3)
				{
					cout << "\nYou are Loked after 3 falid trails\n\n";
					return false;
				}

			}

			cout << "\nEnter User Name: ";
			UserName = clsInputValidate::ReadString();

			cout << "\nEnter Password: ";
			Password = clsInputValidate::ReadString();

			CURRENT_USER = clsUser::Find(UserName, Password);

			LoginFalid = CURRENT_USER.IsEmpty();

		} while (LoginFalid);
		CURRENT_USER.RegisterLogin();
		clsMainScreen::ShowMainMenueScreen();
	}

public:

	static bool ShowLoginScreen()
	{
		_DrawScreenHeader("\t Login Screen");
		return _Login();
	}
};