#include "screening.h"

Screening::Screening(std::shared_ptr<Movie> movie, std::shared_ptr<Room> room, unsigned int time) {
    this->time = time;
    this->room = room;
    this->movie = movie;
}

Screening::~Screening() {

}


std::string Screening::getAll() {
    return "Time of screening: " + std::to_string(time) + "\nRoom: " + room->getName() + "\nMovie: " + movie->toString();
}

