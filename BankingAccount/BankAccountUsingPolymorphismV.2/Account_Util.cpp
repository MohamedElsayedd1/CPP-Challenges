#include "Account_Util.h"

void display(const vector<Account*> &accounts){
    cout << "===============Accounts================\n";
    for(auto const x : accounts){
        cout << *x << endl;
    }
}

void deposit(vector<Account*> &accounts, double amount){
    cout << "===============Depositing to Accounts================\n";
    for(auto x : accounts){
        if (x->deposit(amount))
        {
            cout << amount << " is deposited to " << *x << endl;
        }
        else
        {
            cout << "Faild deposit of " << amount << "to " << *x << endl;
        }
    }
}
void withdraw(vector<Account*> &accounts, double amount){
    cout << "===============Withdrawing from Accounts================\n";
    for(auto x : accounts){
        if (x->withdraw(amount))
        {
            cout << amount << " is withdrawn from " << *x << endl;
        }
        else
        {
            cout << "Faild withdraw of " << amount << "from " << *x << endl;
        }
    }
}
