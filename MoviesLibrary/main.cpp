#include <iostream>
using namespace std;

#include "Movie.cpp"
#include "Movies.cpp"

void Add_movie(Movies &m, string n, string r, int t);
void increment_watched(Movies &m, string n);

int main()
{
    Movies obj;
    obj.display();
    Add_movie(obj, "La la land", "PG-13", 3);
    obj.display();
    Add_movie(obj, "Drive", "PG", 1);
    obj.display();
    Add_movie(obj, "La la land", "PG-13", 3);
    obj.display();
    increment_watched(obj, "La la land");
    obj.display();
    Add_movie(obj, "Fury", "PG", 2);
    obj.display();
    increment_watched(obj, "xxx");
    obj.display();


    return 0;
}

void Add_movie(Movies &m, string n, string r, int t)
{
    if (m.add_movie(n, r, t))
    {
        cout << n << " movie is added successfully." << endl;
    }
    else
    {
        cout << n << " movie is already exist." << endl;
    }
}

void increment_watched(Movies &m, string n)
{
    if (m.increment_watching(n))
    {
        cout << n << " movie increamented by 1." << endl;
    }
    else
    {
        cout << n << " movie is not exist." << endl;
    }
}