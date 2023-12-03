#include<string>
#include<vector>
#include "transaction.h"
using namespace std;

#ifndef BANK_ACCOUNT_H
#define BANK_ACCOUNT_H

class BankAccount {
private:
	int accountNum;
	string accountType;
	double balance;
	vector<Transaction> transactions;

	static int newAccountNum;
	static void saveNewAccountNum();
	void initializeTransactions();
public:
	BankAccount(string accountType);
	BankAccount(string accountType, double balance, int accountNum);
	~BankAccount();
	int getAccountNum() const;
	string getAccountType() const;
	double getBalance() const;
	void withdraw(double amount);
	void deposit(double amount);
	void printAccountSummary(bool outputTransactions) const;
	void saveToFile(int userNum) const;
	static void initializeNewAccountNum();
};

#endif