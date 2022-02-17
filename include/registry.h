#ifndef CINEMATICKETS_REGISTRY_H
#define CINEMATICKETS_REGISTRY_H

#include <unordered_map>
#include <string>

template <class T> class Registry{

    std::unordered_map<std::string, T> registeredItems;

public:
    Registry() = default;

    Registry(std::initializer_list <std::pair<std::string, T>> share_states) {
        if(empty(share_states)) return;
        for(const std::pair<std::string, T> &ss : share_states){
            this->registeredItems.insert(ss);
        }
    }

    ~Registry() = default;

    std::string addItem(std::pair<std::string, T> pair) {

        registeredItems.insert(pair);
        return pair.first;
    }

    T getItemByName(std::string name) {
        return registeredItems.at(name);
    }
};

#endif //CINEMATICKETS_REGISTRY_H
