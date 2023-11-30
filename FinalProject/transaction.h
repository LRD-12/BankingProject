#include<string>
using namespace std;

#ifndef TRANSACTION_H
#define TRANSACTION_H

class Transaction {
private:
	string type;
	double amount;
public:
	Transaction(string type, double amount);
	//~Transaction();
	string getType() const;
	double getAmount() const;
};
#endif