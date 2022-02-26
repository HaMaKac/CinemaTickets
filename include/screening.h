#ifndef CINEMATICKETS_SCREENING_H
#define CINEMATICKETS_SCREENING_H
#include <string>
#include <memory>
#include "movie.h"
#include "room.h"

class Screening{

    unsigned int time;
    std::shared_ptr<Movie> movie;
    std::shared_ptr<Room> room;

public:
    Screening(std::shared_ptr<Movie> movie, std::shared_ptr<Room> room, unsigned int time);
    ~Screening();

    //Getters
    std::shared_ptr<Room> getRoom();
    std::string getAll();
    int getPrice();

};

#endif //CINEMATICKETS_SCREENING_H
