#include<iostream>
#include "user.h"
using namespace std;

int main() {
	User::initializeNewUserNum();
	BankAccount::initializeNewAccountNum();

	User user1("L", "D"), user2("A", "D"), user3("d", "k", 111);
	cout << user1.getUserNum() << endl;
	cout << user2.getUserNum() << endl;
	cout << user3.getUserNum() << endl;

	for (int i = 0; i < 10; i++) {
		user1.createAccount("Savings");
	}
}