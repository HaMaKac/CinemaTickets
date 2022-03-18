#include <iostream>
#include "screening.h"

Screening::Screening(std::shared_ptr<Movie> movie, const std::shared_ptr<Room>& room, unsigned int time) {
    this->movie = movie;
    this->room = room;
    this->time = time;

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

int Screening::getPrice() {
    return movie->getPrice();
}

unsigned int Screening::getTime() {
    return time;
}

std::shared_ptr<Room> Screening::getRoom() {
    return room;
}

Seat *Screening::getSeat(int row, int number) {
    return &seats[row - 1][number - 1];
}

Seat *Screening::occupySeat(int row, int number) {
    seats[row - 1][number - 1].setAvailability(OCCUPIED);
    return &seats[row - 1][number - 1];
}

void Screening::displaySeats() {

    std::cout << std::endl << "0 - available, X - occupied" << std::endl;

    for(int i = 0; i < room->getRows(); i++) {
        std::cout << std::endl;
        for(int j = 0; j < room->getSeatsInRow(); j++) {
            if (seats[i][j].getAvailability() == "0") {
                std::cout << " 0";
            }
            else {
                std::cout << " X";
            }
        }
    }
    std::cout << std::endl << std::endl;
}