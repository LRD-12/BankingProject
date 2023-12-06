#include<iostream>
#include<string>
#include "savings-account.h"
using namespace std;

SavingsAccount::SavingsAccount():BankAccount("Savings") {}

SavingsAccount::SavingsAccount(double balance, int accountNum):BankAccount("Savings", balance, accountNum) {}

SavingsAccount::~SavingsAccount() {}

void SavingsAccount::setBalance(double amount) {
	BankAccount::setBalance(amount);
}

void SavingsAccount::withdraw(double amount)  {
	if (getBalance() + amount < 0) {
		cout << "Insufficient funds!" << endl;
	}
	else if (amount < -1000) {
		cout << "Withdrawal exceeds $1,000 limit!" << endl;
	}
	else {
		setBalance(getBalance() + amount);
		saveTransactionToFile("Withdrawal", amount);
	}
}