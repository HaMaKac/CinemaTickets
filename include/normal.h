#ifndef OOP21_WW_03_NORMAL_H
#define OOP21_WW_03_NORMAL_H

#include "ticket.h"

class Normal : public Ticket {

public:

    Normal(std::shared_ptr<Screening>, Seat * seat);

    //Getter
    double getCost() override;
};

#endif //OOP21_WW_03_NORMAL_H
