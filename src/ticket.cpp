#include "ticket.h"

Ticket::Ticket(std::shared_ptr<Screening> screening, Seat *seat) {
    this->screening = std::move(screening);
    this->seat = seat;
}

std::shared_ptr<Screening> Ticket::getScreening() {
    return screening;
}

Seat * Ticket::getSeat() {
    return seat;
}

int Ticket::getPrice() {
    return this->screening->getPrice();
}
