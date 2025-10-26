#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"

using namespace std;

class clsWithdrawScreen : protected clsScreen
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

    static string _ReadAccountNumber()
    {
        cout << "\nPlease Enter Account Number ? ";
        string AccountNumber = clsInputValidate::ReadString();
        return AccountNumber;
    }

public:

	static void ShowWithdrawScreen()
	{
        system("cls");
        _DrawScreenHeader("\t  Withdraw Screen");

        string AccountNumber = _ReadAccountNumber();

        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nClient with [" << AccountNumber << "] does not exist!\n";
            AccountNumber = _ReadAccountNumber();
        }

        clsBankClient Client1 = clsBankClient::Find(AccountNumber);
        _PrintClient(Client1);

        cout << "\nPlease Enter Withdraw Amount ? ";
        double Amount = clsInputValidate::ReadDblNumber();

        cout << "\nAre you sure you want to perform this Transaction ? Y/N? ";
        char Answer = 'n';
        cin >> Answer;

        if (Answer == 'Y' || Answer == 'y')
        {
            if (Client1.Withdraw(Amount))
            {
                cout << "\nAmount Withdrew Successfully.\n";
                cout << "\nNew Balance is : " << Client1.AccountBalance;
            }
            else
            {
                cout << "\nCannot Withdraw, Insuffecient Balance!\n";
                cout << "\nAmount to Withdraw is : " << Amount;
                cout << "\nYour Balance is : " << Client1.AccountBalance;
            }
        }
        else
        {
            cout << "\nOperation was Cancelled!\n";
        }
	}
};

