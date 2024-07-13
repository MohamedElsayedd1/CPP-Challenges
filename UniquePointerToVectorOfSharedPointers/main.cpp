#include <iostream>
#include <vector>
#include <memory> // For smart pointers

using namespace std;

class Test {
private:
    int data;
public:
    Test() : data(0) { cout << "\tTest constructor (" << data << ")" << endl; }
    Test(int d) : data(d) { cout << "\tTest constructor (" << data << ")" << endl; }
    ~Test() { cout << "\tTest destructor(" << data << ")" << endl; }
    friend ostream &operator<<(ostream &os, const Test &obj);
};

ostream &operator<<(ostream &os, const Test &obj) {
    os << obj.data;
    return os;
}

unique_ptr<vector<shared_ptr<Test>>> make() {
    return make_unique<vector<shared_ptr<Test>>>();
}

void fill(vector<shared_ptr<Test>> &vec, const int size) {
    int temp;
    for (int i = 0; i < size; ++i) {
        cout << "Enter data[" << i + 1 << "] : ";
        cin >> temp;
        vec.push_back(make_shared<Test>(temp));
    }
}

void display(const vector<shared_ptr<Test>> &vec) {
    cout << "=========================\n";
    for (const auto &ptr : vec) {
        cout << *ptr << endl;
    }
    cout << "=========================\n";
}

void fillUniquePtr(unique_ptr<vector<shared_ptr<Test>>> &vec, const int size) {
    int temp;
    for (int i = 0; i < size; ++i) {
        cout << "Enter data[" << i + 1 << "] : ";
        cin >> temp;
        vec->push_back(make_shared<Test>(temp));
    }
}

void displayUniquePtr(const unique_ptr<vector<shared_ptr<Test>>> &vec) {
    cout << "=========================\n";
    for (size_t i = 0; i < vec->size(); i++) {
        cout << *(vec->at(i)) << endl;
    }
    cout << "=========================\n";
}

int main() {
    unique_ptr<vector<shared_ptr<Test>>> vec_ptr = make();
    int size;
    
    cout << "Enter the number of elements you want to add : ";
    cin >> size;
    
    fill(*vec_ptr, size);
    display(*vec_ptr);

    vec_ptr->clear();

    cout << "===========================\n";
    
    cout << "Enter the number of elements you want to add : ";
    cin >> size;
    
    fillUniquePtr(vec_ptr, size);
    displayUniquePtr(vec_ptr);

    return 0;
}

