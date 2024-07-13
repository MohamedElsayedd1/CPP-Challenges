#ifndef ACCOUNT_H
#define ACCOUNT_H

#pragma once
#include "I_Printable.h"
#include <string>
using namespace std;

class Account : public I_Printable
{
protected:
    string name;
    double balance;

public:
    Account(string n = "None", double b = 0.0);
    virtual bool deposit(double amount) = 0;
    virtual bool withdraw(double amount) = 0;
    virtual void print(ostream &os) const override;
    virtual ~Account() = default;
};

#endif