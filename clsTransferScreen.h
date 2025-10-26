#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "Global.h"

using namespace std;

class clsTransferScreen : protected clsScreen
{
    static void _PrintClient(clsBankClient& Client)
    {
        cout << "\nClient Card :";
        cout << "\n______________________________";
        cout << "\nFull Name   : " << Client.FullName();
        cout << "\nAcc. Number : " << Client.AccountNumber();
        cout << "\nBalance     : " << Client.AccountBalance;
        cout << "\n______________________________\n";
    }

    static string _ReadAccountNumber(string Word)
    {
        cout << "\nPlease enter Account Number to Transfer " << Word << " : ";
        string AccountNumber = clsInputValidate::ReadString();

        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nAccount Number is not found, choose another one : ";
            AccountNumber = clsInputValidate::ReadString();
        }

        return AccountNumber;
    }

    static double _ReadAmount(clsBankClient& SourceClient)
    {
        cout << "\nPlease enter transfer Amount : ";
        double Amount = clsInputValidate::ReadDblNumber();

        while (Amount > SourceClient.AccountBalance)
        {
            cout << "\nAmount Exceeds the available Balance, Enter another Amount ? ";
            Amount = clsInputValidate::ReadDblNumber();
        }

        return Amount;
    }

public:

    static void ShowTransferScreen()
    {
        _DrawScreenHeader("\t  Transfer Screen");

        clsBankClient SourceClient = clsBankClient::Find(_ReadAccountNumber("from"));
        _PrintClient(SourceClient);

        clsBankClient DestinationClient = clsBankClient::Find(_ReadAccountNumber("to"));
        _PrintClient(DestinationClient);

        double Amount = _ReadAmount(SourceClient);

        cout << "\nAre you sure you want to Perform this Operation?  Y/N? ";
        char Answer = 'n';
        cin >> Answer;

        if (Answer == 'Y' || Answer == 'y')
        {
            if (SourceClient.Transfer(Amount, DestinationClient, CurrentUser.UserName))
            {
                cout << "\nTransfer done Successfully\n";

                _PrintClient(SourceClient);
                _PrintClient(DestinationClient);
            }
            else
            {
                cout << "\nTransfer Failed\n";
            }
        }
    }
};

