#pragma once
#include <iostream>
#include <iomanip>
#include "clsBankClient.h"
#include "clsScreen.h"

using namespace std;

class clsClientListScreen : protected clsScreen
{
    static void _PrintClientRecordLine(clsBankClient& Client)
    {
        cout << setw(8) << left << "" << "| " << left << setw(16) << Client.AccountNumber();
        cout << "| " << left << setw(20) << Client.FullName();
        cout << "| " << left << setw(12) << Client.Phone;
        cout << "| " << left << setw(20) << Client.Email;
        cout << "| " << left << setw(10) << Client.PinCode;
        cout << "| " << left << setw(12) << Client.AccountBalance;
    }

public:

    static void ShowClientsList()
    {
        if (!_CheckAccessRights(clsUser::enPermissions::pListClients))
        {
            return;  // this will exit the function and it will not continue
        }

        vector <clsBankClient> vClients = clsBankClient::GetClientsList();

        string Title = "\t  Client List Screen";
        string SubTitle = "\t   (" + to_string(vClients.size()) + ") Client(s).";

        _DrawScreenHeader(Title, SubTitle);

        
        cout << setw(8) << left << "" << "\n\t___________________________________________________________________________________________________\n\n";

        cout << setw(8) << left << "" << "| " << left << setw(16) << "Account Number";
        cout << "| " << left << setw(20) << "Client Name";
        cout << "| " << left << setw(12) << "Phone";
        cout << "| " << left << setw(20) << "Email";
        cout << "| " << left << setw(10) << "Pin Code";
        cout << "| " << left << setw(12) << "Balance";

        cout << setw(8) << left << "" << "\n\t___________________________________________________________________________________________________\n\n";

        if (vClients.size() == 0)
        {
            cout << "\t\t\t\tNo Clients Available in the System!";
        }
        else
        {
            for (clsBankClient& C : vClients)
            {
                _PrintClientRecordLine(C);
                cout << "\n";
            }
        }

        cout << setw(8) << left << "" << "\n\t___________________________________________________________________________________________________\n\n";

    }
};

