#include "user.h"
#include "manager.h"
using namespace std;

#ifndef AUTHENTICATOR_H
#define AUTHENTICATOR_H

class Authenticator {
public:
	static User loginUser(string name, string password);
	static Manager loginManager(string name, string password);
};
#endif