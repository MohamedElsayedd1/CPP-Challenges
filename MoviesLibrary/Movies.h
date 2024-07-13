#ifndef MOVIES_H
#define MOVIES_H

#pragma once
#include <string>
#include <iostream>

using namespace std;
#include <vector>
#include "Movie.h"


class Movies
{
private:
    vector<Movie> movies;
public:
    void display() const;
    bool add_movie(string n, string rate, int t);
    bool increment_watching(string n);
    

};

#endif