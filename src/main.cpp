#include <iostream>
#include <xlnt/xlnt.hpp>
#include "registry.h"
#include "boxoffice.h"
#include "normal.h"
#include "reduced.h"
#include "movie.h"

int main() {

    std::vector<std::shared_ptr<Movie>> movies;

    xlnt::path path("../workbook.xlsx");

    xlnt::workbook workbook;
    workbook.load(path);

    xlnt::worksheet worksheet = workbook.active_sheet();
    for (auto row : worksheet.rows(false))
    {
        std::string name;
        int duration;
        int price;

        for (auto cell : row)
        {
            switch(cell.column_index()){
                case 1:
                    name = cell.to_string();
                    break;
                case 2:
                    duration = atoi(cell.to_string().c_str());
                    break;
                case 3:
                    price = atoi(cell.to_string().c_str());
                    break;
            }
        }
        workbook.save(path);

        auto newMovie = std::make_shared<Movie>(name, duration, price);
        movies.push_back(newMovie);
    }

    //Just for the sake of testing the registries...
    //I still need to add some functionality to registries, but I'm too tired now...
    auto movieRegistry = std::make_unique<Registry<Movie>>();

    for(auto movie : movies){
        movieRegistry->addItem(std::make_pair(movie->getName() ,*movie));
    }

    for(auto movie : movies){
        std::clog << movieRegistry->getItemByName(movie->getName()).toString() << std::endl;
    }


    std::clog << "Done!";



/*    std::cout << "Hello, welcome to the box office in the cinema!\n\n";

    std::cout << "How many tickets are available? ";
    int maxTickets = 0;
    std::cin >> maxTickets;

    if (maxTickets >= 0 && maxTickets <= 100){
        BoxOffice boxoffice(maxTickets);
        std::cout << "\nThere are " + std::to_string(maxTickets) + " available tickets.\n\n";

        std::shared_ptr<Ticket> t1 = std::make_shared<Normal>(1, 10);
        boxoffice.sellTicket(t1);

        std::shared_ptr<Ticket> t2 = std::make_shared<Normal>(1, 15);
        boxoffice.sellTicket(t2);

        std::shared_ptr<Ticket> t3 = std::make_shared<Reduced>(5, 10, 50);
        boxoffice.sellTicket(t3);

        std::shared_ptr<Ticket> t4 = std::make_shared<Reduced>(8, 15, 25);
        boxoffice.sellTicket(t4);

        boxoffice.displaySoldTickets();

        std::cout << "\nThere are " + std::to_string(boxoffice.getSoldTicketsCount()) + " sold tickets.\n";

        std::cout << "\nToday the cinema has made " + std::to_string(boxoffice.getTotalProfit()) + " PLN profit. It was a good day. Good night!";

    } else {
        std::cout << "\nThere are 100 seats, that is impossible.\n";
    }*/

    return 0;
}
