#include "Movie.h"

int Movie::counter {0};

int Movie::get_movie_num(){
    return counter;
}

Movie::Movie(string n, string r, int t) : name(n), rating{r}, times_watched(t){
    counter++;
}

Movie::Movie(const Movie &m): name(m.name), rating{m.rating}, times_watched(m.times_watched){
    counter++;
}


Movie::~Movie(){
    counter--;
}

void Movie::display() const{
    cout << name << ", " << rating << ", " << times_watched << endl;
}

void Movie::increment_watched(){
    times_watched++;
}