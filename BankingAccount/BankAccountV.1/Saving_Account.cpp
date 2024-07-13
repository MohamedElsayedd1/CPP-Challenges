#include "Saving_Account.h"

Saving_Account::Saving_Account() : Account(), interest_rate(0.0)
{

}

Saving_Account::~Saving_Account()
{

}

Saving_Account::Saving_Account(string name, double amount, double rate) : Account(name, amount), interest_rate{rate}{

}

Saving_Account::Saving_Account(const Saving_Account &&src) : Account(src.name, src.balance) ,interest_rate{src.interest_rate}{

}

bool Saving_Account::deposit(double amount){
    amount += (amount*interest_rate/100);
    return Account::deposit(amount);
}

ostream &operator<<(ostream &os, const Saving_Account &rhs){
    os << "[Saving_Account -> " << rhs.name << " : " <<  rhs.balance << ", " << rhs.interest_rate << "%]";
    return os;
}