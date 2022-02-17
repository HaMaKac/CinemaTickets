#include <iostream>
#include <string>
#include "boxoffice.h"

BoxOffice::BoxOffice(int allTicketsCount) {
    this->allTicketsCount = allTicketsCount;
}

BoxOffice::~BoxOffice() {

}

int BoxOffice::getAllTicketsCount() const {
    return allTicketsCount;
}

bool BoxOffice::sellTicket(const std::shared_ptr<Ticket>& tick) {
    if (getRemainingTicketsCount() > 0) {

        auto i = tickets.begin();

        for (std::shared_ptr<Ticket> i : tickets) {
            if (i->getSeat() == tick->getSeat()) {
                std::cout << "This tickets cannot be sold - the chosen seat is already occupied!\n";
                return false;
            }
        }
        tickets.push_back(tick);
        std::cout << "Ticket sold. Enjoy watching!\n";
        return true;
    } else {
        std::cout << "This tickets cannot be sold - there are no left tickets!\n";
        return false;
    }
}

unsigned long BoxOffice::getSoldTicketsCount() {
    return tickets.size();
}

unsigned long BoxOffice::getRemainingTicketsCount() {
    return getAllTicketsCount()-getSoldTicketsCount();
}

double BoxOffice::getTotalProfit() {
    double totalProfit{0};
    for (const std::shared_ptr<Ticket>& tick : tickets) {
        totalProfit += tick->getCost();
    }
    return totalProfit;
}

void BoxOffice::displaySoldTickets() {
    std::string soldTickets;
    if (getSoldTicketsCount() == 0) {
        std::cout << "No sold tickets!\n";
    } else {
        std::cout << "\nAll sold tickets:\n";
        int i = 0;
        for (const std::shared_ptr<Ticket>& tick : tickets) {
            i++;
            soldTickets += "Ticket " + std::to_string(i) + ": seat " + std::to_string(tick->getSeat()) + ", price " +
                        std::to_string(tick->getPrice()) + ", cost " + std::to_string(tick->getCost()) + "\n";
        }
        std::cout << soldTickets;
    }
}

