#ifndef OOP21_WW_03_REDUCED_H
#define OOP21_WW_03_REDUCED_H

#include "ticket.h"

class Reduced : public Ticket {

    int discount{0};

public:

    Reduced(std::shared_ptr<Screening> screening, Seat * seat, int discount);

    //Getters
    double getCost() override;
    int getDiscount();
};

#endif //OOP21_WW_03_REDUCED_H