#ifndef ITEM_H
#define ITEM_H
#include <iostream>
#include <unordered_map>

struct item{
    int key;
    std::string data;
    item(int key = -1, std::string data = ""){
        this->key = key;
        this->data = data;
    }
};

#endif // ITEM_H
