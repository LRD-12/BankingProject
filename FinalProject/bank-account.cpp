#include<iostream>
#include<fstream>
#include "bank-account.h"

int BankAccount::newAccountNum = 0;

void BankAccount::initializeNewAccountNum() {
	ifstream inputFile("bank-account-num.txt");

	if (inputFile.is_open()) {
		int num;
		inputFile >> num;
		newAccountNum = num;
	}
	else {
		cout << "Unable to open file for reading." << endl;
	}
}

void BankAccount::saveNewAccountNum() {
	ofstream outputFile("bank-account-num.txt");

	if (outputFile.is_open()) {
		outputFile << newAccountNum;
	}
	else {
		cout << "Unable to open file for writing." << endl;
	}
}

BankAccount::BankAccount(string accountType):accountType(accountType), balance(0) {
	accountNum = newAccountNum;
	newAccountNum++;
	saveNewAccountNum();
}

BankAccount::BankAccount(string accountType, double balance, int accountNum) :accountType(accountType),
	balance(balance), accountNum(accountNum) {}

void BankAccount::withdraw(double amount) {
	if (amount > balance) {
		cout << "Insufficient funds!";
	}
	else {
		// CREATE TRANSACTION AND SAVE TO FILE !!!!
		balance -= amount;
		// UPDATE ACCOUNT INFO IMMEDIATELY ???
	}
}

void BankAccount::deposit(double amount) {
	// CREATE TRANSACTION AND SAVE TO FILE !!!!
	balance += amount;
	// UPDATE ACCOUNT INFO IMMEDIATELY ???
}

void BankAccount::printAccountSummary() const {
	cout << "Account Num: " << accountNum << endl;
	cout << "Account Type: " << accountType << endl;
	cout << "Balance: " << balance << endl;
	// PRINT ALL TRANSACTIONS
}

// Saves to 'bank-accounts.txt', userNum provided as argument since we can't access it directly from BankAccount object
void BankAccount::saveToFile(int userNum) const {
	ofstream outputFile("bank-accounts.txt", ios::app);

	if (outputFile.is_open()) {
		outputFile << userNum << " " << accountNum << " " << accountType << " " << balance << endl;
		outputFile.close();
	}
	else {
		cout << "Unable to open file for writing." << endl;
	}
}