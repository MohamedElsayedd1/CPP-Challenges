#include "CheckingAccount.h"

CheckingAccount::CheckingAccount(string n , double b , double f ) : Account(n, b), fee{f}{

}


bool CheckingAccount::withdraw(double amount) {
    amount -= fee;
    return Account::withdraw(amount);
}

bool CheckingAccount::deposit(double amount) {
    return Account::withdraw(amount);
}


void CheckingAccount::print(ostream &os) const{
    os << "[Checking_Account -> " << name << " : " << balance << " ," << fee << "$]";
}