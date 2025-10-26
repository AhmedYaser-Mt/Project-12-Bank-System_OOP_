#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"

using namespace std;

class clsDepositScreen : protected clsScreen
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

    static void ShowDepositScreen()
    {
        system("cls");
        _DrawScreenHeader("\t  Deposit Screen");

        string AccountNumber = _ReadAccountNumber();

        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nClient with [" << AccountNumber << "] does not exist!\n";
            AccountNumber = _ReadAccountNumber();
        }

        clsBankClient Client1 = clsBankClient::Find(AccountNumber);
        _PrintClient(Client1);

        cout << "\nPlease Enter Deposite Amount ? ";
        double Amount = clsInputValidate::ReadDblNumber();

        cout << "\nAre you sure you want to Perform this Transaction?  Y/N? ";
        char Answer = 'n';
        cin >> Answer;

        if (Answer == 'Y' || Answer == 'y')
        {
            Client1.Deposite(Amount);
            cout << "\nAmount Deposited Successfully.\n";
            cout << "\nNew Balance is : " << Client1.AccountBalance << endl;
        }
        else
        {
            cout << "\nOperation was Cancelled!\n";
        }
    }
};