#ifndef SAVINGS_H
#define SAVINGS_H

#pragma once
#include "Account.h"
#include "I_Printable.h"

class Savings : public Account
{
protected : 
    double interest_rate;
public:
    Savings(string n = "None", double b = 0.0, double r  = 0.05);
    ~Savings();
    virtual bool deposit(double amount) override;
    virtual bool withdraw(double amount) override;
    virtual void print(ostream &os) const override;
};

#endif