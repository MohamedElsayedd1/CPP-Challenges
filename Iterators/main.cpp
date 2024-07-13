#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <set>

using namespace std;

void test1(void){
    cout << "==================================\n";
    vector<int> vec {1, 2, 3, 4, 5};
    vector<int>::iterator it1 = vec.begin(); // points to 1
    cout << *it1 << endl; // 1
    it1++; // points to 2
    cout << *it1 << endl; // 2
    it1 += 2; // points to 4
    cout << *it1 << endl;
    it1--; // points to 3
    cout << *it1 << endl;
    it1 = vec.end() - 1; // points to 5
    cout << *it1 << endl; // 5
}

void test2(void){
    cout << "==================================\n";
    vector<int> vec {1, 2, 3, 4, 5};
    vector<int>::iterator it1 = vec.begin(); // points to 1
    while(it1 != vec.end()){ // iterate over all vector elements
        cout << *it1 << endl;
        it1++; 
    }

    cout << "==================================\n";

    auto it2 = vec.begin();
    while(it2 != vec.end()){
        *it2 = 0;   // change all vector elements to zero
        cout << *it2 << endl; 
        it2++;
    }

}
 
void test3(void){
    cout << "==================================\n";
    vector<int> vec {1, 2, 3, 4, 5};
    vector<int>::const_iterator it1 = vec.begin(); // auto t1 = vec.cbegin(); -> constant iterator
    while(it1 != vec.end()){
        cout << *it1 << endl;
        it1++;
    }

    cout << "==================================\n";

    it1 = vec.begin();
    while(it1 != vec.end()){
        // *it1 = 0; // copile error - read only
        it1++;
    }
}

void test4(void){
    vector<int> vec {1, 2, 3, 4};
    auto it1 = vec.rbegin(); // points to 4
    cout << *it1 << endl;
    it1++; // points to 3
    cout << *it1 << endl;
    cout << "==================================\n";

    vector<string> names {"Larry", "Moe", "Curly"};
    auto it2 = names.crbegin(); // points to "curly", and can't change elements;
    while(it2 != names.crend()){
        cout << *it2 << endl;
        it2++; // points to moe then larry
    }
    cout << "==================================\n";

    map<string, string> pairs {{"Mohamed", "C++"}, {"Khaled", "C#"}, {"Ibrahim", "Java"}};
    auto it3 = pairs.begin();
    while(it3 != pairs.end()){
        cout << it3->first << " : " << it3->second << endl;
        it3++;
    }
}

void test5(void){
    cout << "==================================\n";
    vector<char> chars {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'K', 'L'};
    auto it1 = chars.begin() + 2; // points at 'C'
    auto it2 = chars.end() - 3; // points to 'H'
    while(it1 != it2){
        cout << *it1 << " ";
        it1++;
    }
}

int main()
{
    test1();
    test2();
    test3();
    test4();
    test5();
    return 0;
}

