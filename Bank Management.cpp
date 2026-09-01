#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class BankAccount {
private:
    int accountNumber;
    string name;
    double balance;

public:
    // Constructor
    BankAccount() {
        accountNumber = 0;
        name = "";
        balance = 0;
    }

    // Create account
    void createAccount() {
        cout << "\nEnter Account Number: ";
        cin >> accountNumber;

        cin.ignore();
        cout << "Enter Customer Name: ";
        getline(cin, name);

        cout << "Enter Initial Deposit: ";
        cin >> balance;

        cout << "\nAccount created successfully!\n";
    }

    // Deposit
    void deposit() {
        double amount;

        cout << "\nEnter deposit amount: ";
        cin >> amount;

        if (amount > 0) {
            balance += amount;
            cout << "Amount deposited successfully.\n";
        } else {
            cout << "Invalid amount.\n";
        }
    }

    // Withdraw
    void withdraw() {
        double amount;

        cout << "\nEnter withdrawal amount: ";
        cin >> amount;

        if (amount <= 0) {
            cout << "Invalid amount.\n";
        }
        else if (amount > balance) {
            cout << "Insufficient balance.\n";
        }
        else {
            balance -= amount;
            cout << "Amount withdrawn successfully.\n";
        }
    }

    // Display balance
    void checkBalance() {
        cout << "\nCurrent Balance: Rs. " << balance << endl;
    }

    // Display account details
    void displayAccount() {
        cout << "\n----- Account Details -----\n";
        cout << "Account Number : " << accountNumber << endl;
        cout << "Customer Name  : " << name << endl;
        cout << "Balance        : Rs. " << balance << endl;
    }

    // Get account number
    int getAccountNumber() {
        return accountNumber;
    }

    // Save data to file
    void saveToFile() {
        ofstream file("bank_data.txt", ios::app);

        file << accountNumber << endl;
        file << name << endl;
        file << balance << endl;

        file.close();
    }
};

int main() {
    BankAccount account;
    int choice;

    do {
        cout << "\n========== BANK MANAGEMENT SYSTEM ==========\n";
        cout << "1. Create Account\n";
        cout << "2. Deposit Money\n";
        cout << "3. Withdraw Money\n";
        cout << "4. Check Balance\n";
        cout << "5. Display Account Details\n";
        cout << "6. Exit\n";
        cout << "============================================\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            account.createAccount();
            account.saveToFile();
            break;

        case 2:
            account.deposit();
            break;

        case 3:
            account.withdraw();
            break;

        case 4:
            account.checkBalance();
            break;

        case 5:
            account.displayAccount();
            break;

        case 6:
            cout << "\nThank you for using the Bank Management System!\n";
            break;

        default:
            cout << "\nInvalid choice. Try again.\n";
        }

    } while (choice != 6);

    return 0;
}
