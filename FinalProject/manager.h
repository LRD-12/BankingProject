#include <string>
#include <vector>
using namespace std;

#ifndef MANAGER_H
#define MANAGER_H

class Manager {
private:
    bool loggedIn;
public:
    Manager(bool loggedIn);
    bool isLoggedIn() const;
    void viewAllAccounts() const;
    void deleteAccount(int accountNumber);
};
#endif
