#include<iostream>
#include<fstream>
#include<iomanip>
#include "user.h"

int User::newUserNum = 0;

void User::initializeNewUserNum() {
	ifstream inputFile("user-num.txt");

	if (inputFile.is_open()) {
		int num;
		inputFile >> num;
		newUserNum = num;
		inputFile.close();
	}
	else {
		cout << "Unable to open file for reading." << endl;
	}
}

void User::saveNewUserNum() {
	ofstream outputFile("user-num.txt");

	if (outputFile.is_open()) {
		outputFile << newUserNum;
		outputFile.close();
	}
	else {
		cout << "Unable to open file for writing." << endl;
	}
}

void User::initializeAccounts() {
	ifstream inputFile("bank-accounts.txt");

	if (inputFile.is_open()) {
		int fileUserNum, accountNum;
		double balance;
		string accountType;

		while (inputFile >> fileUserNum >> accountNum >> accountType >> balance) {
			if (userNum == fileUserNum) {
				// Make a BankAccount object and put it in the accounts vector
				accounts.emplace_back(accountType, balance, accountNum);
			}
		}
	}
	else {
		cout << "Unable to open file for reading";
	}
}

// Used to show that user login failed
User::User():loggedIn(false), userNum(-1) {}

// Used to create new user account
User::User(string name, string password):name(name), password(password), loggedIn(false) {
	userNum = newUserNum;
	newUserNum++;
	saveNewUserNum();
}

// Used when user logs in successfully
User::User(string name, string password, int userNum):name(name), password(password), userNum(userNum), loggedIn(true) {
	initializeAccounts();
}

User::~User() {}

string User::getName() const {
	return name;
}

string User::getPassword() const {
	return password;
}

int User::getUserNum() const {
	return userNum;
}

bool User::isLoggedIn() const {
	return loggedIn;
}

void User::saveToFile() const {
	// Open file in append mode
	ofstream outputFile("users.txt", ios::app);

	if (outputFile.is_open()) {
		outputFile << userNum << " " << name << " " << password << endl;
		outputFile.close();
	}
	else {
		cout << "Unable to open file for writing." << endl;
	}
}

void User::createAccount(BankAccount* account) {
	accounts.push_back(*account);
	account->saveToFile(userNum);
}

BankAccount* User::getAccount(int accountNum) {
	for (auto& account : accounts) {
		if (accountNum == account.getAccountNum()) {
			return &account;
		}
	}
	return nullptr;
}

void User::printAccounts() const {
	cout << setw(20) << left << "Account Number" << setw(20) << "Account Type" << setw(20) << "Balance" << endl;
	for (const auto& account : accounts) {
		account.printAccountSummary(false);
	}
}