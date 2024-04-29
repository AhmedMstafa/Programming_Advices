#include <iostream>
#include "clsScreen.h"
#include "clsMainScreen.h"
#include "../clsInputValidate.h"
#include "../Global.h"
#include "../clsUser.h"
using namespace std;

class clsLogin : protected clsScreen
{
private:

	static void  _Login()
	{

		bool LoginFalid = false;
		string UserName ,Password;

		do 
		{
			if (LoginFalid)
				cout << "\nInvaled UserName/Password \n\n";

			cout << "\nEnter User Name: ";
			UserName = clsInputValidate::ReadString();

			cout << "\nEnter Password: ";
			Password = clsInputValidate::ReadString();

			CURRENT_USER = clsUser::Find(UserName, Password);

			LoginFalid = CURRENT_USER.IsEmpty();

		} while (LoginFalid);
		
		clsMainScreen::ShowMainMenueScreen();
	}

public:

	static void ShowLoginScreen()
	{
		_DrawScreenHeader("\t Login Screen");
		_Login();
	}
};