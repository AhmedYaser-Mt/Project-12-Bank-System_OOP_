#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include "clsMainScreen.h"
#include "Global.h"

using namespace std;

class clsLoginScreen : protected clsScreen
{
	static void _Login()
	{
		bool LoginFailed = false;

		string UserName, Password;

		do
		{
			if (LoginFailed)
			{
				cout << "\nInvalid UserName/Password!\n\n";
			}

			cout << "Enter UserName ? ";
			cin >> UserName;

			cout << "Enter Password ? ";
			cin >> Password;

			CurrentUser = clsUser::Find(UserName, Password);

			LoginFailed = CurrentUser.IsEmpty();

		} while (LoginFailed);

		clsMainScreen::ShowMainMenue();
	}

public:

	static void ShowLoginScreen()
	{
		system("cls");
		_DrawScreenHeader("\t  Login Screen");
		_Login();
	}
};

