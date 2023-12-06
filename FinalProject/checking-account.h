#include "bank-account.h"
#include<string>
using namespace std;

#ifndef CHECKING_ACCOUNT_H
#define CHECKING_ACCOUNT_H

class CheckingAccount :public BankAccount {
public:
	CheckingAccount();
	CheckingAccount(double balance, int accountNum);
	~CheckingAccount();
	void setBalance(double amount) override;
	void withdraw(double amount) override;
};
#endif

