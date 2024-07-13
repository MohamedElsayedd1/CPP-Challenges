#ifndef CHECKINGACCOUNT_H
#define CHECKINGACCOUNT_H

#pragma once
#include <string>
#include "Account.h"
#include "I_Printable.h"
using namespace std;

class CheckingAccount : public Account
{
protected :
    double fee;
public:
    CheckingAccount(string n = "None", double b = 0.0, double f = 2.5);
    virtual ~CheckingAccount() = default;
    virtual bool withdraw(double amount) override;
    virtual bool deposit(double amount) override;
    virtual void print(ostream &os) const override;

};

#endif