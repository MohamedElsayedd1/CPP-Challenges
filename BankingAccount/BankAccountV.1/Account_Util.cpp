#include "Account_Util.h"

static int trust_withdraw_counter = 0;

void deposit(vector<Account> &accounts, double amount)
{
    cout << "===============Depositing to Accounts================\n";
    for (auto &x : accounts)
    {
        if (x.deposit(amount))
        {
            cout << amount << " is deposited to " << x << endl;
        }
        else
        {
            cout << "Faild deposit of " << amount << "to " << x << endl;
        }
    }
}

void display(vector<Account> &accounts)
{
    cout << "===============Accounts================\n";
    for (auto const & x : accounts)
    {
        cout << x << endl;
    }
}

void withdraw(vector<Account> &accounts, double amount)
{ 
    cout << "===============Withdrawing from Accounts================\n";
    for (auto &x : accounts)
    {
        if (x.withdraw(amount)){
            cout << "withdraw " << amount << " from " << x << endl;
        }
        else{
            cout << "Faild to withraw " << amount << " from " << x << endl;
        }
    }
}


void deposit(vector<Saving_Account> &accounts, double amount)
{
    cout << "===============Depositing to Saving Accounts================\n";
    for (auto &x : accounts)
    {
        if (x.deposit(amount))
        {
            cout << amount << " is deposited to " << x << endl;
        }
        else
        {
            cout << "Faild deposit of " << amount << "to " << x << endl;
        }
    }
}

void display(vector<Saving_Account> &accounts)
{
    cout << "===============Saving Accounts================\n";
    for (auto const &x : accounts)
    {
        cout << x << endl;
    }
}

void withdraw(vector<Saving_Account> &accounts, double amount)
{ 
    cout << "===============Withdrawing from Saving Accounts================\n";
    for (auto &x : accounts)
    {
        if (x.withdraw(amount)){
            cout << "withdraw " << amount << " from " << x << endl;
        }
        else{
            cout << "Faild to withraw " << amount << " from " << x << endl;
        }
    }
}

void display(const vector<Checking_Account> &accounts){
    cout << "===============Checking Accounts================\n";
    for(auto &x : accounts){
        cout << x << endl;
    }
}

void deposit(vector<Checking_Account> &accounts, double amount){
    cout << "===============Depositing to Saving Accounts================\n";
    for(auto &x : accounts){
        if (x.deposit(amount))
        {
            cout << amount << " is deposited to " << x << endl;
        }
        else
        {
            cout << "Faild deposit of " << amount << "to " << x << endl;
        }
    }
}

void withdraw(vector<Checking_Account> &accounts, double amount){
    cout << "===============Withdrawing from Checking Accounts================\n";
    for (auto &x : accounts)
    {
        if (x.withdraw(amount)){
            cout << "withdraw " << amount << " from " << x << endl;
        }
        else{
            cout << "Faild to withraw " << amount << " from " << x << endl;
        }
    }
}

void display(const vector<Trust_Account> &accounts){
    cout << "===============Trust Accounts================\n";
    for(auto &x : accounts){
        cout << x << endl;
    }
}
void deposit(vector<Trust_Account> &accounts, double amount){
    cout << "===============Depositing to Trust Accounts================\n";
    for(auto &x : accounts){
        if (x.deposit(amount))
        {
            cout << amount << " is deposited to " << x << endl;
        }
        else
        {
            cout << "Faild deposit of " << amount << "to " << x << endl;
        }
    }
}

void withdraw(vector<Trust_Account> &accounts, double amount){
    cout << "===============Withdrawing from Trust Accounts================\n";
    trust_withdraw_counter++;
    for (auto &x : accounts)
    {
        if (x.withdraw(amount) && trust_withdraw_counter <= 3){
            cout << "withdraw " << amount << " from " << x << endl;
        }
        else{
            cout << "Faild to withraw " << amount << " from " << x << endl;
        }
    }
}