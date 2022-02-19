#ifndef CINEMATICKETS_WORKBOOKMANAGER_H
#define CINEMATICKETS_WORKBOOKMANAGER_H

#include <memory>
#include <vector>
#include <xlnt/xlnt.hpp>
#include "registry.h"
#include "movie.h"
#include "room.h"
#include "screening.h"

class WorkbookManager{

    std::string path{"../workbook.xlsx"};
    xlnt::workbook workbook;
    xlnt::worksheet worksheet;

private:
    WorkbookManager();
    static WorkbookManager* worksheetManager;

public:
    WorkbookManager(WorkbookManager &other) = delete;
    void operator=(const WorkbookManager &) = delete;

    static WorkbookManager *GetInstance();

    std::unique_ptr<Registry<std::shared_ptr<Movie>>> loadMovies();
    std::unique_ptr<Registry<std::shared_ptr<Room>>> loadRooms();
    std::unique_ptr<std::vector<std::shared_ptr<Screening>>> loadScreenings(Registry<std::shared_ptr<Movie>> movies,
                                                                            Registry<std::shared_ptr<Room>> rooms);

    void changeFilenameToLoad(std::string pathToFile);
};

#endif //CINEMATICKETS_WORKBOOKMANAGER_H
