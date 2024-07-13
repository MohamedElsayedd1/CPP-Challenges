#include <iostream>
#include <memory>
using namespace std;

class IllegalBalanceException{
public : 
    friend ostream &operator<<(ostream &os, const IllegalBalanceException &obj);
};

class Account{
private : 
    string name;
    double balance;
public : 
    Account(string n, double b) : name{n}, balance{b}{
        if(balance < 0.0){
            throw IllegalBalanceException();
        }
    }
    Account() : name{"None"}, balance{0.0}{
        
    }
    ~Account(){

    }
    friend ostream &operator<<(ostream &os, const Account &obj);
};

int main()
{
    try{
        unique_ptr<Account> acc = make_unique<Account>("Larry", -10);
        cout << *acc << endl;
    }
    catch(const IllegalBalanceException &ex){
        cout << ex << endl;
    }
    
    return 0;
}

ostream &operator<<(ostream &os, const IllegalBalanceException &obj){
    os << "Couldn't create account - nagative balance.";
    return os;
}

ostream &operator<<(ostream &os, const Account &obj){
    os << "[Account : " << obj.name << ", " << obj.balance <<"]";
    return os;
}