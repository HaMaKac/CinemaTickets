#include "ticket.h"

Ticket::Ticket(unsigned seat, int price) {
    this->seat = seat;
    this->price = price;
}

Ticket::~Ticket() {

}

unsigned Ticket::getSeat() {
    return seat;
}

int Ticket::getPrice() {
    return price;
}