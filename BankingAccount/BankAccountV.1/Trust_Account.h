#ifndef TRUST_ACCOUNT_H
#define TRUST_ACCOUNT_H

#pragma once
#include <string>
#include <iostream>
using namespace std;
#include "Saving_Account.h"

class Trust_Account : public Saving_Account
{
private : 
    const double bouns = 50.0;
public:
    Trust_Account(string n = "None", double b = 0.0, double i = 0.05);
    bool deposit(double amount);
    bool withdraw(double amount);
    friend ostream &operator<<(ostream &os, const Trust_Account &rhs);
};

#endif