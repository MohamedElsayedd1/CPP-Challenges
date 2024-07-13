#include <iostream>
#include <cctype>
#include <deque>
using namespace std;

bool isPlindrome(const string &s)
{
    deque<char> d1;
    deque<char> d2;
    for (auto const &elem : s)
    {
        if (isalpha(elem))
        {
            d1.push_front(toupper(elem));
            d2.push_back(toupper(elem));
        }
    }
    for (auto const elem : d1)
    {
        cout << elem << " ";
    }
    cout << endl;
    for (auto const elem : d2)
    {
        cout << elem << " ";
    }
    cout << endl;
    for (int i = 0; i < d1.size(); i++)
    {
        if (d1[i] != d2[i])
        {
            return false;
        }
    }
    return true;
}

// string proccess(const string &s){
//     string my;
//     my.reserve(s.size()); // Reserve space to improve efficiency
//     size_t index = 0;
//     for(auto const &elem : s){
//         if(isalpha(elem)){
//             my += (char)toupper(elem);
//             index++;
//         }
//     }
//     return my;
// }

// bool isPlindrome(const string &s)
// {
//     deque<char> d1;
//     deque<char> d2;
//     string newstr = proccess(s);
//     for (auto const &elem : newstr)
//     {
//         d1.push_front(elem);
//         d2.push_back(elem);
//     }
//     for (auto const elem : d1)
//     {
//         cout << elem << " ";
//     }
//     cout << endl;
//     for (auto const elem : d2)
//     {
//         cout << elem << " ";
//     }
//     cout << endl;
//     for (int i = 0; i < d1.size(); i++)
//     {
//         if (d1[i] != d2[i])
//         {
//             return false;
//         }
//     }
//     return true;
// }

int main()
{
    string mystr;
    cout << "Enter string : ";
    getline(cin, mystr);

    if (isPlindrome(mystr))
        cout << "string is palindrome.\n";
    else
        cout << "string is not palindrome.\n";

    return 0;
}