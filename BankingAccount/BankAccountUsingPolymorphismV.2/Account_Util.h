#ifndef ACCOUNT_UTIL_H
#define ACCOUNT_UTIL_H

#pragma once
#include <iostream>
#include <vector>
#include "Account.h"

void display(const vector<Account*> &accounts);
void deposit(vector<Account*> &accounts, double amount);
void withdraw(vector<Account*> &accounts, double amount);

#endif