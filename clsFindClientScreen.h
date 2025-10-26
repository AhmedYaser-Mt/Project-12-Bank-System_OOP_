#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"

using namespace std;

class clsFindClientScreen : clsScreen
{
    static void _PrintClient(clsBankClient& Client)
    {
        cout << "\nClient Card :";
        cout << "\n______________________________";
        cout << "\nFirst Name     : " << Client.FirstName;
        cout << "\nLast Name      : " << Client.LastName;
        cout << "\nFull Name      : " << Client.FullName();
        cout << "\nEmail          : " << Client.Email;
        cout << "\nPhone          : " << Client.Phone;
        cout << "\nAccount Number : " << Client.AccountNumber();
        cout << "\nPassword       : " << Client.PinCode;
        cout << "\nAcc. Balance   : " << Client.AccountBalance;
        cout << "\n______________________________\n";
    }

public:

	static void ShowFindClientScreen()
	{
        if (!_CheckAccessRights(clsUser::enPermissions::pFindClient))
        {
            return;  // this will exit the function and it will not continue
        }

		_DrawScreenHeader("\tFind Client Screen");

        string AccountNumber = "";

        cout << "\nPlease Enter Client Account Number : ";
        AccountNumber = clsInputValidate::ReadString();

        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nAccount Number is not found, choose another one : ";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient Client1 = clsBankClient::Find(AccountNumber);

        if (!Client1.IsEmpty())
        {
            cout << "\nClient Found :-)\n";
        }
        else
        {
            cout << "\nClient was not Found :-(\n";
        }

        _PrintClient(Client1);
	}
};

