#include <climits>
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

    for (auto row : worksheet.rows(false))
    {
        unsigned int time;
        int rownum, number;
        std::string roomName;
        for (auto cell : row)
        {
            if(!cell.has_value()) continue;
            switch(cell.column_index()){
                case 10:
                    time = atoi(cell.to_string().c_str());
                    break;
                case 11:
                    roomName = cell.to_string();
                    break;
                case 12:
                    rownum = atoi(cell.to_string().c_str());
                    break;
                case 13:
                    number = atoi(cell.to_string().c_str());
                    break;
            }
        }

        for(auto screening : *screenings){
            if(screening->getTime() == time && screening->getRoom()->getName() == roomName){
                screening->occupySeat(rownum, number);
            }
        }
    }

    return screenings;
}

bool WorkbookManager::canSellTicket(std::shared_ptr<Ticket> ticket) {

    bool repeats = true;

    for (auto row : worksheet.rows(false))
    {
        bool rowEmpty = true;
        for (auto cell : row)
        {
            if(!cell.has_value()) continue;
            switch(cell.column_index()){
                case 10:
                    rowEmpty = false;
                    if(atoi(cell.to_string().c_str()) != ticket->getScreening()->getTime()) repeats = false;
                    break;
                case 11:
                    rowEmpty = false;
                    if(cell.to_string() != ticket->getScreening()->getRoom()->getName()) repeats = false;
                    break;
                case 12:
                    rowEmpty = false;
                    if(atoi(cell.to_string().c_str()) != ticket->getSeat()->getRowNumber() - 1) repeats= false;
                    break;
                case 13:
                    rowEmpty = false;
                    if(atoi(cell.to_string().c_str()) != ticket->getSeat()->getSeatNumber() - 1) repeats = false;
                    break;
            }
        }
        if(repeats && !rowEmpty) return false;
    }
    return true;
}

void WorkbookManager::saveSoldTicket(std::shared_ptr<Ticket> ticket) {

    for (int rowIdx = 1; rowIdx < INT_MAX; ++rowIdx) {
        if (!worksheet.cell(10, rowIdx).has_value()) {
            worksheet.cell(10, rowIdx).value(ticket->getScreening()->getTime());
            worksheet.cell(11, rowIdx).value(ticket->getScreening()->getRoom()->getName());
            worksheet.cell(12, rowIdx).value(ticket->getSeat()->getRowNumber() - 1);
            worksheet.cell(13, rowIdx).value(ticket->getSeat()->getSeatNumber() - 1);
            break;
        }
    }
    workbook.save(path);
}