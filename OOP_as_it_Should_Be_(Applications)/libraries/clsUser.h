#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "clsPerson.h"
#include "clsString.h"
using namespace std;

class clsUser : public clsPerson
{

private:

	enum enMode { EmptyMode = 1, UpdateMode = 2, AddMode = 3 };
	enMode _Mode;
	string _UserName;
	string _Password;
	short  _Permissions;

	bool _MarkForDeleted = false;

	static clsUser _ConvertLineToUserObjec(string Line, string Separator = "#//#")
	{
		vector<string> vClient = clsString::Split(Line, Separator);
		return clsUser(enMode::UpdateMode, vClient[0], vClient[1], vClient[2], vClient[3], vClient[4], vClient[5], stoi(vClient[6]));
	}

	static string _ConvertObjectToLine(clsUser User, string Separator = "#//#")
	{
		string Line = "";

		Line += User.FirstName + Separator;
		Line += User.LastName + Separator;
		Line += User.Email + Separator;
		Line += User.Phone + Separator;

		Line += User.UserName() + Separator;
		Line += User.Password + Separator;
		Line += to_string(User.Permissions);

		return Line;
	}

	static clsUser _GetEmptyObject()
	{
		return clsUser(enMode::EmptyMode, "", "", "", "", "", "", 0);
	}

	static vector<clsUser> _LoadUserDataFromFile()
	{
		vector<clsUser> vUsers;
		fstream MyFile;

		MyFile.open("../../db/Users.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsUser Client = _ConvertLineToUserObjec(Line);
				vUsers.push_back(Client);
			}
			MyFile.close();
		}

		return vUsers;
	}

	static void _SaveDataToFile(vector<clsUser> vUsers)
	{
		fstream MyFile;

		MyFile.open("../../db/Users.txt", ios::out);

		if (MyFile.is_open())
		{
			for (clsUser User : vUsers)
			{
				string Line;
				if (User._MarkForDeleted == false)
				{
					Line = _ConvertObjectToLine(User);
					MyFile << Line << endl;
				}
			}
			MyFile.close();
		}

	}

	void _AddDataLineToFile(string Line)
	{
		fstream MyFile;
		MyFile.open("../../db/Users.txt", ios::app);

		if (MyFile.is_open())
		{
			MyFile << Line << endl;

			MyFile.close();
		}
	}

	void _Update()
	{
		vector<clsUser> vUsers = _LoadUserDataFromFile();

		for (clsUser& User : vUsers)
		{
			if (User.UserName() == _UserName)
			{
				User = *this;
				break;
			}
		}
		_SaveDataToFile(vUsers);
	}

	void _AddNew()
	{
		_AddDataLineToFile(_ConvertObjectToLine(*this));
	}

public:

	clsUser(enMode Mode, string FirstName, string LastName, string Email,
		string Phone, string UserName, string Password, short Permissions)
		: clsPerson(FirstName, LastName, Email, Phone)
	{
		_Mode = Mode;
		_UserName = UserName;
		_Password = Password;
		_Permissions = Permissions;
	}

	string UserName()
	{
		return _UserName;
	}

	string GetPassword()
	{
		return _Password;
	}

	void SetPassword(string Password)
	{
		_Password = Password;
	}

	__declspec(property(get = GetPassword, put = SetPassword)) string Password;

	short GetPermissions()
	{
		return _Permissions;
	}

	void SetPermissions(short Permissions)
	{
		_Permissions = Permissions;
	}

	__declspec(property(get = GetPermissions, put = SetPermissions)) short Permissions;

	/*
	void Print()
	{
		cout << "\nClient Card:";
		cout << "\n________________________";
		cout << "\nFirst Name      : " << FirstName;
		cout << "\nLast Name       : " << LastName;
		cout << "\nFull Name       : " << FullName();
		cout << "\nEmail           : " << Email;
		cout << "\nPhone           : " << Phone;
		cout << "\nUser Name       : " << _UserName;
		cout << "\nPassword        : " << _Password;
		cout << "\nPermissions     : " << _Permissions;
		cout << "\n________________________\n";

		cout << endl;
	}
	*/

	bool IsEmpty()
	{
		return (_Mode == enMode::EmptyMode);
	}

	static bool IsUserExist(string UserName)
	{
		return !clsUser::Find(UserName).IsEmpty();
	}

	static clsUser Find(string UserName)
	{
		fstream MyFile;
		MyFile.open("../../db/Users.txt", ios::in); // Read Mode

		if (MyFile.is_open())
		{
			string Line = "";
			while (getline(MyFile, Line))
			{
				clsUser User = _ConvertLineToUserObjec(Line);

				if (User.UserName() == UserName)
				{
					return User;
				}
			}
			MyFile.close();
		}

		return _GetEmptyObject();
	}

	static clsUser Find(string UserName, string Password)
	{
		fstream MyFile;
		MyFile.open("../../db/Users.txt", ios::in); // Read Mode

		if (MyFile.is_open())
		{
			string Line = "";
			while (getline(MyFile, Line))
			{
				clsUser User = _ConvertLineToUserObjec(Line);

				if (User.UserName() == UserName && User.Password == Password)
				{
					return User;
				}
			}
			MyFile.close();
		}

		return _GetEmptyObject();
	}

	static clsUser GetAddNewUserObjec(string UserName)
	{
		return clsUser(enMode::AddMode, "", "", "", "", UserName, "", 0);
	}

	bool Delete()
	{
		vector<clsUser> vUsers = _LoadUserDataFromFile();

		for (clsUser& User : vUsers)
		{
			if (User.UserName() == _UserName)
			{
				User._MarkForDeleted = true;
				break;
			}
		}

		_SaveDataToFile(vUsers);
		*this = _GetEmptyObject();
		return true;
	}

	enum enPermissions {eAll = -1, pListClients = 1, pAddNewClient = 2,pDeleteClient = 4, pUpdateClient = 8
		, pFindClient = 16, pTransactions = 32, pManageUsers = 64};

	static int ReadPermissionsToSet()
	{
		short Permissions = 0;
		char Answer = 'n';

		cout << "\nDo you want give full access? y/n? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
			return -1;

		cout << "\nDo you want to give access to : ";

		cout << "\nShow Client List y/n? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
			Permissions += enPermissions::pListClients;

		cout << "\nAdd New Clients ? y/n? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
			Permissions += enPermissions::pAddNewClient;

		cout << "\nDelete Client? y/n? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
			Permissions += enPermissions::pDeleteClient;

		cout << "\nUpdate Client? y/n? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
			Permissions += enPermissions::pUpdateClient;

		cout << "\nFind Client? y/n? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
			Permissions += enPermissions::pFindClient;

		cout << "\nTransaction Screen? y/n? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
			Permissions += enPermissions::pTransactions;

		cout << "\nManage Users Screen? y/n? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
			Permissions += enPermissions::pManageUsers;

		return Permissions;
	}

	static vector<clsUser> GetUsersList()
	{
		return _LoadUserDataFromFile();
	}

	bool CheckAccessPermission(enPermissions Permissions)
	{
		if (this->Permissions == enPermissions::eAll)
			return true;

		if ((this->Permissions & Permissions) == Permissions)
			return true;
		else
			return false;
	}

	enum enSaveResults { svSaveSucceded = 1, svFaildEmptyObject = 2, svFalidAccountNumberExists = 3 };

	enSaveResults Save()
	{
		switch (_Mode)
		{
		case clsUser::EmptyMode:

			return svFaildEmptyObject;

			break;
		case clsUser::UpdateMode:

			_Update();
			return svSaveSucceded;

			break;
		case clsUser::AddMode:

			if (clsUser::IsUserExist(_UserName))
			{
				return svFalidAccountNumberExists;
			}
			else
			{
				_AddNew();
				_Mode = enMode::UpdateMode;
				return svSaveSucceded;
			}

			break;
		}
	}

};