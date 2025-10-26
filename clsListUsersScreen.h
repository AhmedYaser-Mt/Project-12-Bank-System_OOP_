#pragma once
#include <iostream>
#include <iomanip>
#include <vector>
#include "clsScreen.h"
#include "clsUser.h"
#include "clsUtil.h"

using namespace std;

class clsListUsersScreen : protected clsScreen
{
    static void _PrintUserRecordLine(clsUser& User)
    {
        cout << setw(8) << left << "" << "| " << left << setw(12) << User.UserName;
        cout << "| " << left << setw(25) << User.FullName();
        cout << "| " << left << setw(12) << User.Phone;
        cout << "| " << left << setw(20) << User.Email;
        cout << "| " << left << setw(10) << User.Password;
        cout << "| " << left << setw(12) << User.Permissions;
    }

public:

	static void ShowUsersList()
	{
        vector <clsUser> vUsers = clsUser::GetUsersList();

        string Title = "\t  User List Screen";
        string SubTitle = "\t   (" + to_string(vUsers.size()) + ") User(s).";

        _DrawScreenHeader(Title, SubTitle);


        cout << setw(8) << left << "" << "\n\t______________________________________________________________________________________________________\n\n";

        cout << setw(8) << left << "" << "| " << left << setw(12) << "UserName";
        cout << "| " << left << setw(25) << "Full Name";
        cout << "| " << left << setw(12) << "Phone";
        cout << "| " << left << setw(20) << "Email";
        cout << "| " << left << setw(10) << "Password";
        cout << "| " << left << setw(12) << "Permissions";

        cout << setw(8) << left << "" << "\n\t______________________________________________________________________________________________________\n\n";

        if (vUsers.size() == 0)
        {
            cout << "\t\t\t\tNo Users Available in the System!";
        }
        else
        {
            for (clsUser& U : vUsers)
            {
                _PrintUserRecordLine(U);
                cout << "\n";
            }
        }

        cout << setw(8) << left << "" << "\n\t______________________________________________________________________________________________________\n\n";
	}
};

