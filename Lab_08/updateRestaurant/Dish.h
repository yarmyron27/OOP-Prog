#ifndef DISH_H
#define DISH_H

#include <iostream>
#include <string>
using namespace std;

struct Dish {
    string name;
    unsigned short count = 0;
    double price_one_unit = 0;

    Dish() = default;
    Dish(string name, unsigned short count, double price_one_unit) : name(move(name)), count(count), price_one_unit(price_one_unit) {}
};

#endif // DISH_H
