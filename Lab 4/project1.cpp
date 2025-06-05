#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;

class Account {
private:
    string accountNumber;
    string name;
    double balance;

public:
    Account(string accNum, string accName, double initialBalance)
        : accountNumber(accNum), name(accName), balance(initialBalance) {}

    string getAccountNumber() const { return accountNumber; }
    string getName() const { return name; }
    double getBalance() const { return balance; }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposit successful. New balance: " << balance << endl;
        } else {
            cout << "Invalid deposit amount." << endl;
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawal successful. New balance: " << balance << endl;
        } else {
            cout << "Insufficient funds or invalid amount." << endl;
        }
    }

    void display() const {
        cout << left << setw(15) << accountNumber
             << setw(25) << name
             << setw(10) << fixed << setprecision(2) << balance << endl;
    }
};

class Bank {
private:
    vector<Account> accounts;

    Account* findAccount(const string& accountNumber) {
        for (auto& account : accounts) {
            if (account.getAccountNumber() == accountNumber) {
                return &account;
            }
        }
        return nullptr;
    }

public:
    void createAccount() {
        string accNum, name;
        double initialBalance;

        cout << "Enter account number: ";
        cin >> accNum;

        // Check if account already exists
        if (findAccount(accNum)) {
            cout << "Account already exists!" << endl;
            return;
        }

        cout << "Enter account holder name: ";
        cin.ignore();
        getline(cin, name);

        cout << "Enter initial balance: ";
        cin >> initialBalance;

        accounts.emplace_back(accNum, name, initialBalance);
        cout << "Account created successfully!" << endl;
    }

    void deposit() {
        string accNum;
        double amount;

        cout << "Enter account number: ";
        cin >> accNum;

        Account* account = findAccount(accNum);
        if (account) {
            cout << "Enter deposit amount: ";
            cin >> amount;
            account->deposit(amount);
        } else {
            cout << "Account not found!" << endl;
        }
    }

    void withdraw() {
        string accNum;
        double amount;

        cout << "Enter account number: ";
        cin >> accNum;

        Account* account = findAccount(accNum);
        if (account) {
            cout << "Enter withdrawal amount: ";
            cin >> amount;
            account->withdraw(amount);
        } else {
            cout << "Account not found!" << endl;
        }
    }

    void checkBalance() {
        string accNum;

        cout << "Enter account number: ";
        cin >> accNum;

        Account* account = findAccount(accNum);
        if (account) {
            cout << "Account Holder: " << account->getName() << endl;
            cout << "Current Balance: " << account->getBalance() << endl;
        } else {
            cout << "Account not found!" << endl;
        }
    }

    void displayAllAccounts() {
        if (accounts.empty()) {
            cout << "No accounts found!" << endl;
            return;
        }

        cout << left << setw(15) << "Account Number"
             << setw(25) << "Account Holder"
             << setw(10) << "Balance" << endl;
        cout << string(50, '-') << endl;

        for (const auto& account : accounts) {
            account.display();
        }
    }
};

void displayMenu() {
    cout << "\nBank Management System" << endl;
    cout << "1. Create Account" << endl;
    cout << "2. Deposit" << endl;
    cout << "3. Withdraw" << endl;
    cout << "4. Check Balance" << endl;
    cout << "5. Display All Accounts" << endl;
    cout << "6. Exit" << endl;
    cout << "Enter your choice: ";
}

int main() {
    Bank bank;
    int choice;

    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                bank.createAccount();
                break;
            case 2:
                bank.deposit();
                break;
            case 3:
                bank.withdraw();
                break;
            case 4:
                bank.checkBalance();
                break;
            case 5:
                bank.displayAllAccounts();
                break;
            case 6:
                cout << "Thank you for using our bank system!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 6);

    return 0;
}
