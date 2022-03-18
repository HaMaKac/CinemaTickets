#ifndef CINEMATICKETS_WORKBOOKMANAGER_H
#define CINEMATICKETS_WORKBOOKMANAGER_H

#include <memory>
#include <vector>
#include <xlnt/xlnt.hpp>
#include "registry.h"
#include "movie.h"
#include "room.h"
#include "screening.h"
#include "ticket.h"

class WorkbookManager{

    std::string path{"../workbook.xlsx"};
    xlnt::workbook workbook;
    xlnt::worksheet worksheet;

    WorkbookManager();
    static WorkbookManager* workbookManager;

public:

    WorkbookManager(WorkbookManager &other) = delete;
    void operator=(const WorkbookManager &) = delete;

    static WorkbookManager *GetInstance();

    std::unique_ptr<Registry<std::shared_ptr<Movie>>> loadMovies();
    std::unique_ptr<Registry<std::shared_ptr<Room>>> loadRooms();
    std::unique_ptr<std::vector<std::shared_ptr<Screening>>> loadScreenings(Registry<std::shared_ptr<Movie>> movies, Registry<std::shared_ptr<Room>> rooms);
    bool canSellTicket(std::shared_ptr<Ticket> ticket);
    void saveSoldTicket(std::shared_ptr<Ticket> ticket);
};

#endif //CINEMATICKETS_WORKBOOKMANAGER_H