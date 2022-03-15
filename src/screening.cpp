#include <iostream>
#include "screening.h"

Screening::Screening(std::shared_ptr<Movie> movie, std::shared_ptr<Room> room, unsigned int time) {
    this->time = time;
    this->room = room;
    this->movie = movie;

    this->seats = new Seat * [room->getRows()];
    for(int i = 0; i < room->getRows(); i++){
        this->seats[i] = new Seat[room->getSeatsInRow()];
        for(int j = 0; j < room->getSeatsInRow(); j++){
            this->seats[i][j] = Seat(i + 1, j + 1);
        }
    }
}

Screening::~Screening() {
    for(int i = 0; i < room->getRows(); i++){
        delete [] this->seats[i];
    }
    delete [] this->seats;
}


std::string Screening::getAll() {
    return "Time of screening: " + std::to_string(time) + "\nRoom: " + room->getName() + "\nMovie: " + movie->toString();
}

Seat *Screening::occupySeat(int row, int number) {
    seats[row][number].setAvailability(OCCUPIED);
    return &seats[row][number];
}

Seat *Screening::getSeat(int row, int number) {
    return &seats[row][number];
}

void Screening::displaySeats() {
    for(int i = 0; i < room->getRows(); i++) {
        std::cout << std::endl;
        for(int j = 0; j < room->getSeatsInRow(); j++){
            if (seats[i][j].getAvailability() == "0") {
                std::cout << " 0";
            }
            else {
                std::cout << " 1";
            }
        }
    }
    std::cout << std::endl << std::endl;
}
