#ifndef TRUSTACCOUNT_H
#define TRUSTACCOUNT_H

#pragma once
#include "Savings.h"
#include "I_Printable.h"

class TrustAccount : public Savings
{
protected : 
    const double bouns = 50.0;
private :
    int withdraws = 0;
    const int maxWithdraws = 3;
public:
    TrustAccount(string n, double b, double r);
    virtual ~TrustAccount() = default;
    virtual bool deposit(double amount) override;
    virtual bool withdraw(double amount) override;
    virtual void print(ostream &os) const override;
};

#endif