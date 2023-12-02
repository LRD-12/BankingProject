#include<iostream>
#include<fstream>
#include "transaction.h"
using namespace std;

Transaction::Transaction(string type, double amount) :type(type), amount(amount) {}

Transaction::~Transaction() {}

string Transaction::getType() const {
	return type;
}

double Transaction::getAmount() const {
	return amount;
}

// Saves to 'transactions.txt', accountNum provided as argument since we can't access it directly from Transaction object
void Transaction::saveToFile(int accountNum) const {
	ofstream outputFile("transactions.txt", ios::app);

	if (outputFile.is_open()) {
		outputFile << accountNum << " " << type << " " << amount << endl;
		outputFile.close();
	}
	else {
		cout << "Unable to open file for writing." << endl;
	}
}