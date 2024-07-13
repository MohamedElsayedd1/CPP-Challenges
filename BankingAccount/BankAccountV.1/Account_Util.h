#ifndef ACCOUNT_UTIL_H
#define ACCOUNT_UTIL_H

#pragma once

#include <vector>
#include <iostream>
#include "Account.h"
#include "Saving_Account.h"
#include "Checking_Account.h"
#include "Trust_Account.h"


void deposit(vector<Account> &accounts, double amount);
void display(const vector<Account> &accounts);
void withdraw(vector<Account> &accounts, double amount);

void deposit(vector<Saving_Account> &accounts, double amount);
void display(const vector<Saving_Account> &accounts);
void withdraw(vector<Saving_Account> &accounts, double amount);

void display(const vector<Checking_Account> &accounts);
void deposit(vector<Checking_Account> &accounts, double amount);
void withdraw(vector<Checking_Account> &accounts, double amount);

void display(const vector<Trust_Account> &accounts);
void deposit(vector<Trust_Account> &accounts, double amount);
void withdraw(vector<Trust_Account> &accounts, double amount);


#endif