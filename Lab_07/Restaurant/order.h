#ifndef ORDER_H
#define ORDER_H

#include <iostream>
#include <string>
#include <vector>
#include "Dish.h"
using namespace std;

class Order
{
    vector<Dish> curentOrder;

public:
    Order() = default;
    Order(const initializer_list<Dish>&);

    void printDishDetails(const Dish& dish) const;
    void addDish(const Dish&);
    void removeDishByName(const string&);
    double calculatePrise() const;
    void printOrder() const;

    void printMenu() const;
    void printExpensiveDishes(double threshold) const;
    void printCheapDishes(double threshold) const;
};

#endif // ORDER_H
