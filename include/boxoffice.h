#ifndef OOP21_WW_03_BOXOFFICE_H
#define OOP21_WW_03_BOXOFFICE_H

#include <vector>
#include <memory>
#include "normal.h"
#include "reduced.h"

class BoxOffice {

    int allTicketsCount{0};
    std::vector<std::shared_ptr<Ticket>> tickets;

public:
    BoxOffice(int allTicketsCount);
    ~BoxOffice();
    int getAllTicketsCount() const;
    bool sellTicket(const std::shared_ptr<Ticket>& tick);
    unsigned long getSoldTicketsCount();
    unsigned long getRemainingTicketsCount();
    double getTotalProfit();
    void displaySoldTickets();
};

#endif //OOP21_WW_03_BOXOFFICE_H
