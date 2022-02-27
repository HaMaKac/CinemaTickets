#include "workbookmanager.h"

WorkbookManager* WorkbookManager::workbookManager = nullptr;

WorkbookManager *WorkbookManager::GetInstance() {
    if(workbookManager == nullptr){
        workbookManager = new WorkbookManager;
    }
    return workbookManager;
}

WorkbookManager::WorkbookManager() {
    workbook.load(path);
    worksheet = workbook.active_sheet();
}

std::unique_ptr<Registry<std::shared_ptr<Movie>>> WorkbookManager::loadMovies() {

    auto movieRegistry = std::make_unique<Registry<std::shared_ptr<Movie>>>();

    for (auto row : worksheet.rows(false))
    {
        std::shared_ptr<Movie> newMovie;

        std::string roomName, movieName;
        int time;
        int price;

        for (auto cell : row)
        {
            if(!cell.has_value()) continue;
            switch(cell.column_index()){
                case 1:
                    movieName = cell.to_string();
                    break;
                case 2:
                    time = atoi(cell.to_string().c_str());
                    break;
                case 3:
                    price = atoi(cell.to_string().c_str());
                    newMovie = std::make_shared<Movie>(movieName, time, price);
                    movieRegistry->addItem(std::make_pair(newMovie->getName() ,newMovie));
                    break;
            }
        }
    }

    return movieRegistry;
}

std::unique_ptr<Registry<std::shared_ptr<Room>>> WorkbookManager::loadRooms() {

    auto roomRegistry = std::make_unique<Registry<std::shared_ptr<Room>>>();

    for (auto row : worksheet.rows(false))
    {
        std::shared_ptr<Room> newRoom;

        std::string roomName, movieName;
        int rows;
        int seats;

        for (auto cell : row)
        {
            if(!cell.has_value()) continue;
            switch(cell.column_index()){
                case 4:
                    roomName = cell.to_string();
                    break;
                case 5:
                    rows = atoi(cell.to_string().c_str());
                    break;
                case 6:
                    seats = atoi(cell.to_string().c_str());
                    newRoom = std::make_shared<Room>(roomName, rows, seats);
                    roomRegistry->addItem(std::make_pair(newRoom->getName(), newRoom));
                    break;
            }
        }
    }

    return roomRegistry;
}

std::unique_ptr<std::vector<std::shared_ptr<Screening>>>
WorkbookManager::loadScreenings(Registry<std::shared_ptr<Movie>> movies, Registry<std::shared_ptr<Room>> rooms) {

    auto screenings = std::make_unique<std::vector<std::shared_ptr<Screening>>>();

    for (auto row : worksheet.rows(false))
    {
        std::shared_ptr<Screening> newScreening;

        std::string roomName, movieName;
        int time;

        for (auto cell : row)
        {
            if(!cell.has_value()) continue;
            switch(cell.column_index()){
                case 7:
                    time = atoi(cell.to_string().c_str());
                    break;
                case 8:
                    roomName = cell.to_string();
                    break;
                case 9:
                    movieName = cell.to_string();
                    newScreening = std::make_shared<Screening>(movies.getItemByName(movieName), rooms.getItemByName(roomName), time);
                    screenings->push_back(newScreening);
                    break;
            }
        }
    }

    return screenings;
}

bool WorkbookManager::canSellTicket(Ticket *ticket) {

    for (auto row : worksheet.rows(false))
    {
        for (auto cell : row)
        {
            if(!cell.has_value()) continue;
            switch(cell.column_index()){
                case 10:
                    if(atoi(cell.to_string().c_str()) != ticket->getScreening()->getTime()) return true;
                    break;
                case 11:
                    if(cell.to_string() != ticket->getScreening()->getRoom()->getName()) return true;
                    break;
                case 12:
                    if(atoi(cell.to_string().c_str()) != ticket->getSeat()->getRowNumber()) return true;
                    break;
                case 13:
                    if(atoi(cell.to_string().c_str()) != ticket->getSeat()->getSeatNumber()) return true;
                    break;
            }
        }
    }

    return false;
}

void WorkbookManager::saveSoldTicket(Ticket *ticket) {

    for (auto row : worksheet.rows(false))
    {
        for (auto cell : row)
        {
            if(cell.has_value()) continue;
            switch(cell.column_index()){
                case 10:
                    cell.value(ticket->getScreening()->getTime());
                    break;
                case 11:
                    cell.value(ticket->getScreening()->getRoom()->getName());
                    break;
                case 12:
                    cell.value(ticket->getSeat()->getRowNumber());
                    break;
                case 13:
                    cell.value(ticket->getSeat()->getSeatNumber());
                    break;
            }
        }
    }
}

void WorkbookManager::changeFilenameToLoad(std::string pathToFile) {
    path = std::move(pathToFile);
    workbook.load(path);
    worksheet = workbook.active_sheet();
}