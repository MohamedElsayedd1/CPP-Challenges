#ifndef ACCOUNT_H
#define ACCOUNT_H

#pragma once
#include <iostream>
#include <string.h>
using namespace std;

class Account
{
protected :
    string name;
    double balance;
public:
    Account();
    Account(string, double);
    Account(const Account &&src); // move constructor
    ~Account();
    bool deposit(double amount);
    bool withdraw(double amount);
    friend ostream &operator<<(ostream &os, const Account &rhs);

};

#endif