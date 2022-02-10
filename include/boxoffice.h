#ifndef OOP21_WW_03_BOXOFFICE_H
#define OOP21_WW_03_BOXOFFICE_H

#include <vector>
#include <memory>
#include "normal.h"
#include "reduced.h"

class BoxOffice {

    int allTicketsCount{0};
    std::vector<std::shared_ptr<Ticket>> ticket;

public:
    BoxOffice(int allTicketsCount);
    ~BoxOffice();
    int getAllTicketsCount();
    bool sellTicket(std::shared_ptr<Ticket> tick);
    int getSoldTicketsCount();
    int getRemainingTicketsCount();
    double getTotalProfit();
    void displaySoldTickets();
};

#endif //OOP21_WW_03_BOXOFFICE_H
