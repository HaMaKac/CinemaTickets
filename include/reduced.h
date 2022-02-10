#ifndef OOP21_WW_03_REDUCED_H
#define OOP21_WW_03_REDUCED_H

#include "ticket.h"

class Reduced : public Ticket {

    int discount{0};

public:
    Reduced(unsigned seat, int price, int discount);
    double getCost() override;
    int getDiscount();
};

#endif //OOP21_WW_03_REDUCED_H
