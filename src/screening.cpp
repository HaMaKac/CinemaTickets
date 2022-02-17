#include "screening.h"

Screening::Screening(Movie *movie, Room *room, unsigned int time) {
    this->time = time;
    this->room = room;
    this->movie = movie;
}

Screening::~Screening() {

}

std::string Screening::getAll() {
    return std::string();
}