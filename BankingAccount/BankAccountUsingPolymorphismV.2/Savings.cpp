#include "Savings.h"

Savings::Savings(string n , double b, double r) : Account(n, b), interest_rate{r}{

}

Savings::~Savings(){

}

bool Savings::deposit(double amount){
    amount += (amount*interest_rate/100);
    return Account::deposit(amount);
}

bool Savings::withdraw(double amount){
    return Account::withdraw(amount);
}

void Savings::print(ostream &os) const{
    os << "[Saving_Account -> " << name << " : " <<  balance << ", " << interest_rate << "%]";
}