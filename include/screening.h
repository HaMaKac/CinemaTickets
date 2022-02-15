#ifndef CINEMATICKETS_SCREENING_H
#define CINEMATICKETS_SCREENING_H

#include <string>
#include "movie.h"
#include "room.h"

class Screening{

    unsigned int time;

public:
    Screening(Movie* movie, Room* room, unsigned int time);
    ~Screening();

    //Getters
    std::string getAll();

};

#endif //CINEMATICKETS_SCREENING_H
