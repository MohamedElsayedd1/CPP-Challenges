#include "Checking_Account.h"


Checking_Account::Checking_Account(string n , double b, double f) : Account(n, b), fee{f}{

}


bool Checking_Account::withdraw(double amount){
    amount += fee;
    return Account::withdraw(amount);
}

ostream &operator<<(ostream &os, const Checking_Account &rhs){
    os << "[Checking_Account -> " << rhs.name << " : " << rhs.balance << " ," << rhs.fee << "$]";
    return os;
}