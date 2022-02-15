#include "registry.h"

template<class Item>
Registry<Item>::Registry(std::initializer_list <std::pair<std::string, Item>> share_states) {
    for(const std::pair<std::string, Item> &ss : share_states){
        this->registeredItems.insert(ss);
    }
}

template<class Item>
std::string Registry<Item>::addItem(std::string name, Item item) {

    registeredItems.insert(name, item);
    return name;
}

template<class Item>
Item Registry<Item>::getItemByName(std::string name) {
    return registeredItems.at(name);
}
