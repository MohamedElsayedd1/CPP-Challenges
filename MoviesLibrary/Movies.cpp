#include "Movies.h"

void Movies::display() const
{
    if(!movies.empty()){
        cout << "========================\n";
        cout << "Movies list : " << endl;
        for(int i = 0; i < movies.size(); i++){
            movies[i].display();
        }
        cout << "========================\n";
    }
    else{
        cout << "Sorry, no movies to display" << endl;
    }
}


bool Movies::add_movie(string n, string rate, int t)
{
    bool flag = true;
    for(int i = 0; i < movies.size(); i++){
        if(n == movies[i].name){
            flag = false;
            return flag;
            break;
        }
        else{
            flag = true;
        }
    }
    if(flag == true){
        Movie obj(n, rate, t);
        movies.push_back(obj);
    }
    return flag;
}

bool Movies::increment_watching(string n){
    bool flag = false;
    int i = 0;
    for(i = 0; i < movies.size(); i++){
        if(n == movies[i].name){
            flag = true;
            break;
        }
        else{
            flag = false;
        }
    }
    if(flag == true){
        movies[i].increment_watched();
    }
    return flag;
}