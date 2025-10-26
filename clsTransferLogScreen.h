#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"

using namespace std;

class clsTransferLogScreen : clsScreen
{
	static void _PrintTransferLogRecordLine(clsBankClient::stTransferLogRecord& TransferLogRecord)
	{
		cout << setw(8) << left << "" << "| " << left << setw(26) << TransferLogRecord.DateTime;
		cout << "| " << left << setw(10) << TransferLogRecord.SourceAccountNumber;
		cout << "| " << left << setw(10) << TransferLogRecord.DestinationAccountNumber;
		cout << "| " << left << setw(10) << TransferLogRecord.Amount;
		cout << "| " << left << setw(10) << TransferLogRecord.SourceBalanceAfter;
		cout << "| " << left << setw(10) << TransferLogRecord.DestinationBalanceAfter;
		cout << "| " << left << setw(10) << TransferLogRecord.UserName;
	}

public:

	static void ShowTransferLogScreen()
	{
		vector <clsBankClient::stTransferLogRecord> vTransferLogRecord = clsBankClient::GetTransferLogList();

		string Title = "\tTransfer Log List Screen";
		string SubTitle = "\t    (" + to_string(vTransferLogRecord.size()) + ") Record(s).";

		_DrawScreenHeader(Title, SubTitle);

		cout << setw(8) << left << "" << "\n\t___________________________________________________________________________________________________\n\n";

		cout << setw(8) << left << "" << "| " << left << setw(26) << "Date/Time";
		cout << "| " << left << setw(10) << "s.Acct";
		cout << "| " << left << setw(10) << "d.Acct";
		cout << "| " << left << setw(10) << "Amount";
		cout << "| " << left << setw(10) << "s.Balance";
		cout << "| " << left << setw(10) << "d.Balance";
		cout << "| " << left << setw(10) << "User";

		cout << setw(8) << left << "" << "\n\t___________________________________________________________________________________________________\n\n";

		if (vTransferLogRecord.size() == 0)
		{
			cout << "\t\t\t\tNo Records Available in the System!";
		}
		else
		{
			for (clsBankClient::stTransferLogRecord& Record : vTransferLogRecord)
			{
				_PrintTransferLogRecordLine(Record);
				cout << "\n";
			}
		}

		cout << setw(8) << left << "" << "\n\t___________________________________________________________________________________________________\n\n";

	}
};

