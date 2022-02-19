#ifndef CINEMATICKETS_ROOM_H
#define CINEMATICKETS_ROOM_H

#include <string>
#include "seat.h"

class Room{

    std::string name{"ExampleName"};
    unsigned int rows{0};
    unsigned int seatsInRow{0};
    Seat** seats;

public:
    Room(std::string name, unsigned int rows, unsigned int seatsInRow);
    ~Room();

    //Getters
    const std::string &getName() const {return name;}
    unsigned int getRows() {return rows;};
    unsigned int getSeatsInRow() {return  seatsInRow;};
};

#endif //CINEMATICKETS_ROOM_H
