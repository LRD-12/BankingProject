#include<iostream>
#include<string>
#include "user.h"
#include "authenticator.h"
#include "bank-account.h"
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
					case 1: {
						string accountType;
						cout << "Enter type of account: ";
						cin >> accountType;
						BankAccount account(accountType);
						user.createAccount(&account);
						break;
					}
					case 2: {
						user.printAccounts();
					}
					}
				} while (userChoice != 3);
			}
			else {
				cout << "Login failed!" << endl;
			}
			break;
		}
		case 2: {

		}
		}
		
	} while (choice != 4);

	/*User user1 = Authenticator::loginUser("Logan", "1233");

	for (int i = 0; i < 5; i++) {
		BankAccount b("Savings");
		user1.createAccount(&b);
	}

	cout << user1.getName() << endl;
	cout << user1.getPassword() << endl;
	cout << user1.getUserNum() << endl;
	user1.saveToFile();*/
	return 0;
}