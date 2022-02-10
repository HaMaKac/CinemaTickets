#include "reduced.h"

Reduced::Reduced(unsigned seat, int price, int discount) : Ticket(seat, price) {
    this->discount = discount;
}

double Reduced::getCost() {
    return getPrice()*(1-0.01*getDiscount());
}

int Reduced::getDiscount() {
    return discount;
}

