#include<iostream>
#include<fstream>
#include<sstream>
#include "manager.h"
using namespace std;

Manager::Manager(bool loggedIn):loggedIn(loggedIn) {}

bool Manager::isLoggedIn() const {
    return loggedIn;
}

void Manager::viewAllAccounts() const {
    ifstream inputFile("bank-accounts.txt");

    if (inputFile.is_open()) {
        string line;
        while (getline(inputFile, line)) {
            cout << line << endl;
        }
        inputFile.close();
    }
    else {
        cout << "Unable to open file for reading" << endl;
    }
}

void Manager::deleteAccount(int accountNum) {
    ifstream inputFile("bank-accounts.txt");
    vector<string> tempAccounts;

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
        }
        inputFile.close();
    }
    else {
        cout << "Unable to open file for reading" << endl;
    }
    

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
}