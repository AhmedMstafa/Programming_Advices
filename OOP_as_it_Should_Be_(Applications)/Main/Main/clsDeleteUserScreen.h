#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include "clsInputValidate.h"
using namespace std;

class clsDeleteUser : protected clsScreen
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

	static void ShowDeleteUser()
	{
		_DrawScreenHeader("\t Delete User Screen");

		string UserName = "";
		cout << "\nEnter UserName: ";
		UserName = clsInputValidate::ReadString();
		while (!clsUser::IsUserExist(UserName))
		{
			cout << "\nUser is not  found ,choose another one: ";
			UserName = clsInputValidate::ReadString();
		}
		clsUser User = clsUser::Find(UserName);

		_PrintUser(User);

		char Answer = 'n';
		cout << "\nAre you sure you want to delete this User? y/n? ";
		cin >> Answer;

		if (Answer == 'Y' || Answer == 'y')
		{

			if (User.Delete())
			{
				cout << "\nUser Deleted Successfully :-)\n";
				_PrintUser(User);
			}
			else
			{
				cout << "\nError User Was not Deleted :-(\n";
			}

		}
		else
		{
			cout << "\nUser Deleted Canceld *_*\n";
		}

	}
};