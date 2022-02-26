#include <utility>
#include "room.h"

Room::Room(std::string name, unsigned int rows, unsigned int seatsInRow) {

    this->name = std::move(name);
    this->rows = rows;
    this->seatsInRow = seatsInRow;

    seats = new Seat * [rows];
    for(int i = 0; i < rows; i++){
        seats[i] = new Seat[seatsInRow];
        for(int j = 0; j < seatsInRow; j++){
            seats[i][j] = Seat(i, j);
        }
    }
}

Room::~Room() {

    for(int i = 0; i < rows; i++){
        delete [] seats[i];
    }
    delete [] seats;
}