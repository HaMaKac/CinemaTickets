#ifndef OOP21_WW_03_NORMAL_H
#define OOP21_WW_03_NORMAL_H

#include "ticket.h"

class Normal : public Ticket {

public:
    Normal(unsigned seat, int price);
    double getCost() override;
};

#endif //OOP21_WW_03_NORMAL_H
