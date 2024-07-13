#include "Trust_Account.h"




Trust_Account::Trust_Account(string n, double b, double i) : Saving_Account(n, b ,i){

}

bool Trust_Account::deposit(double amount){
    if(amount >= 5000)
        amount += bouns;
    return Saving_Account::deposit(amount);
}

bool Trust_Account::withdraw(double amount){
    if(amount < 0.2*balance){
        Saving_Account::withdraw(amount);
    }
    else{
        return false;
    }
}

ostream &operator<<(ostream &os, const Trust_Account &rhs){
    os << "[Trust_Account -> " << rhs.name << " : " <<  rhs.balance << ", " << rhs.interest_rate << "%]";
    return os;
}