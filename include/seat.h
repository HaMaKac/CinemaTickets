#ifndef CINEMATICKETS_SEAT_H
#define CINEMATICKETS_SEAT_H

enum Availability{
    AVAILABLE = 0,
    RESERVED = 1,
    OCCUPIED = 2
};

class Seat{

    unsigned int rowNumber;
    unsigned int seatNumber;
    Availability availability{AVAILABLE};

public:
    Seat(unsigned int rowNumber = 0, unsigned int seatNumber = 0);
    ~Seat();

    void setAvailability(Availability available);

    //Getters
    unsigned int getRowNumber() const {return rowNumber;}
    unsigned int getSeatNumber() const {return seatNumber;}
};

#endif //CINEMATICKETS_SEAT_H
