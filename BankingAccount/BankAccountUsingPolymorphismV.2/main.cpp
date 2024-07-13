#include <iostream>
using namespace std;
#include "I_Printable.cpp"
#include "Account.cpp"
#include "CheckingAccount.cpp"
#include "Savings.cpp"
#include "TrustAccount.cpp"
#include "Account_Util.cpp"

int main()
{

    vector<Account *> bank_accounts;
    Account *b1 = new Savings{"superman", 1000, 0.05};
    Account *b2 = new CheckingAccount{"thanos", 5000, 5};
    Account *b3 = new TrustAccount{"joe", 5000, 0.5};
    bank_accounts.push_back(b1);
    bank_accounts.push_back(b2);
    bank_accounts.push_back(b3);

    display(bank_accounts);
    deposit(bank_accounts, 1000);
    withdraw(bank_accounts, 2000);

    delete b1;
    delete b2;
    delete b3;



    return 0;
}