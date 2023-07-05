#include <iostream>

using namespace std;

bool verifyPIN(int enteredPIN, int storedPIN)
{
    return enteredPIN == storedPIN;
}

void withdrawCash(double& accountBalance)
{
    cout << "Enter the amount to withdraw: $";
    double amount;
    cin >> amount;

    if (amount <= accountBalance)
    {
        cout << "Withdrawing $" << amount << " from your account." << endl;
        accountBalance -= amount;
    }
    else
    {
        cout << "Insufficient funds. Unable to withdraw $" << amount << "." << endl;
    }
}

void depositFunds(double& accountBalance)
{
    cout << "Enter the amount to deposit: $";
    double amount;
    cin >> amount;

    cout << "Depositing $" << amount << " into your account." << endl;
    accountBalance += amount;
}

void checkBalance(double accountBalance)
{
    cout << "Your current account balance is $" << accountBalance << endl;
}

int main()
{
    cout << "Welcome to the ATM. Please insert your bank card." << endl;

    int enteredPIN;
    cout << "Enter your PIN: ";
    cin >> enteredPIN;

    int storedPIN = 1234;
    if (verifyPIN(enteredPIN, storedPIN))
    {
        bool continueTransaction = true;
        double accountBalance = 10000.0;

        while (continueTransaction)
        {
            cout << "1. Withdraw cash" << endl;
            cout << "2. Deposit funds" << endl;
            cout << "3. Check account balance" << endl;
            cout << "4. End session" << endl;

            cout << "Select an option: ";
            int option;
            cin >> option;

            switch (option)
            {
                case 1:
                {
                    withdrawCash(accountBalance);
                    break;
                }
                case 2:
                {
                    depositFunds(accountBalance);
                    break;
                }
                case 3:
                {
                    checkBalance(accountBalance);
                    break;
                }
                case 4:
                {
                    cout << "Thank you for using the ATM. Please take your bank card." << endl;
                    continueTransaction = false;
                    break;
                }
                default:
                {
                    cout << "Invalid option. Please try again." << endl;
                    break;
                }
            }

            if (continueTransaction)
            {
                char choice;
                cout << "\nDo you want to perform another transaction? (Y/N): ";
                cin >> choice;
                if (choice != 'Y' && choice != 'y')
                {
                	cout << "Thank you for using the ATM. Please take your bank card." << endl;
                    continueTransaction = false;
                }
            }
        }
    }
    else
    {
        cout << "Invalid PIN. Please try again." << endl;
    }
    return 0;
}

