#include "bank-account.h"
#include<string>
using namespace std;

#ifndef SAVINGS_ACCOUNT_H
#define SAVINGS_ACCOUNT_H

class SavingsAccount :public BankAccount {
public:
	SavingsAccount();
	SavingsAccount(double balance, int accountNum);
	~SavingsAccount();
	void setBalance(double amount) override;
	void withdraw(double amount) override;
};
#endif
