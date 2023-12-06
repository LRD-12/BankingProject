#include "authenticator.h"
#include<fstream>
#include<iostream>
using namespace std;

User Authenticator::loginUser(string name, string password) {
	ifstream inputFile("users.txt");

	if (inputFile.is_open()) {
		int userNum;
		string n, p;
		
		while (inputFile >> userNum >> n >> p) {
			if (name == n && password == p) {
				// User logged in successfully
				return User(name, password, userNum);
			}
		}
	}
	else {
		cout << "Unable to open file for reading";
	}
	// User login failed
	return User();
}

Manager Authenticator::loginManager(string name, string password) {
	ifstream inputFile("managers.txt");

	if (inputFile.is_open()) {
		string n, p;
		while (inputFile >> n >> p) {
			if (name == n && password == p) {
				// Manager logged in successfully
				return Manager(true);
			}
		}
		inputFile.close();
	}
	else {
		cout << "Unable to open file for reading" << endl;
	}
	// Manager login failed
	return Manager(false);
}