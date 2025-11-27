#ifndef ORDER_H
#define ORDER_H

#include <iostream>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include "Dish.h"
using namespace std;

class Order {
    map<string, pair<int, double>> currentOrder;
    multimap<string, double> repeatedOrders;
    priority_queue<pair<double, string>> expensiveQueue;
    set<string> uniqueDishes;
    stack<string> history;
    queue<string> waitingOrders;
    map<string, double> menuPrices {
        {"Borshch", 3.50},
        {"Pizza Paperoni", 4.00},
        {"Cezar", 1.99},
        {"Compot", 0.50}
    };

public:
    Order() = default;

    void addDish(const string& name, int count, double price);
    void addDishAuto(const string& name, int count);
    void removeDish(const string& name);
    double calculateTotal() const;
    void printOrder() const;
    void printMenu() const;

    void addRepeatedOrder(const string& name, double price);
    void showMostExpensive();
    void printUniqueDishes() const;

    void undoLastAction();
    void addToQueue(const string& name);
    void processNextOrder();
};

#endif // ORDER_H
