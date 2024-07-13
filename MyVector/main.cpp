#include <iostream>
using namespace std;

class out_of_range_error
{
private:
    string msg;

public:
    out_of_range_error(string n) : msg{n} {}
    string message(void) const
    {
        return msg;
    }
    ~out_of_range_error() = default;
};

template <typename T>
class Myvector
{
private:
    int index;
    T *data;

public:
    Myvector() : index{-1}, data{nullptr} {};

    Myvector(initializer_list<T> values) : index{-1}, data{nullptr}
    {
        for (auto val : values)
        {
            push(val);
        }
    }

    void push(T var)
    {
        index++;
        T *new_data = new T[index + 1];
        for (size_t i = 0; i < index; i++)
        {
            new_data[i] = data[i];
        }
        delete[] data;
        data = new_data;
        data[index] = var;
    }

    void pull(void)
    {
        if (index < 0)
            throw out_of_range_error("Index out of range");
        index--;
    }

    int size(void)
    {
        return index + 1;
    }

    T at(int indx)
    {
        if (indx < 0 || indx > index)
        {
            throw out_of_range_error("Index out of range");
        }
        return data[indx];
    }

    T &operator[](int indx)
    {
        if (indx < 0 || indx > index)
        {
            throw out_of_range_error("Index out of range");
        }
        return data[indx];
    }
    ~Myvector()
    {
        delete[] data;
    }

    friend ostream &operator<<(ostream &os, const Myvector<T> &obj)
    {
        if (obj.index < 0)
            cout << "[ " << "]";
        for (size_t i = 0; i <= obj.index; i++)
        {
            os << "[ " << obj.data[i] << " ] ";
        }
        return os;
    }
};

class Player
{
private:
    string name;
    double health;
    double xp;

public:
    Player(string n = "None", double h = 0, double x = 0) : name{n}, health{h}, xp{x} {}
    ~Player() = default;
    friend ostream &operator<<(ostream &os, const Player &obj);
};

int main()
{
    try
    {
        Myvector<int> vec;
        cout << vec.size() << endl;
        vec.push(10);
        vec.push(20);
        cout << vec << endl;
        cout << vec.size() << endl;
        vec.pull();
        cout << vec << endl;
        cout << vec.size() << endl;
        vec.push(200);
        vec[0] = 19;
        cout << vec << endl;

        cout << "===========================\n"
             << endl;

        Myvector<string> names{"Mohamed"};
        names.push("Ahmed");
        names.push("Khaled");
        names.push("Joe");
        cout << names << endl;
        cout << names.size() << endl;
        cout << names.at(0) << endl;
        names[0] = "Elsayed";
        names.push("Malik");
        cout << names << endl;
        cout << names.size() << endl;
        cout << names.at(0) << endl;

        cout << "===========================\n"
             << endl;
        Myvector<Player> players{{"Larry", 88, 10}};
        Player p1;
        Player p2{"Hero", 100, 99};
        Player p3{"Anime", 99, 100};
        players.push(p1);
        players.push(p2);
        players.push(p3);
        cout << players << endl;
        players.push(Player("Superhero", 200, 120));
        cout << players << endl;
        players.pull();
        players.pull();
        cout << players << endl;
    }
    catch (const out_of_range_error &ex)
    {
        cout << ex.message() << endl;
    }

    return 0;
}

ostream &operator<<(ostream &os, const Player &obj)
{
    os << obj.name << " " << obj.health << " " << obj.xp;
    return os;
}