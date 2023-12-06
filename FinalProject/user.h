#include<string>
#include<vector>
#include "bank-account.h"
using namespace std;

#ifndef USER_H
#define USER_H

class User {
private:
	string name;
	string password;
	int userNum;
	vector<BankAccount*> accounts;
	bool loggedIn;
	static int newUserNum;

	void initializeAccounts();
	static void saveNewUserNum();
public:
	User();
	User(string name, string password);
	User(string name, string password, int userNum);
	~User();
	string getName() const;
	string getPassword() const;
	int getUserNum() const;
	bool isLoggedIn() const;
	void saveToFile() const;
	void saveAccountsToFile() const;
	bool hasAccounts() const;
	void createAccount(BankAccount* account);
	BankAccount* getAccount(int accountNum) const;
	void printAccounts() const;

	static void initializeNewUserNum();
};

#endif