#ifndef SAVING_ACCOUNT_H
#define SAVING_ACCOUNT_H

#pragma once
#include "Account.h"

class Saving_Account : public Account
{
protected : 
    double interest_rate;
public:
    Saving_Account();
    Saving_Account(string n, double b, double r);
    Saving_Account(const Saving_Account &&src);
    ~Saving_Account();
    bool deposit(double amount); // deposit base method is overridden
    // withdraw base method is inherited
    friend ostream &operator<<(ostream &os, const Saving_Account &rhs);

};

#endif