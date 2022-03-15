#include "seat.h"

Seat::Seat(unsigned int rowNumber, unsigned int seatNumber) {
    this->rowNumber = rowNumber;
    this->seatNumber = seatNumber;
}

void Seat::setAvailability(Availability available) {
    this->availability = available;
}

std::string Seat::getAvailability() {
    std::string state = std::to_string(availability);
    return state;
}

Seat::~Seat() {

}

std::string Seat::ToString() {
    return "seat row = " + std::to_string(rowNumber) + ", seat number = " + std::to_string(seatNumber);
}
