#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;
void fun(int *x);
void fun2(string *s);
void change_vector(vector<string> *v);
void print_vectors(vector<string> *v);

int main()
{
    vector<string> names = {"larry", "moe", "Ahmed"};

    print_vectors(&names);
    cout << endl;
    change_vector(&names);
    print_vectors(&names);
}

void fun(int *x)
{
    cout << *x << endl;
    *x = 200;
    cout << *x << endl;
}

void fun2(string *s)
{
    *s = "Hellommmm";
}

void change_vector(vector<string> *v)
{
    *v = {"sammy"};
}

void print_vectors(vector<string> *v)
{
    for (auto s : *v)
    {
        cout << s << " ";
    }
}