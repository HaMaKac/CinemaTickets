#include <iostream>
#include <xlnt/xlnt.hpp>
#include "registry.h"
#include "boxoffice.h"
#include "workbookmanager.h"
#include "movie.h"
#include "room.h"
#include "screening.h"

int main() {

    WorkbookManager * workbookManager = WorkbookManager::GetInstance();

    auto movieRegistry = std::move(workbookManager->loadMovies());
    auto roomRegistry = std::move(workbookManager->loadRooms());

    auto screenings = std::move(workbookManager->loadScreenings(*movieRegistry, *roomRegistry));

    for(const auto& screening : *screenings){
        std::clog << screening->getAll() << std::endl;
    }

    std::clog << "Done!";

    return 0;
}
