#include<iostream>
#include<fstream>
#include<sstream>
#include<iomanip>
#include "manager.h"
using namespace std;

Manager::Manager(bool loggedIn):loggedIn(loggedIn) {}

bool Manager::isLoggedIn() const {
    return loggedIn;
}

void Manager::viewAllAccounts() const {
    ifstream inputFile("bank-accounts.txt");

    if (inputFile.is_open()) {
        int userNum, accountNum;
        string accountType;
        double balance;

        cout << fixed << setprecision(2);
        cout << setw(20) << left << "User Number" << setw(20) << "Account Number" << setw(20) << "Account Type" << setw(20) << "Balance ($)" << endl;
        while (inputFile >> userNum >> accountNum >> accountType >> balance) {
            cout << setw(20) << userNum << setw(20) << accountNum << setw(20) << accountType << setw(20) << balance << endl;
        }
        inputFile.close();
    }
    else {
        cout << "Unable to open file for reading" << endl;
    }
}

void Manager::deleteTransactions(int accountNum) const {
    ifstream inputFile("transactions.txt");
    vector<string> tempTransactions;
    
    bool transactionFound = false;
    if (inputFile.is_open()) {
        int fileAccountNum;
        string type;
        double amount;

        while (inputFile >> fileAccountNum >> type >> amount) {
            ostringstream oss;
            if (accountNum != fileAccountNum) {
                oss << fileAccountNum << " " << type << " " << amount;
                tempTransactions.push_back(oss.str());
            }
            else {
                transactionFound = true;
            }
        }
        inputFile.close();
    }
    else {
        cout << "Unable to open file for reading" << endl;
    }

    if (transactionFound) {
        ofstream outputFile("transactions.txt");
        if (outputFile.is_open()) {
            for (const auto& transaction : tempTransactions) {
                outputFile << transaction << endl;
            }
            outputFile.close();
        }
        else {
            cout << "Unable to open file for writing" << endl;
        }
    }
}

void Manager::deleteAccount(int accountNum) const {
    ifstream inputFile("bank-accounts.txt");
    vector<string> tempAccounts;

    bool accountFound = false;
    if (inputFile.is_open()) {
        int userNum, fileAccountNum;
        string accountType;
        double balance;

        while (inputFile >> userNum >> fileAccountNum >> accountType >> balance) {
            ostringstream oss;
            if (accountNum != fileAccountNum) {
                oss << userNum << " " << fileAccountNum << " " << accountType << " " << balance;
                tempAccounts.push_back(oss.str());
            }
            else {
                accountFound = true;
            }
        }
        inputFile.close();
    }
    else {
        cout << "Unable to open file for reading" << endl;
    }
    
    if (accountFound) {
        // Rewrite bank accounts file
        ofstream outputFile("bank-accounts.txt");
        if (outputFile.is_open()) {
            for (const auto& account : tempAccounts) {
                outputFile << account << endl;
            }
            outputFile.close();
            cout << "Account deleted!" << endl;
        }
        else {
            cout << "Unable to open file for writing" << endl;
        }

        // Read and rewrite transactions file
        deleteTransactions(accountNum);
    }
    else {
        cout << "Account number not found!" << endl;
    }
}