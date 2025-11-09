#ifndef DISH_H
#define DISH_H

#include <iostream>
#include <string>
using namespace std;

struct Dish {
    string name;
    unsigned short count = 0;
    double prise_one_unit = 0;
};

#endif // DISH_H
