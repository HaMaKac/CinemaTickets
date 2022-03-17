#include "boxoffice.h"

std::shared_ptr<Normal> BoxOffice::buyNormalTicket(const std::shared_ptr<Screening>& screening, Seat *seat) {
    return std::make_shared<Normal>(screening, seat);
}

std::shared_ptr<Reduced> BoxOffice::buyReducedTicket(const std::shared_ptr<Screening>& screening, Seat *seat, int discount) {
    return std::make_shared<Reduced>(screening, seat, discount);
}