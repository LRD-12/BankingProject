#include<iostream>
#include "user.h"
using namespace std;

int main() {
	User::initializeNewUserNum();
	BankAccount::initializeNewAccountNum();

	User user1("Logan", "wu_tang_clan");

	for (int i = 0; i < 10; i++) {
		BankAccount b("Savings");
		user1.createAccount(&b);
	}

	cout << user1.getName();
	cout << user1.getPassword();
	user1.saveToFile();

}