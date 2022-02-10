#include <iostream>
#include <string>
#include "boxoffice.h"

BoxOffice::BoxOffice(int allTicketsCount) {
    this->allTicketsCount = allTicketsCount;
}

BoxOffice::~BoxOffice() {

}

int BoxOffice::getAllTicketsCount() {
    return allTicketsCount;
}

bool BoxOffice::sellTicket(std::shared_ptr<Ticket> tick) {
    if (getRemainingTicketsCount() > 0) {

        std::vector<std::shared_ptr<Ticket>>::iterator i = ticket.begin();

        for (std::shared_ptr<Ticket> i : ticket) {
            if (i->getSeat() == tick->getSeat()) {
                std::cout << "This ticket cannot be sold - the chosen seat is already occupied!\n";
                return false;
            }
        }
        ticket.push_back(tick);
        std::cout << "Ticket sold. Enjoy watching!\n";
        return true;
    } else {
        std::cout << "This ticket cannot be sold - there are no left tickets!\n";
        return false;
    }
}

int BoxOffice::getSoldTicketsCount() {
    return ticket.size();
}

int BoxOffice::getRemainingTicketsCount() {
    return getAllTicketsCount()-getSoldTicketsCount();
}

double BoxOffice::getTotalProfit() {
    double totalProfit{0};
    for (std::shared_ptr<Ticket> tick : ticket) {
        totalProfit += tick->getCost();
    }
    return totalProfit;
}

void BoxOffice::displaySoldTickets() {
    std::string soldTickets{""};
    if (getSoldTicketsCount() == 0) {
        std::cout << "No sold tickets!\n";
    } else {
        std::cout << "\nAll sold tickets:\n";
        int i = 0;
        for (std::shared_ptr<Ticket> tick : ticket) {
            i++;
            soldTickets += "Ticket " + std::to_string(i) + ": seat " + std::to_string(tick->getSeat()) + ", price " +
                        std::to_string(tick->getPrice()) + ", cost " + std::to_string(tick->getCost()) + "\n";
        }
        std::cout << soldTickets;
    }
}

