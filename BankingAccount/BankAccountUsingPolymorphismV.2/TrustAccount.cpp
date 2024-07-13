#include "TrustAccount.h"

TrustAccount::TrustAccount(string n, double b, double r) : Savings(n, b, r){

}


bool TrustAccount::deposit(double amount){
    if(amount >= 5000){
        amount += bouns;
    }
    return Savings::deposit(amount);
}

bool TrustAccount::withdraw(double amount){
    if(amount <= 0.2*balance && withdraws < maxWithdraws){
        return Account::withdraw(amount);
    }
    else{
        return false;
    }
}

void TrustAccount::print(ostream &os) const{
    os << "[Trust_Account -> " << name << " : " <<  balance << ", " << interest_rate << "%]";
}