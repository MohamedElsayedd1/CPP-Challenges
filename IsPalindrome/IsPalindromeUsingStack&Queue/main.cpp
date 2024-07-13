#include <iostream>
#include <cctype>
#include <queue>
#include <stack>
using namespace std;

bool isPlindrome(const string &str)
{
    queue<char> q;
    stack<char> s;
    for(char ch : str){
        if(isalpha(ch)){
            s.push(ch); // puches at front
            q.push(ch); // pushes at back
        }
    }

    while(!s.empty()){
        if(s.top() != q.front()){
            return false;
        }
        else{
            s.pop(); // removes last character added
            q.pop(); // removes first character added
        }
    }
    return true;
}

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