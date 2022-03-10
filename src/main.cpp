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

    //Box office initialization
    BoxOffice boxOffice;

    while(isRunning){
        std::cout << "Type \"1\" to buy a normal ticket." << std::endl;
        std::cout << "Type \"2\" to buy a discounted ticket." << std::endl;
        std::cout << "Type \"3\" to display all registered movies." << std::endl;
        std::cout << "Type \"4\" to display all registered rooms." << std::endl;
        std::cout << "Type \"5\" to display all registered screenings." << std::endl;
        std::cout << "Type \"6\" to exit the app." << std::endl;

        int input, input2;

        std::cin >> input;

        std::shared_ptr<Screening> screening;

        switch(input) {
            case 1:
                std::cout << std::endl << "Enter the screening id:";
                std::cin >> input;

                screening = screenings->at(input);

                std::cout << std::endl << "Enter seat row:";
                std::cin >> input;

                std::cout << std::endl << "Enter seat number:";
                std::cin >> input2;

                boxOffice.buyNormalTicket(screening, screening->occupySeat(input, input2));
                break;
            case 2:
                std::cout << std::endl << "Enter the screening id:";
                std::cin >> input;

                screening = screenings->at(input);

                std::cout << std::endl << "Enter seat row:";
                std::cin >> input;

                std::cout << std::endl << "Enter seat number:";
                std::cin >> input2;

                boxOffice.buyReducedTicket(screening, screening->occupySeat(input, input2), 15);
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
                isRunning = false;
                break;
        }
        std::cout << "Press enter to continue..." << std::endl;
        system("read");
    }

    std::clog << "Done!";

    return 0;
}
