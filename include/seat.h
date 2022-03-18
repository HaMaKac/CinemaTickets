#ifndef CINEMATICKETS_SEAT_H
#define CINEMATICKETS_SEAT_H

#include <string>

enum Availability{
    AVAILABLE = 0,
    OCCUPIED = 1
};

class Seat{

    unsigned int rowNumber;
    unsigned int seatNumber;
    Availability availability{AVAILABLE};

public:
    Seat(unsigned int rowNumber = 0, unsigned int seatNumber = 0);
    ~Seat() = default;

    void setAvailability(Availability available);

    //Getters
    std::string getAvailability();
    unsigned int getRowNumber();
    unsigned int getSeatNumber();

};

#endif //CINEMATICKETS_SEAT_H