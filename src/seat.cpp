#include "seat.h"

Seat::Seat(unsigned int rowNumber, unsigned int seatNumber) {
    this->rowNumber = rowNumber;
    this->seatNumber = rowNumber;
}

void Seat::setAvailability(Availability availability) {
    this->availability = availability;
}

Seat::~Seat() {

}
