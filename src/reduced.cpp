#include "reduced.h"

Reduced::Reduced(std::shared_ptr<Screening> screening, Seat * seat, int discount) : Ticket(screening, seat) {
    this->discount = discount;
}

double Reduced::getCost() {
    return getPrice()*(1-0.01*getDiscount());
}

int Reduced::getDiscount() {
    return discount;
}

