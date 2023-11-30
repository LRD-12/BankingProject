#include<iostream>
#include<fstream>
#include "user.h"

int User::newUserNum = 0;

void User::initializeNewUserNum() {
	ifstream inputFile("user-num.txt");

	if (inputFile.is_open()) {
		int num;
		inputFile >> num;
		newUserNum = num;
	}
	else {
		cout << "Unable to open file for reading." << endl;
	}
}

void User::saveNewUserNum() {
	ofstream outputFile("user-num.txt");

	if (outputFile.is_open()) {
		outputFile << newUserNum;
	}
	else {
		cout << "Unable to open file for writing." << endl;
	}
}

User::User(string name, string password) {
	userNum = newUserNum;
	newUserNum++;
	saveNewUserNum();
}

User::User(string name, string password, int userNum):name(name), password(password), userNum(userNum) {}

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

bool User::login() { return true; }

void User::createAccount(string accountType) {
	accounts.emplace_back(accountType);
}