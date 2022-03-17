#ifndef OOP21_WW_03_TICKET_H
#define OOP21_WW_03_TICKET_H

#include "seat.h"
#include "screening.h"

class Ticket {

    std::shared_ptr<Screening> screening;
    Seat * seat;

public:
    Ticket(std::shared_ptr<Screening> screening, Seat *seat);
    ~Ticket() = default;

    //Getters
    std::shared_ptr<Screening> getScreening();
    Seat * getSeat();
    int getPrice();
    virtual double getCost() = 0;
};

#endif //OOP21_WW_03_TICKET_H
