#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsUtil.h"

using namespace std;

class clsTotalBalancesScreen : protected clsScreen
{
	static void _PrintClientRecordBalanceLine(clsBankClient& Client)
	{
		cout << setw(25) << left << "" << "| " << left << setw(16) << Client.AccountNumber();
		cout << "| " << left << setw(40) << Client.FullName();
		cout << "| " << left << setw(12) << Client.AccountBalance;
	}

public:

	static void ShowTotalBalances()
	{
		system("cls");

		vector <clsBankClient> vClients = clsBankClient::GetClientsList();

		string Title = "\t Balances List Screen";
		string SubTile = "\t   (" + to_string(vClients.size()) + ") Client(s).";

		_DrawScreenHeader(Title, SubTile);

		cout << setw(25) << left << "" << "\n\t\t_______________________________________________________";
		cout << "__________________________\n" << endl;

		cout << setw(25) << left << "" << "| " << left << setw(15) << "Accout Number";
		cout << "| " << left << setw(40) << "Client Name";
		cout << "| " << left << setw(12) << "Balance";

		cout << setw(25) << left << "" << "\t\t_______________________________________________________";
		cout << "__________________________\n" << endl;

		if (vClients.size() == 0)
		{
			cout << "\t\t\t\tNo Clients Available In the System!";
		}
		else
		{
			for (clsBankClient& Client : vClients)
			{
				_PrintClientRecordBalanceLine(Client);
				cout << endl;
			}
		}

		cout << setw(25) << left << "" << "\n\t\t_______________________________________________________";
		cout << "__________________________\n" << endl;

		double TotalBalances = clsBankClient::GetTotalBalances();

		cout << setw(8) << left << "" << "\t\t\t\t Total Balances = " << TotalBalances << endl;
		cout << setw(8) << left << "" << "\t\t\t\t ( " << clsUtil::NumberToText(TotalBalances) << " )";
	}
};

