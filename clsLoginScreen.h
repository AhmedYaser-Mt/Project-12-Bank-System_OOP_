#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include "clsMainScreen.h"
#include "Global.h"

using namespace std;

class clsLoginScreen : protected clsScreen
{
	static bool _Login()
	{

		bool LoginFailed = false;
		short FailedLoginCount = 0;
		string UserName, Password;

		do
		{

			if (LoginFailed)
			{
				FailedLoginCount++;

				cout << "\nInvalid UserName/Password!\n";
				cout << "You have " << (3 - FailedLoginCount) << " Trail(s) to Login.\n\n";
			}

			if (FailedLoginCount == 3)
			{
				cout << "\nYou are Locked after 3 failed trails\n\n";
				return false;
			}

			cout << "Enter UserName ? ";
			cin >> UserName;

			cout << "Enter Password ? ";
			cin >> Password;

			CurrentUser = clsUser::Find(UserName, Password);

			LoginFailed = CurrentUser.IsEmpty();

		} while (LoginFailed);

		CurrentUser.RegisterLogIn();

		clsMainScreen::ShowMainMenue();
		return true;
	}

public:

	static bool ShowLoginScreen()
	{
		system("cls");
		_DrawScreenHeader("\t  Login Screen");
		return _Login();
	}
};

