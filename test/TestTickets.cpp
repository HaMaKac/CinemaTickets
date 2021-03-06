#include <boost/test/unit_test.hpp>
#include "ticket.h"
#include "normal.h"
#include "reduced.h"

BOOST_AUTO_TEST_SUITE(TestTicketsSuite)

    BOOST_AUTO_TEST_CASE(testNormalTicket_ExpectedCost) {
        auto room1 = std::make_shared<Room>("Big", 5, 10);
        auto movie1 = std::make_shared<Movie> ("Shrek", 90, 20);
        auto screening1 = std::make_shared<Screening> (movie1, room1, 14);
        Normal normal1 (screening1, screening1->occupySeat(1,1));
        BOOST_CHECK_EQUAL(normal1.getCost(), 20);
    }

    BOOST_AUTO_TEST_CASE(testReducedTicket_ExpectedCost) {
        auto room1 = std::make_shared<Room>("Small", 3, 6);
        auto movie1 = std::make_shared<Movie> ("Harry Potter", 100, 20);
        auto screening1 = std::make_shared<Screening> (movie1, room1, 10);
        Reduced reduced1 (screening1, screening1->occupySeat(3,5), 10);
        BOOST_CHECK_EQUAL(reduced1.getCost(), 18);
    }

BOOST_AUTO_TEST_SUITE_END()

