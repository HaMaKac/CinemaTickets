#ifndef CINEMATICKETS_SCREENING_H
#define CINEMATICKETS_SCREENING_H
#include <string>
#include <memory>
#include "movie.h"
#include "room.h"

class Screening{

    unsigned int time;
    std::shared_ptr<Movie> movie;
    std::shared_ptr<Room> room;
    Seat** seats;

public:

    Screening(std::shared_ptr<Movie> movie, const std::shared_ptr<Room>& room, unsigned int time);
    ~Screening();

    //Getters
    std::string getAll();
    int getPrice();
    unsigned int getTime();
    std::shared_ptr<Room> getRoom();
    Seat *getSeat(int row, int number);

    Seat *occupySeat(int row, int number);
    void displaySeats();
};

#endif //CINEMATICKETS_SCREENING_H