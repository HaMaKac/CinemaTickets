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
    Seat** seats;

public:
    Screening(std::shared_ptr<Movie> movie, std::shared_ptr<Room> room, unsigned int time);
    ~Screening();

    //Getters
    std::string getAll();

    std::shared_ptr<Room> getRoom(){return room;};
    int getPrice(){return movie->getPrice();};
    Seat *occupySeat(int row, int number);
    unsigned int getTime() const{return time;};

};

#endif //CINEMATICKETS_SCREENING_H
