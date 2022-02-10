#include <boost/test/unit_test.hpp>
#include "ticket.h"
#include "normal.h"
#include "reduced.h"

BOOST_AUTO_TEST_SUITE(TestTicketsSuite)

    BOOST_AUTO_TEST_CASE(testNormalTicket_ExpectedCost) {
        Normal normal(5, 20);
        BOOST_CHECK_EQUAL(normal.getCost(), 20);
    }

    BOOST_AUTO_TEST_CASE(testReducedTicket_ExpectedCost) {
        Reduced reduced(11, 10, 20);
        BOOST_CHECK_EQUAL(reduced.getCost(), (1-0.2)*10);
    }

BOOST_AUTO_TEST_SUITE_END()

