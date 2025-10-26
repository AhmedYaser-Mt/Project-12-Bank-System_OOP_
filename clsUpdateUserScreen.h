#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include "clsInputValidate.h"
#include "clsUtil.h"
#include "Global.h"

using namespace std;

class clsUpdateUserScreen : protected clsScreen
{
	static void _ReadUserInfo(clsUser& User)
	{
		cout << "\nEnter FirstName : ";
		User.FirstName = clsInputValidate::ReadString();

		cout << "\nEnter LastName : ";
		User.LastName = clsInputValidate::ReadString();

		cout << "\nEnter Email : ";
		User.Email = clsInputValidate::ReadString();

		cout << "\nEnter Phone : ";
		User.Phone = clsInputValidate::ReadString();

		cout << "\nEnter Password : ";
		User.Password = clsInputValidate::ReadString();
		
		cout << "\nEnter Permissions : ";
		User.Permissions = _ReadPermissionsToSet();
	}

	static void _PrintUser(clsUser& User)
	{
		cout << "\nUser Card :";
		cout << "\n______________________________";
		cout << "\nFirst Name     : " << User.FirstName;
		cout << "\nLast Name      : " << User.LastName;
		cout << "\nFull Name      : " << User.FullName();
		cout << "\nEmail          : " << User.Email;
		cout << "\nPhone          : " << User.Phone;
		cout << "\nUser Name      : " << User.UserName;
		cout << "\nPassword       : " << User.Password;
		cout << "\nPermissions    : " << User.Permissions;
		cout << "\n______________________________\n";
	}

	static int _ReadPermissionsToSet()
	{
		int Permissions = 0;
		char Answer = 'N';

		cout << "\nDo you want to give full access ? Y/N? ";
		cin >> Answer;

		if (toupper(Answer) == 'Y')
		{
			return -1;
		}

		cout << "\nDo you want to give access to :\n";

		cout << "\nShow Client List ? Y/N? ";
		cin >> Answer;
		if (toupper(Answer) == 'Y')
		{
			Permissions += clsUser::enPermissions::pListClients;
		}

		cout << "\nAdd New Client ? Y/N? ";
		cin >> Answer;
		if (toupper(Answer) == 'Y')
		{
			Permissions += clsUser::enPermissions::pAddNewClient;
		}

		cout << "\nDelete Client ? Y/N? ";
		cin >> Answer;
		if (toupper(Answer) == 'Y')
		{
			Permissions += clsUser::enPermissions::pDeleteClient;
		}

		cout << "\nUpdate Client ? Y/N? ";
		cin >> Answer;
		if (toupper(Answer) == 'Y')
		{
			Permissions += clsUser::enPermissions::pUpdateClient;
		}

		cout << "\nFind Client ? Y/N? ";
		cin >> Answer;
		if (toupper(Answer) == 'Y')
		{
			Permissions += clsUser::enPermissions::pFindClient;
		}

		cout << "\nTransactions ? Y/N? ";
		cin >> Answer;
		if (toupper(Answer) == 'Y')
		{
			Permissions += clsUser::enPermissions::pTransactions;
		}

		cout << "\nManage Users ? Y/N? ";
		cin >> Answer;
		if (toupper(Answer) == 'Y')
		{
			Permissions += clsUser::enPermissions::pManageUsers;
		}

		cout << "\nShow Login Register ? Y/N? ";
		cin >> Answer;
		if (toupper(Answer) == 'Y')
		{
			Permissions += clsUser::enPermissions::pShowLoginRegister;
		}

		return Permissions;

	}

public:

	static void ShowUpdateUserScreen()
	{
		_DrawScreenHeader("\t Update User Screen");

		string UseName = "";

		cout << "\nPlease Enter UserName : ";
		UseName = clsInputValidate::ReadString();

		while (!clsUser::IsUserExist(UseName))
		{
			cout << "\nUser was not found, choose another one : ";
			UseName = clsInputValidate::ReadString();
		}

		clsUser User1 = clsUser::Find(UseName);
		_PrintUser(User1);

		cout << "\nAre you sure you want to update this User y/n? ";
		char Answer = 'n';
		cin >> Answer;

		if (Answer == 'Y' || Answer == 'y')
		{
			cout << "\n\nUpdate User Info:";
			cout << "\n____________________\n";

			_ReadUserInfo(User1);

			clsUser::enSaveResults SaveResult;
			SaveResult = User1.Save();

			switch (SaveResult)
			{
			case clsUser::svFailedEmptyObject:

				cout << "\nError User was not saved because it's Empty";
				break;

			case clsUser::svSucceeded:

				cout << "\nUser Updated Successfully :-)\n";
				_PrintUser(User1);
				break;
			}
		}
	}
};

