#ifndef MOVIE_H
#define MOVIE_H

#pragma once

#include <string>
#include <iostream>

using namespace std;

class Movie
{
private:
    string name;
    string rating;
    int times_watched;
    static int counter;
public:
    friend class Movies;

    Movie(string n, string r, int t);
    Movie(const Movie &m);
    ~Movie();

    static int get_movie_num();

    void display() const;
    void increment_watched();

};

#endif