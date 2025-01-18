#include <iostream>
#include <limits>
using namespace std;

class ATMSimulator
{
private:
    double balance;

public:
    ATMSimulator() : balance(0.0) {}

    void displayMenu()
    {
        cout << "\nATM Simulator Menu:\n";
        cout << "1. Check Balance\n";
        cout << "2. Deposit Money\n";
        cout << "3. Withdraw Money\n";
        cout << "4. Exit\n";
    }

    void checkBalance() const
    {
        cout << "Your current balance is: $" << balance << endl;
    }

    void depositMoney()
    {
        double amount;
        cout << "Enter amount to deposit: $";
        cin >> amount;

        if (cin.fail() || amount <= 0)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid amount. Please enter a positive number.\n";
            return;
        }

        balance += amount;
        cout << "Successfully deposited: $" << amount << endl;
    }

    void withdrawMoney()
    {
        double amount;
        cout << "Enter amount to withdraw: $";
        cin >> amount;

        if (cin.fail() || amount <= 0)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid amount. Please enter a positive number.\n";
            return;
        }

        if (amount > balance)
        {
            cout << "Insufficient funds! Your current balance is: $" << balance << endl;
        }
        else
        {
            balance -= amount;
            cout << "Successfully withdrew: $" << amount << endl;
        }
    }
};

int main()
{
    ATMSimulator atm;
    int choice;

    do
    {
        atm.displayMenu();
        cout << "Enter your choice: ";

        while (!(cin >> choice))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid choice. Please enter a number between 1 and 4: ";
        }

        switch (choice)
        {
        case 1:
            atm.checkBalance();
            break;
        case 2:
            atm.depositMoney();
            break;
        case 3:
            atm.withdrawMoney();
            break;
        case 4:
            cout << "Exiting the ATM Simulator. Thank you!\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
            break;
        }
    } while (choice != 4);

    return 0;
}

// By Bhukya Ganesh