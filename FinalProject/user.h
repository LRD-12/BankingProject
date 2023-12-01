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
	vector<BankAccount> accounts;
	static int newUserNum;

	static void saveNewUserNum();
public:
	User(string name, string password);
	User(string name, string password, int userNum);
	~User();
	string getName() const;
	string getPassword() const;
	int getUserNum() const;
	void saveToFile() const;
	bool login();
	void createAccount(BankAccount* account);

	static void initializeNewUserNum();
};

#endif