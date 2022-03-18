#include <boost/test/unit_test.hpp>
#include "workbookmanager.h"


BOOST_AUTO_TEST_SUITE(TestWorkbookManager)

    BOOST_AUTO_TEST_CASE(testWorkbookManager_LoadMovies) {

        WorkbookManager * workbookManager = WorkbookManager::GetInstance();

        auto movieRegistry = std::move(workbookManager->loadMovies());
        auto roomRegistry = std::move(workbookManager->loadRooms());

        auto screenings = std::move(workbookManager->loadScreenings(*movieRegistry, *roomRegistry));
        BOOST_REQUIRE_EQUAL(screenings->at(0)->getPrice(), 10);
    }

BOOST_AUTO_TEST_SUITE_END()