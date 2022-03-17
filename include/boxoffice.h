#ifndef OOP21_WW_03_BOXOFFICE_H
#define OOP21_WW_03_BOXOFFICE_H

#include <vector>
#include <memory>
#include <iostream>
#include <string>
#include "normal.h"
#include "reduced.h"

class BoxOffice {

    std::vector<std::shared_ptr<Ticket>> tickets;

public:

    BoxOffice() = default;

    static std::shared_ptr<Normal> buyNormalTicket(const std::shared_ptr<Screening>& screening, Seat * seat);
    static std::shared_ptr<Reduced> buyReducedTicket(const std::shared_ptr<Screening>& screening, Seat *seat, int discount);

};

#endif //OOP21_WW_03_BOXOFFICE_H
