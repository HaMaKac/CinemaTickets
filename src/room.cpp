#include "room.h"

Room::Room(std::string name, unsigned int rows, unsigned int seatsInRow) {

    this->name = name;
    this->rows = rows;
    this->seatsInRow = seatsInRow;
}

std::string Room::getName() {
    return name;
}

unsigned int Room::getRows() {
    return rows;
}

unsigned int Room::getSeatsInRow() {
    return seatsInRow;
}