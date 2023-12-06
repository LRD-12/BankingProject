#include<iostream>
#include<fstream>
#include<iomanip>
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

void BankAccount::initializeTransactions() {
	ifstream inputFile("transactions.txt");

	if (inputFile.is_open()) {
		int fileAccountNum;
		double amount;
		string type;

		while (inputFile >> fileAccountNum >> type >> amount) {
			if (fileAccountNum == accountNum) {
				// Make a Transaction object and put it in the transactions vector
				transactions.emplace_back(type, amount);
			}
		}
	}
	else {
		cout << "Unable to open file for reading";
	}
}

// Used to create a new bank account
BankAccount::BankAccount(string accountType):accountType(accountType), balance(0) {
	accountNum = newAccountNum;
	newAccountNum++;
	saveNewAccountNum();
}

// Used to load an existing bank account
BankAccount::BankAccount(string accountType, double balance, int accountNum) :accountType(accountType),
	balance(balance), accountNum(accountNum) {
	initializeTransactions();
}

BankAccount::~BankAccount() {}

int BankAccount::getAccountNum() const {
	return accountNum;
}

string BankAccount::getAccountType() const {
	return accountType;
}

double BankAccount::getBalance() const {
	return balance;
}

void BankAccount::setBalance(double amount) {
	balance = amount;
}

void BankAccount::saveTransactionToFile(string type, double amount) {
	Transaction transaction(type, amount);
	transactions.push_back(transaction);
	transaction.saveToFile(accountNum);
}


void BankAccount::deposit(double amount) {
	// create transaction and save to file
	balance += amount;
	saveTransactionToFile("Deposit", amount);
}

void BankAccount::printAccountSummary(bool outputTransactions) const {
	cout << setw(20) << left << accountNum << setw(20) << accountType << setw(20) << "$" + to_string(balance) << endl;
	if (outputTransactions) {
		for (const auto& transaction : transactions) {
			transaction.printTransaction();
		}
	}
	
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