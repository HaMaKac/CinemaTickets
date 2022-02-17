#include "seat.h"

Seat::Seat(unsigned int rowNumber, unsigned int seatNumber) {
    this->rowNumber = rowNumber;
    this->seatNumber = seatNumber;
}

void Seat::setAvailability(Availability available) {
    this->availability = available;
}

Seat::~Seat() {

}
