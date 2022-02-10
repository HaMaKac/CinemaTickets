#include "normal.h"

Normal::Normal(unsigned seat, int price) : Ticket(seat, price) {

}

double Normal::getCost() {
    return getPrice();
}

