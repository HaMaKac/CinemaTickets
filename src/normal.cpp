#include "normal.h"

Normal::Normal(std::shared_ptr<Screening> screening, Seat * seat) : Ticket(screening, seat) {

}

double Normal::getCost() {
    return getPrice();
}

