#ifndef CINEMATICKETS_ROOM_H
#define CINEMATICKETS_ROOM_H

#include <string>
#include "seat.h"

class Room{

    std::string name{"ExampleName"};
    unsigned int rows{0};
    unsigned int seatsInRow{0};

public:
    Room(std::string name, unsigned int rows, unsigned int seatsInRow);
    ~Room() = default;

    //Getters
    const std::string &getName() const {return name;}
    unsigned int getRows() const {return rows;};
    unsigned int getSeatsInRow() const {return  seatsInRow;};
};

#endif //CINEMATICKETS_ROOM_H
