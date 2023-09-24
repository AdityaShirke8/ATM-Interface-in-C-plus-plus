//We first import the required libraries
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

// Define a structure to represent a transaction
struct Transaction {
    string type;
    double amount;
    string targetAccount;
};

class ATM {
private:
    double balance;
    string accountNumber;
    string pin;
    vector<Transaction> transactionHistory;

public:
    ATM(string accNumber, string pinCode) {
        balance = 0.0;
        accountNumber = accNumber;
        pin = pinCode;
    }

    // Function to display transaction history
    void displayTransactionHistory() {
        cout << "\nTransaction History:\n";
        cout << "----------------------\n";
        cout << "Type\tAmount\tTarget Account\n";
        cout << "----------------------\n";
        for (const Transaction &transaction : transactionHistory) {
            cout << transaction.type << "\t" << transaction.amount << "\t" << transaction.targetAccount << endl;
        }
    }

    // Function to withdraw money
    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            Transaction transaction;
            transaction.type = "Withdraw";
            transaction.amount = amount;
            transaction.targetAccount = "";
            transactionHistory.push_back(transaction);
            cout << "Withdrawn $" << amount << endl;
        } else {
            cout << "Invalid withdrawal amount or insufficient balance." << endl;
        }
    }

    // Function to deposit money
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            Transaction transaction;
            transaction.type = "Deposit";
            transaction.amount = amount;
            transaction.targetAccount = "";
            transactionHistory.push_back(transaction);
            cout << "Deposited $" << amount << endl;
        } else {
            cout << "Invalid deposit amount." << endl;
        }
    }

    // Function to transfer money to another account
    void transfer(string targetAccount, double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            Transaction transaction;
            transaction.type = "Transfer";
            transaction.amount = amount;
            transaction.targetAccount = targetAccount;
            transactionHistory.push_back(transaction);
            cout << "Transferred $" << amount << " to account " << targetAccount << endl;
        } else {
            cout << "Invalid transfer amount or insufficient balance." << endl;
        }
    }

    // Function to display balance
    void displayBalance() {
        cout << "Current Balance: $" << balance << endl;
    }

    // Authenticate the user by verifying the account number and PIN
    bool authenticate(string enteredAccountNumber, string enteredPin) {
        return (enteredAccountNumber == accountNumber && enteredPin == pin);
    }

    // Main menu
    void menu() {
        string enteredAccountNumber;
        string enteredPin;

        cout << "Welcome to the ATM!\n";
        cout << "Enter your account number: ";
        cin >> enteredAccountNumber;
        cout << "Enter your PIN: ";
        cin >> enteredPin;

        if (!authenticate(enteredAccountNumber, enteredPin)) {
            cout << "Authentication failed. Exiting...\n";
            return;
        }

        int choice;
        double amount;
        string targetAccount;

        do {
            cout << "\nATM Interface\n";
            cout << "1. Transaction History\n";
            cout << "2. Withdraw\n";
            cout << "3. Deposit\n";
            cout << "4. Transfer\n";
            cout << "5. Display Balance\n";
            cout << "6. Quit\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    displayTransactionHistory();
                    break;
                case 2:
                    cout << "Enter withdrawal amount: $";
                    cin >> amount;
                    withdraw(amount);
                    break;
                case 3:
                    cout << "Enter deposit amount: $";
                    cin >> amount;
                    deposit(amount);
                    break;
                case 4:
                    cout << "Enter target account number: ";
                    cin >> targetAccount;
                    cout << "Enter transfer amount: $";
                    cin >> amount;
                    transfer(targetAccount, amount);
                    break;
                case 5:
                    displayBalance();
                    break;
                case 6:
                    cout << "Thank you for using the ATM. Goodbye!\n";
                    break;
                default:
                    cout << "Invalid choice. Please try again.\n";
                    break;
            }
        } while (choice != 6);
    }
};

int main() {
    // WE initialize the ATM with account number and PIN
    ATM atm("867342", "0976");
    atm.menu();
    return 0;
}
