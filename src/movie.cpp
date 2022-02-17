#include "movie.h"

Movie::Movie(std::string name, int duration, int price) {
    this->name = name;
    this->duration = duration;
    this->price = price;
}

std::string Movie::toString() {
    return "Name: " + name + ", duration = " + std::to_string(duration) + ", price = " + std::to_string(price);
}
