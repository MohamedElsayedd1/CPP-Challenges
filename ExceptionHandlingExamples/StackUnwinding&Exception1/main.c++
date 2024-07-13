#include <iostream>
using namespace std;

void func_c(){
    cout << "Starting func_c.\n";
    try{
        throw string{"Error !\n"};
    }
    catch(string &ex){
        cout << ex;
    }
    cout << "Ending func_c.\n";
}

void func_b(){
    cout << "Starting func_b.\n";
    try{
        func_c();
    }
    catch(string &ex){
        cout << ex;
    }
    cout << "Ending func_b.\n";
}

void func_a(){
    cout << "Starting func_a.\n";
    func_b();
    cout << "Ending func_a.\n";
}

int main()
{
    cout << "Starting main.\n";
    try{
        func_a();
    }
    catch(string &ex){
        cout << ex;
    }
    cout << "Ending main.\n";
    return 0;
}