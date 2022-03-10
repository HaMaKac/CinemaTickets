#ifndef OOP21_WW_03_BOXOFFICE_H
#define OOP21_WW_03_BOXOFFICE_H

#include <vector>
#include <memory>
#include <iostream>
#include <string>
#include "normal.h"
#include "reduced.h"

class BoxOffice {

    int allTicketsCount{0};
    std::vector<std::shared_ptr<Ticket>> tickets;

public:

    BoxOffice() = default;

    static std::shared_ptr<Normal> buyNormalTicket(const std::shared_ptr<Screening>& screening, Seat * seat);
    static std::shared_ptr<Reduced> buyReducedTicket(const std::shared_ptr<Screening>& screening, Seat *seat, int discount);


    bool sellTicket(const std::shared_ptr<Ticket>& tick);

    int getAllTicketsCount() const;
    unsigned long getSoldTicketsCount();
    unsigned long getRemainingTicketsCount();
    double getTotalProfit();

    void displaySoldTickets();
};

#endif //OOP21_WW_03_BOXOFFICE_H
