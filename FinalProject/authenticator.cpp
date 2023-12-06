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
	// Check if the credentials match the manager's credentials
	if (name == "manager" && password == "admin") {
		return Manager(true);
	}
	return Manager(false);
}