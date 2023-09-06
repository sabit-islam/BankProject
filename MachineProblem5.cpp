// Title: MachineProblem5.cpp
// Author: Sabit Islam
// Date: 7/30/2023
// Description: Write a C++ program that manages customer’s information at the bank
// and afterwards displays the required information for each customer. 

#include <iostream>
#include <iomanip>

using namespace std;

// function where we ask for their account number 
int readAccountNo() {
    int accountNumber;
    do {
        cout << "Enter account number: ";
        cin >> accountNumber;
        if (accountNumber % 2 != 0 || accountNumber <= 0 || accountNumber >= 10000) {
            cout << "Invalid account number. Please enter an even positive number less than 10000.\n";
        }
    } while (accountNumber % 2 != 0 || accountNumber <= 0 || accountNumber >= 10000);
    return accountNumber;
}
// function where we ask for initial starting balance 
double readBalanceAmount() {
    double balance;
    do {
        cout << "Enter opening balance: ";
        cin >> balance;
        if (balance < 1 || balance > 200000) {
            cout << "Invalid balance amount. Please enter a value between 1 and $200,000.\n";
        }
    } while (balance < 1 || balance > 200000);
    return balance;
}
// function which adds deposit into total balance 
double calculateDeposit(double balance) {
    double deposit;
    cout << "Enter the amount to deposit: ";
    cin >> deposit;
    balance += deposit;
    cout << "New cumulative amount balance: " << balance << endl;
    return balance;
}
//function which calculates and returns updated balance with bonus
double addReturnBonus(double balance) {
    if (balance >= 1 && balance <= 100)
        balance += balance * 0.02;
    else if (balance >= 101 && balance <= 500)
        balance += balance * 0.03;
    else if (balance >= 501 && balance <= 1000)
        balance += balance * 0.04;
    else if (balance > 1000)
        balance += balance * 0.05;

    return balance;
}
// printing each customers info
void printAllInfo(int accNumbers[], double balances[], int numCustomers) {
    cout << "================================= Balance Accounts ==========================\n";
    for (int i = 0; i < numCustomers; i++) {
        cout << "=============================================================================\n";
        cout << "Balance amount for Customer account number: " << accNumbers[i] << "       " << fixed << setprecision(2) << "$" << balances[i] << endl;
    }
    cout << "=============================================================================\n";
}

int main() {
    // display initial header
    cout << "*****************************************************************************\n";
    cout << "*****************************************************************************\n";
    cout << "Name: Sabit Islam Section: DT2            Due Date: July 30, 2023\n";
    cout << "*****************************************************************************\n";
    cout << "*****************************************************************************\n\n";

    // data for our 4 customers
    const int numCustomers = 4;
    int accountNumbers[numCustomers];
    double openingBalances[numCustomers];

    // where we we will input data
    cout << "Enter data for 4 customers:\n\n";
    for (int i = 0; i < numCustomers; i++) {
        cout << "For customer " << i + 1 << ":\n";
        accountNumbers[i] = readAccountNo();
        openingBalances[i] = readBalanceAmount();
    }

    // Add bonus for each customer
    for (int i = 0; i < numCustomers; i++) {
        openingBalances[i] = addReturnBonus(openingBalances[i]);
    }

    // our menu 
    char choice;
    do {
        cout << "\nMain Menu:\n";
        cout << "A-   Do deposit\n";
        cout << "B-   View accounts\n";
        cout << "C-   Exit the program\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 'A':
            case 'a':
                // Do deposit
                cout << "Enter the customer number (1 to 4): ";
                int customerNum;
                cin >> customerNum;
                if (customerNum >= 1 && customerNum <= numCustomers) {
                    openingBalances[customerNum - 1] = calculateDeposit(openingBalances[customerNum - 1]);
                } else {
                    cout << "Invalid customer number. Please enter a number between 1 and 4.\n";
                }
                break;
            case 'B':
            case 'b':
                // View accounts
                printAllInfo(accountNumbers, openingBalances, numCustomers);
                break;
            case 'C':
            case 'c':
                // Exit program
                cout << "Exiting program.\n";
                break;
            default:
                // Invalid choice
                cout << "Invalid menu option. Please try again.\n";
        }
    } while (choice != 'C' && choice != 'c');

    return 0;
}
