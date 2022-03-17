#include <iostream>
#include "workbookmanager.h"
#include "movie.h"
#include "boxoffice.h"

int main() {

    bool isRunning{true};

    //Workbook manager singleton
    WorkbookManager * workbookManager = WorkbookManager::GetInstance();

    //Registries
    auto movieRegistry = std::move(workbookManager->loadMovies());
    auto roomRegistry = std::move(workbookManager->loadRooms());

    //Screenings vector
    auto screenings = std::move(workbookManager->loadScreenings(*movieRegistry, *roomRegistry));

    while(isRunning){
        std::cout << "Type \"1\" to buy a normal ticket." << std::endl;
        std::cout << "Type \"2\" to buy a discounted ticket." << std::endl;
        std::cout << "Type \"3\" to display all registered movies." << std::endl;
        std::cout << "Type \"4\" to display all registered rooms." << std::endl;
        std::cout << "Type \"5\" to display all registered screenings." << std::endl;
        std::cout << "Type \"6\" to display seat availability." << std::endl;
        std::cout << "Type \"7\" to exit the app." << std::endl;

        int input, input2;

        std::cin >> input;

        std::shared_ptr<Screening> screening;
        std::shared_ptr<Ticket> ticket;

        switch(input) {
            case 1:
                std::cout << std::endl << "Enter the screening id:";
                std::cin >> input;

                screening = screenings->at(input-1);

                std::cout << std::endl << "Enter seat row:";
                std::cin >> input;

                std::cout << std::endl << "Enter seat number:";
                std::cin >> input2;

                if (!(input - 1 >= 0 && input2 - 1 >= 0)) {
                    std::cout << "Wrong seat number" << std::endl;
                    break;
                }

                ticket = BoxOffice::buyNormalTicket(screening, screening->getSeat(input-1, input2-1));

                if(workbookManager->canSellTicket(ticket)){
                    screening->occupySeat(input-1, input2-1);
                    workbookManager->saveSoldTicket(ticket);
                } else {
                    std::cout << "Seat already taken, select a different one" << std::endl;
                }

                break;
            case 2:
                std::cout << std::endl << "Enter the screening id:";
                std::cin >> input;

                screening = screenings->at(input-1);

                std::cout << std::endl << "Enter seat row:";
                std::cin >> input;

                std::cout << std::endl << "Enter seat number:";
                std::cin >> input2;

                if (!(input - 1 >= 0 && input2 - 1 >= 0)) {
                    std::cout << "Wrong seat number" << std::endl;
                    break;
                }

                ticket = BoxOffice::buyReducedTicket(screening, screening->getSeat(input-1, input2-1), 15);

                if(workbookManager->canSellTicket(ticket)){
                    screening->occupySeat(input-1, input2-1);
                    workbookManager->saveSoldTicket(ticket);
                } else {
                    std::cout << "Seat already taken, select a different one." << std::endl;
                }
                break;
            case 3:
                movieRegistry->listAllItems();
                break;
            case 4:
                roomRegistry->listAllItems();
                break;
            case 5:
                for(int i = 0; i < screenings->size(); ++i){
                    std::cout << i + 1 << ".\n" << screenings->at(i)->getAll() << std::endl;
                }
                break;
            case 6:
                std::cout << std::endl << "Enter the screening id:";
                std::cin >> input;

                screening = screenings->at(input-1);
                screening->displaySeats();
                break;
            case 7:
                isRunning = false;
                break;
            default:
                break;
        }
        std::cout << std::endl<<std::endl;
    }

    std::cout << "\nDone!";

    return 0;
}
