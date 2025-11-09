#include "order.h"

Order::Order(const initializer_list<Dish>& list) {
    for (const auto& dish : list) curentOrder.push_back(dish);
}

void Order::printDishDetails(const Dish& dish) const {
    cout << "Dishes: \"" << dish.name << "\" "
         << "(Count: " << dish.count
         << ", Prise: " << dish.prise_one_unit << " $/one)";
}

void Order::addDish(const Dish& dish) { curentOrder.push_back(dish); }

double Order::calculatePrise() const {
    double total = 0.0;
    for (const Dish& dish : curentOrder) {
        total += dish.count * dish.prise_one_unit;
    }
    return total;
}

void Order::removeDishByName(const string& name) {
    for (auto counter = curentOrder.begin(); counter != curentOrder.end(); ) {
        if (counter->name == name) counter = curentOrder.erase(counter);
        else ++counter;
    }
}

void Order::printOrder() const {
    if (curentOrder.empty()) {
        cout << "Order is empty" << endl;
        return;
    }
    cout << "Curent Order: " << endl;
    for (const Dish& dish : curentOrder) {
        cout << " *";
        printDishDetails(dish);
        cout << endl;
    }
}

void Order::printMenu() const {
    cout << "========= Menu Restorant =========" << endl;
    cout << "1. Borshch (3.50 $)" << endl;
    cout << "2. Pizza Paperoni (4.00 $)" << endl;
    cout << "3. Cezar (1.99 $)" << endl;
    cout << "4. Compot (0.50 $)" << endl;
    cout << "====================================" << endl;
}

void Order::printExpensiveDishes(double threshold) const {
    cout << "Over prise menu  > " << threshold << "$ " << endl;
    bool found = false;
    for (const Dish& dish : curentOrder) {
        if (dish.prise_one_unit > threshold) {
            cout << " *";
            printDishDetails(dish);
            cout << endl;
            found = true;
        }
    }
    if (!found) cout << "Dish is empty" << endl;
}

void Order::printCheapDishes(double threshold) const {
    cout << "Cheap prise menu  < " << threshold << "$ " << endl;
    bool found = false;
    for (const Dish& dish : curentOrder) {
        if (dish.prise_one_unit < threshold) {
            cout << " *";
            printDishDetails(dish);
            cout << endl;
            found = true;
        }
    }
    if (!found) cout << "Dish is empty" << endl;
}


