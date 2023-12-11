#include <string>
#include <vector>
using namespace std;

#ifndef MANAGER_H
#define MANAGER_H

class Manager {
private:
    bool loggedIn;
    void deleteTransactions(int accountNum) const;
public:
    Manager(bool loggedIn);
    bool isLoggedIn() const;
    void viewAllAccounts() const;
    void deleteAccount(int accountNum) const;
};
#endif
