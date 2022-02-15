#ifndef CINEMATICKETS_REGISTRY_H
#define CINEMATICKETS_REGISTRY_H

#include <unordered_map>
#include <string>

template <class Item> class Registry{

    std::unordered_map<std::string, Item> registeredItems;

public:
    Registry(std::initializer_list <std::pair<std::string, Item>> share_states);
    ~Registry() = 0;

    std::string addItem(std::string name, Item);
    Item getItemByName(std::string name);
};

#endif //CINEMATICKETS_REGISTRY_H
