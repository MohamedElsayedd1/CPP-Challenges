#ifndef CHECKING_ACCOUNT_H
#define CHECKING_ACCOUNT_H

#pragma once
#include "Account.h"
#include <string>
using namespace std;

class Checking_Account : public Account
{
protected: 
    double fee;
public:
    Checking_Account(string n = "None", double b = 0.0, double f = 1.50);
    bool withdraw(double amount);
    // deposit method will be inherited.
    friend ostream &operator<<(ostream &os, const Checking_Account &rhs);
};

#endif