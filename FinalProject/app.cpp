#include<iostream>
#include<string>
#include<sstream>
#include<iomanip>
#include "user.h"
#include "authenticator.h"
#include "bank-account.h"
#include "checking-account.h"
#include "savings-account.h"
#include "transaction.h"
using namespace std;


// Utility function for safely getting user input
int getUserInput() {
	int choice;
	cin >> choice;
	while (cin.fail()) {
		cout << "Invalid input! Enter a number: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> choice;
	}
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	return choice;
}


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

		choice = getUserInput();

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
					userChoice = getUserInput();

					switch (userChoice) {
					// Create account
					case 1: {
						int accountChoice;
						do {
							cout << "Enter type of account (1 = Savings, 2 = Checking): ";
							accountChoice = getUserInput();
						} while (accountChoice != 1 && accountChoice != 2);

						BankAccount* account = nullptr;
						if (accountChoice == 1) {
							account = new SavingsAccount();
						}
						else {
							account = new CheckingAccount();
						}
						user.createAccount(account);
						cout << "Account created!" << endl;
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
								accountNum = getUserInput();
								account = user.getAccount(accountNum);
							} while (account == nullptr);

							int userChoice;
							do {
								cout << "1. Make a transaction (deposit/withdrawal)\n"
									<< "2. Account Summary\n"
									<< "3. Exit Account\n"
									<< "Enter your choice: ";
								userChoice = getUserInput();

								switch (userChoice) {
								// Make a transaction
								case 1: {
									double amount;
									cout << "Enter transaction amount: ";
									amount = getUserInput();
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
									cout << setw(20) << left << "Account Number" << setw(20) << "Account Type" << setw(20) << "Balance ($)" << endl;
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
		// Manager login
		case 3: {
			string name, password;
			cout << "Enter your name: ";
			cin >> name;
			cout << "Enter your password: ";
			cin >> password;

			Manager manager = Authenticator::loginManager(name, password);
			if (manager.isLoggedIn()) {
				cout << "Manager login success!" << endl;
				int managerChoice;
				do {
					cout << "1. View all accounts\n"
						<< "2. Delete account\n"
						<< "3. Logout\n"
						<< "Enter your choice: ";
					managerChoice = getUserInput();

					switch (managerChoice) {
					case 1: {
						manager.viewAllAccounts();
						break;
					}
					case 2: {
						int accountNum;
						cout << "Enter account number to delete: ";
						accountNum = getUserInput();
						manager.deleteAccount(accountNum);
						break;
					}
					}
				} while (managerChoice != 3);
			}
			else {
				cout << "Manager login failed!" << endl;
			}
			break;
		}
		}
		
	} while (choice != 4);

	return 0;
}