#include <iostream>
#include <stdexcept>        // For std::out_of_range exception
#include <initializer_list> // For std::initializer_list
using namespace std;

template <typename T, int N>
class MyArray
{
private:
    T arr[N];

public:
    MyArray() = default;

    MyArray(T var)
    {
        fill(var);
    }

    MyArray(initializer_list<T> values)
    {
        if (values.size() > N)
        {
            throw out_of_range("Initializer list size exceeds array size.");
        }
        int i = 0;
        for (auto const &val : values)
        {
            arr[i++] = val;
        }
    }
    void fill(T var)
    {
        for (auto &elem : arr)
        {
            elem = var;
        }
    }

    void zero(void)
    {
        for (int i = 0; i < N; i++)
        {
            arr[i] = 0;
        }
    }

    void display(void) const
    {
        for (int i = 0; i < N; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    int getSize(void) const
    {
        return N;
    }

    T &operator[](int index)
    {
        if (index >= 0 && index < N)
        {
            return arr[index];
        }
        else
        {
            throw out_of_range("Index is out of range.");
        }
    }

    template <typename U, int M>
    friend ostream &operator<<(ostream &os, const MyArray<U, M> &obj);

    ~MyArray() = default;
};

template <typename T, int N>
ostream &operator<<(ostream &os, const MyArray<T, N> &obj)
{
    for (auto const &elem : obj.arr)
    {
        os << "[ " << elem << " ] ";
    }
    return os;
}

int main()
{
    try
    {
        MyArray<int, 5> arr1; // array of 5 integers
        cout << arr1 << endl; // random numbers
        arr1.zero();
        arr1.display();
        cout << arr1 << endl;
        arr1.fill(50);
        cout << arr1 << endl;
        cout << arr1[2] << endl;
        arr1[3] = 100;
        cout << arr1 << endl;
        cout << arr1.getSize() << endl;

        cout << "============================\n";

        MyArray<string, 10> arr2;
        cout << arr2 << endl;
        arr2.fill("Mohamed");
        cout << arr2 << endl;
        arr2[4] = "Elsayed";
        cout << arr2 << endl;

        cout << "============================\n";

        MyArray<char, 10> arr3('n');
        cout << arr3 << endl; // random characters
        arr2.fill("K");
        cout << arr2 << endl;

        cout << "============================\n";

        MyArray<double, 4> arr4{22.21, 13.67, 15.7};
        cout << arr4 << endl;
        arr4[3] = 33.12;
        cout << arr4 << endl;

        // This will throw an exception, but will be caught below
        cout << "Attempting to access out-of-bounds index:" << endl;
        arr1[5] = 200;

        cout << "============================\n";
    }
    catch (const out_of_range &e)
    {
        cerr << "Caught exception: " << e.what() << endl;
    }

    return 0;
}
