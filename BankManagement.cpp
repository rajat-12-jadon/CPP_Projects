#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class BankAccount
{
    string AccountHolderName;
    string AccountNumber;
    float NetBalance;

public:
    BankAccount(string name, string accNum, float balance = 0.0)
    {
        AccountHolderName = name;
        AccountNumber = accNum;
        NetBalance = balance;
    }

    void deposit(float amount)
    {
        if (amount > 0)
        {
            NetBalance += amount;
            cout << "Deposited: " << amount << endl;
        }
        else
        {
            cout << "Invalid amount!" << endl;
        }
    }

    void withdraw(float amount)
    {
        if (amount > 0 && amount <= NetBalance)
        {
            NetBalance -= amount;
            cout << "Withdrawn: " << amount << endl;
        }
        else
        {
            cout << "Insufficient balance or invalid input!" << endl;
        }
    }

    void checkBalance()
    {
        cout << "Net Balance: " << NetBalance << endl;
    }

    void displayAccountInfo()
    {
        cout << "Account Holder: " << AccountHolderName << endl;
        cout << "Account Number: " << AccountNumber << endl;
        checkBalance();
    }
};

int main()
{
    string name, accNumber;
    int intBalance;

    cout << "Enter the Account Holder Name: ";
    getline(cin, name);
    cout << "Enter Account Number: ";
    getline(cin, accNumber);
    cout << "Enter Initial Balance: ";
    cin >> intBalance;

    BankAccount account(name, accNumber, intBalance);

    int choice = -1;
    while (true)
    {
        // Display menu options
        cout << "\n1. Deposit\n2. Withdraw\n3. Check Balance\n4. Display Account Info\n5. Exit\n";
        cout << "Enter your choice: ";

        // Input validation
        if (!(cin >> choice))
        {
            // Clear the error flag and ignore invalid input
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Please enter a number from 1 to 5.\n";
            continue; // Skip the rest of the loop and prompt again
        }

        switch (choice)
        {
        case 1:
        {
            float depositAmount;
            cout << "Enter deposit amount: ";
            cin >> depositAmount;
            account.deposit(depositAmount);
            break;
        }

        case 2:
        {
            float withdrawalAmount;
            cout << "Enter withdrawal amount: ";
            cin >> withdrawalAmount;
            account.withdraw(withdrawalAmount);
            break;
        }

        case 3:
        {
            account.checkBalance();
            break;
        }

        case 4:
        {
            account.displayAccountInfo();
            break;
        }

        case 5:
        {
            cout << "Exiting the system...\n";
            return 0;
        }
        default:
            cout << "Invalid Choice! Please enter a number from 1 to 5.\n";
            break;
        }
    }
    return 0;
}