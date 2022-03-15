#include <boost/test/unit_test.hpp>
#include "boxoffice.h"
#include "ticket.h"
#include "normal.h"
#include "reduced.h"

BOOST_AUTO_TEST_SUITE(TestBoxOfficeSuite)

/*BOOST_AUTO_TEST_CASE(testBoxOffice_NoSoldTickets_ZeroTotalProfit) {
        BoxOffice boxoffice(10);

        BOOST_CHECK_EQUAL(boxoffice.getTotalProfit(), 0);
}

BOOST_AUTO_TEST_CASE(testBoxOffice_FourTickets_SoldTickets_TotalProfit) {
        BoxOffice boxoffice(2);

        std::shared_ptr<Ticket> t1 = std::make_shared<Normal>(1, 10);
        std::shared_ptr<Ticket> t2 = std::make_shared<Normal>(1, 15);
        std::shared_ptr<Ticket> t3 = std::make_shared<Reduced>(5, 10, 50);
        std::shared_ptr<Ticket> t4 = std::make_shared<Reduced>(8, 15, 25);

        boxoffice.sellTicket(t1);
        boxoffice.sellTicket(t2);
        boxoffice.sellTicket(t3);
        boxoffice.sellTicket(t4);

        BOOST_CHECK_EQUAL(boxoffice.getSoldTicketsCount(), 2);
        BOOST_CHECK_EQUAL(boxoffice.getTotalProfit(), 15);
}*/

BOOST_AUTO_TEST_SUITE_END()