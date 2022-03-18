#ifndef CINEMATICKETS_REGISTRY_H
#define CINEMATICKETS_REGISTRY_H

#include <map>
#include <string>

template <class T> class Registry{

    std::map<std::string, T> registeredItems;

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

    void listAllItems() {

        std::cout << "\nList of items in registry:" << std::endl;

        for(std::pair<std::string, T> item : registeredItems){

            std::cout << " > \"" << item.first << "\"" << std::endl;
        }
    }

    T getItemByName(std::string name) {
        try {
            return registeredItems.at(name);
        }
        catch(const std::out_of_range &message){
            std::cerr << message.what();
        }
    }
};

#endif //CINEMATICKETS_REGISTRY_H