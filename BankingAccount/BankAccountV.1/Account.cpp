#include "Account.h"

Account::Account() : balance{0.0}, name{"None"}{

}

Account::Account(string n, double b) : balance {b}, name{n}{

}

Account::Account(const Account &&src) : name{src.name}, balance{src.balance}{

} // move constructor

Account::~Account(){

}

bool Account::deposit(double amount){
    balance += amount;
    return true;
}

bool Account::withdraw(double amount){
    if(balance - amount > 0){
        balance -= amount;
        return true;
    }
    else{
        return false;
    }
}

ostream &operator<<(ostream &os, const Account &rhs){
    os << "[Account -> " << rhs.name << " : " << rhs.balance << "]";
    return os;
}