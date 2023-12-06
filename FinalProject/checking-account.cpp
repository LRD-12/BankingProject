#include<iostream>
#include<string>
#include "checking-account.h"
using namespace std;

CheckingAccount::CheckingAccount() :BankAccount("Checking") {}

CheckingAccount::CheckingAccount(double balance, int accountNum) :BankAccount("Checking", balance, accountNum) {}

CheckingAccount::~CheckingAccount() {}

void CheckingAccount::setBalance(double amount) {
	BankAccount::setBalance(amount);
}

void CheckingAccount::withdraw(double amount) {
	if (getBalance() + amount < 0) {
		cout << "Insufficient funds!" << endl;
	}
	else {
		setBalance(getBalance() + amount);
		saveTransactionToFile("Withdrawal", amount);
	}
}