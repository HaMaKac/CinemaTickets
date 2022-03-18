#ifndef CINEMATICKETS_ROOM_H
#define CINEMATICKETS_ROOM_H

#include <string>
#include "seat.h"

class Room{

    std::string name;
    unsigned int rows{0};
    unsigned int seatsInRow{0};

public:

    Room(std::string name, unsigned int rows, unsigned int seatsInRow);
    ~Room() = default;

    //Getters
    std::string getName();
    unsigned int getRows();
    unsigned int getSeatsInRow();
};

#endif //CINEMATICKETS_ROOM_H