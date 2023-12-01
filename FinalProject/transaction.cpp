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