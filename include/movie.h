#ifndef CINEMATICKETS_MOVIE_H
#define CINEMATICKETS_MOVIE_H

#include <string>

class Movie{

    std::string name;
    int duration;
    int price;

public:
    Movie(std::string name, int duration, int price);
    ~Movie(){};

    //Getters
    const std::string &getName() const {return name;}
    int getDuration() const {return duration;}
    int getPrice() const {return price;}

};

#endif //CINEMATICKETS_MOVIE_H
