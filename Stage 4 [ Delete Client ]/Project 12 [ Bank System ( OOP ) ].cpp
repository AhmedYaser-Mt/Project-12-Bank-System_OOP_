#include <iostream>
#include "clsBankClient.h"
#include "clsInputValidate.h"

using namespace std;

void ReadClientInfo(clsBankClient& Client)
{
    cout << "\nEnter FirstName : ";
    Client.FirstName = clsInputValidate::ReadString();

    cout << "\nEnter LastName : ";
    Client.LastName = clsInputValidate::ReadString();

    cout << "\nEnter Email : ";
    Client.Email = clsInputValidate::ReadString();

    cout << "\nEnter Phone : ";
    Client.Phone = clsInputValidate::ReadString();

    cout << "\nEnter PinCode : ";
    Client.PinCode = clsInputValidate::ReadString();

    cout << "\nEnter Account Balance : ";
    Client.AccountBalance = clsInputValidate::ReadFloatNumber();
}

void UpdateClient()
{
    string AccountNumber = "";

    cout << "\nPlease Enter Client Account Number : ";
    AccountNumber = clsInputValidate::ReadString();

    while (!clsBankClient::IsClientExist(AccountNumber))
    {
        cout << "\nAccount Number is not found, choose another one : ";
        AccountNumber = clsInputValidate::ReadString();
    }

    clsBankClient Client = clsBankClient::Find(AccountNumber);
    Client.Print();

    cout << "\n\nUpdate Client Info :";
    cout << "\n_________________\n";

    ReadClientInfo(Client);

    clsBankClient::enSaveResults SaveResult;

    SaveResult = Client.Save();

    switch (SaveResult)
    {
    case clsBankClient::enSaveResults::svSucceeded:

        cout << "\nAccount Updated Successfully :-)\n";
        Client.Print();
        break;

    case clsBankClient::enSaveResults::svFailedEmptyObject:

        cout << "\nError Account was not saved because it's Empty\n";
    }
}

void AddNewClient()
{
    string AccountNumber = "";

    cout << "\nPlease Enter Account Number : ";
    AccountNumber = clsInputValidate::ReadString();

    while (clsBankClient::IsClientExist(AccountNumber))
    {
        cout << "\nAccount Number is already Used, Choose another one : ";
        AccountNumber = clsInputValidate::ReadString();
    }

    clsBankClient NewClient = clsBankClient::GetAddNewClientObject(AccountNumber);

    ReadClientInfo(NewClient);

    clsBankClient::enSaveResults SaveResult;

    SaveResult = NewClient.Save();

    switch (SaveResult)
    {
    case clsBankClient::enSaveResults::svSucceeded:

        cout << "\nAccount Added Successfully :-)\n";
        NewClient.Print();
        break;

    case clsBankClient::enSaveResults::svFailedEmptyObject:

        cout << "\nError Account was not saved because it's empty\n";
        break;

    case clsBankClient::enSaveResults::svFailedAccountNumberExists:

        cout << "\nError Account was not saved because Account Number is used!\n";
        break;
    }
}

void DeleteClient()
{
    string AccountNumber = "";

    cout << "\nPlease Enter Account Number : ";
    AccountNumber = clsInputValidate::ReadString();

    while (!clsBankClient::IsClientExist(AccountNumber))
    {
        cout << "\nAccount Number was not found, Choose another one : ";
        AccountNumber = clsInputValidate::ReadString();
    }

    clsBankClient Client1 = clsBankClient::Find(AccountNumber);
    Client1.Print();

    cout << "\nAre you sure you want to delete this client y/n? ";

    char Answer = 'n';
    cin >> Answer;

    if (Answer == 'Y'|| Answer == 'y')
    {
        if (Client1.Delete())
        {
            cout << "\nClient Deleted Successfully :-)\n";
            Client1.Print();
        }
        else
        {
            cout << "\nError Client was not deleted\n";
        }
    }
}

int main()
{
    DeleteClient();

    system("pause>0");
    return 0;
}

