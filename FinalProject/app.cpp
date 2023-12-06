#include<iostream>
#include<string>
#include "user.h"
#include "authenticator.h"
#include "bank-account.h"
#include "checking-account.h"
#include "savings-account.h"
#include "transaction.h"
using namespace std;

int main() {
	User::initializeNewUserNum();
	BankAccount::initializeNewAccountNum();

	int choice;
	do {
		cout << "1. User Login\n"
			<< "2. Create Account\n"
			<< "3. Manager Login\n"
			<< "4. Exit\n"
			<< "Enter your choice: ";
		cin >> choice;

		switch (choice) {
		// User login
		case 1: {
			string name, password;
			cout << "Enter your name: ";
			cin >> name;
			cout << "Enter your password: ";
			cin >> password;

			User user = Authenticator::loginUser(name, password);
			if (user.isLoggedIn()) {
				cout << "Login success!" << endl;
				int userChoice;
				do {
					cout << "1. Create account\n"
						<< "2. Manage accounts\n"
						<< "3. Logout\n"
						<< "Enter your choice: ";
					cin >> userChoice;

					switch (userChoice) {
					// Create account
					case 1: {
						int accountChoice;
						do {
							cout << "Enter type of account (1 = Savings, 2 = Checking): ";
							cin >> accountChoice;
						} while (accountChoice != 1 && accountChoice != 2);

						BankAccount* account = nullptr;
						if (accountChoice == 1) {
							account = new SavingsAccount();
						}
						else {
							account = new CheckingAccount();
						}
						user.createAccount(account);
						break;
					}
					// Manage accounts
					case 2: {
						if (user.hasAccounts()) {

							user.printAccounts();
							int accountNum;
							BankAccount* account = nullptr;
							do {
								cout << "Enter account number to manage: ";
								cin >> accountNum;
								account = user.getAccount(accountNum);
							} while (account == nullptr);

							int userChoice;
							do {
								cout << "1. Make a transaction (deposit/withdrawal)\n"
									<< "2. Account Summary\n"
									<< "3. Exit Account\n"
									<< "Enter your choice: ";
								cin >> userChoice;

								switch (userChoice) {
								// Make a transaction
								case 1: {
									double amount;
									cout << "Enter transaction amount: ";
									cin >> amount;
									if (amount > 0) {
										account->deposit(amount);
									}
									else if (amount < 0) {
										account->withdraw(amount);
									}
									break;
								}
								// Print account summary
								case 2: {
									account->printAccountSummary(true);
								}
								}
							} while (userChoice != 3);
						}
						else {
							cout << "No accounts exist!" << endl;
						}
					}
					}
				} while (userChoice != 3);
				// Save user account changes before 'logging them out'
				user.saveAccountsToFile();
			}
			else {
				cout << "Login failed!" << endl;
			}
			break;
		}
		case 2: {
			cout << "Creating account..." << endl;
			string name, password;
			cout << "Enter your name: ";
			cin >> name;
			cout << "Enter your password: ";
			cin >> password;

			User userLogin = Authenticator::loginUser(name, password);
			if (!userLogin.isLoggedIn()) {
				User user(name, password);
				user.saveToFile();
				cout << "User created!" << endl;
			}
			else {
				cout << "This name/password combination already exists!" << endl;
			}
			break;
		}
		case 3: {
			
		}
		}
		
	} while (choice != 4);

	return 0;
}