#ifndef CINEMATICKETS_MOVIE_H
#define CINEMATICKETS_MOVIE_H

#include <string>

class Movie{

    std::string name;
    int duration;
    int price;

public:

    Movie(std::string name, int duration, int price);
    ~Movie() = default;

    std::string toString();

    //Getters
    std::string getName();
    int getPrice();

};

#endif //CINEMATICKETS_MOVIE_H
