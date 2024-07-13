#include "Account.h"



Account::Account(string n, double b) : name{n}, balance{b}{

}

bool Account::deposit(double amount){
    if(amount > 0){
        balance += amount;
        return true;
    }
    else{
        return false;
    }
}

bool Account::withdraw(double amount){
    if(balance - amount > 0){
        balance -= amount;
        return true;
    }
    return false;
}

void Account::print(ostream &os) const {
    os << "[Account -> " << name << " : " << balance << "]";
}