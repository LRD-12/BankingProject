#include "user.h"
using namespace std;

#ifndef AUTHENTICATOR_H
#define AUTHENTICATOR_H


class Authenticator {
public:
	static User loginUser(string name, string password);
};

#endif