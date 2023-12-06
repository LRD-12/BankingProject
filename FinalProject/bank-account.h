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
	virtual ~BankAccount();
	int getAccountNum() const;
	string getAccountType() const;
	double getBalance() const;
	virtual void setBalance(double amount);
	virtual void withdraw(double amount) = 0;
	void deposit(double amount);
	void printAccountSummary(bool outputTransactions) const;
	void saveToFile(int userNum) const;
	void saveTransactionToFile(string type, double amount);
	static void initializeNewAccountNum();
};
#endif