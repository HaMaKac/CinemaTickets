#ifndef OOP21_WW_03_TICKET_H
#define OOP21_WW_03_TICKET_H

class Ticket {

    unsigned seat{0};
    int price{0};

public:
    Ticket(unsigned seat, int price);
    ~Ticket();
    unsigned getSeat();
    int getPrice();
    virtual double getCost() = 0;
};

#endif //OOP21_WW_03_TICKET_H
