#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"

using namespace std;

class clsLoginRegisterScreen : protected clsScreen
{
	static void _PrintLoginRegisterRecordLine(clsUser::stLoginRegisterRecord& LoginRegisterRecord)
	{
		cout << setw(8) << left << "" << "| " << left << setw(35) << LoginRegisterRecord.DateTime;
		cout << "| " << left << setw(20) << LoginRegisterRecord.UserName;
		cout << "| " << left << setw(20) << LoginRegisterRecord.Password;
		cout << "| " << left << setw(10) << LoginRegisterRecord.Permissions;
	}

public:

	static void ShowLoginRegisterScreen()
	{
		if (!_CheckAccessRights(clsUser::enPermissions::pShowLoginRegister))
		{
			return;  // this will exit the function and it will not continue
		}

		vector <clsUser::stLoginRegisterRecord> vLoginRegisterRecord = clsUser::GetLoginRegisterList();

		string Title = "\tLogin Register List Screen";
		string SubTitle = "\t\t(" + to_string(vLoginRegisterRecord.size()) + ") Record(s).";

		_DrawScreenHeader(Title, SubTitle);

		cout << setw(8) << left << "" << "\n\t___________________________________________________________________________________________________\n\n";

		cout << setw(8) << left << "" << "| " << left << setw(35) << "Date/Time";
		cout << "| " << left << setw(20) << "UserName";
		cout << "| " << left << setw(20) << "Password";
		cout << "| " << left << setw(10) << "Permissions";

		cout << setw(8) << left << "" << "\n\t___________________________________________________________________________________________________\n\n";
		
		if (vLoginRegisterRecord.size() == 0)
		{
			cout << "\t\t\t\tNo Records Available in the System!";
		}
		else
		{
			for (clsUser::stLoginRegisterRecord& Record : vLoginRegisterRecord)
			{
				_PrintLoginRegisterRecordLine(Record);
				cout << "\n";
			}
		}

		cout << setw(8) << left << "" << "\n\t___________________________________________________________________________________________________\n\n";
	}
};

