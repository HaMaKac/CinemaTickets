#include <iostream>
#include "boxoffice.h"
#include "normal.h"
#include "reduced.h"

int main() {

    std::cout << "Hello, welcome to the box office in the cinema!\n\n";

    std::cout << "How many tickets are available? ";
    int maxTickets = 0;
    std::cin >> maxTickets;

    if (maxTickets >= 0 && maxTickets <= 100){
        BoxOffice boxoffice(maxTickets);
        std::cout << "\nThere are " + std::to_string(maxTickets) + " available tickets.\n\n";

        std::shared_ptr<Ticket> t1 = std::make_shared<Normal>(1, 10);
        boxoffice.sellTicket(t1);

        std::shared_ptr<Ticket> t2 = std::make_shared<Normal>(1, 15);
        boxoffice.sellTicket(t2);

        std::shared_ptr<Ticket> t3 = std::make_shared<Reduced>(5, 10, 50);
        boxoffice.sellTicket(t3);

        std::shared_ptr<Ticket> t4 = std::make_shared<Reduced>(8, 15, 25);
        boxoffice.sellTicket(t4);

        boxoffice.displaySoldTickets();

        std::cout << "\nThere are " + std::to_string(boxoffice.getSoldTicketsCount()) + " sold tickets.\n";

        std::cout << "\nToday the cinema has made " + std::to_string(boxoffice.getTotalProfit()) + " PLN profit. It was a good day. Good night!";

    } else {
        std::cout << "\nThere are 100 seats, that is impossible.\n";
    }

    return 0;
}
