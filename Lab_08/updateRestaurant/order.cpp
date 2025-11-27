#include "order.h"
#include <algorithm>

void Order::addDish(const string& name, int count, double price) {
    currentOrder[name] = {count, price};
    uniqueDishes.insert(name);
    expensiveQueue.push({price, name});
    history.push("Added: " + name);
}

void Order::removeDish(const string& name) {
    if (currentOrder.erase(name)) {
        history.push("Removed: " + name);
        uniqueDishes.erase(name);

        auto range = repeatedOrders.equal_range(name);
        repeatedOrders.erase(range.first, range.second);

        priority_queue<pair<double, string>> rebuilt;
        while (!expensiveQueue.empty()) {
            auto top = expensiveQueue.top();
            expensiveQueue.pop();
            if (top.second != name) rebuilt.push(top);
        }
        expensiveQueue.swap(rebuilt);

        queue<string> newWaiting;
        while (!waitingOrders.empty()) {
            if (waitingOrders.front() != name) newWaiting.push(waitingOrders.front());
            waitingOrders.pop();
        }
        waitingOrders.swap(newWaiting);
    } else {
        cout << "Dish not found: " << name << endl;
    }
}

double Order::calculateTotal() const {
    double total = 0.0;
    for (auto& [name, info] : currentOrder)
        total += info.first * info.second;
    return total;
}

void Order::printOrder() const {
    if (currentOrder.empty()) {
        cout << "Order is empty" << endl;
        return;
    }
    cout << "Current order:" << endl;
    for (auto& [name, info] : currentOrder)
        cout << " * " << name << " (" << info.first << " pcs, $" << info.second << " each)" << endl;
}

void Order::printMenu() const {
    cout << "========= Menu =========" << endl;
    cout << "1. Borshch (3.50 $)" << endl;
    cout << "2. Pizza Paperoni (4.00 $)" << endl;
    cout << "3. Cezar (1.99 $)" << endl;
    cout << "4. Compot (0.50 $)" << endl;
    cout << "=========================" << endl;
}

void Order::addRepeatedOrder(const string& name, double price) {
    repeatedOrders.insert({name, price});
    history.push("Repeated: " + name);
}

void Order::showMostExpensive() {
    if (currentOrder.empty()) {
        cout << "No dishes." << endl;
        return;
    }
    vector<pair<string,double>> prices;
    prices.reserve(currentOrder.size());
    for (auto & [name, info] : currentOrder) {
        prices.emplace_back(name, info.second);
    }
    sort(prices.begin(), prices.end(), [](const auto &a, const auto &b){ return a.second > b.second; });
    cout << "Most expensive dishes:" << endl;
    for (size_t i = 0; i < prices.size() && i < 2; ++i) {
        cout << " * " << prices[i].first << " - $" << prices[i].second << endl;
    }
}

void Order::printUniqueDishes() const {
    cout << "Unique dishes: ";
    for (auto& name : uniqueDishes)
        cout << name << " ";
    cout << endl;
}

void Order::undoLastAction() {
    if (history.empty()) {
        cout << "Nothing to undo." << endl;
        return;
    }
    cout << "Undo action: " << history.top() << endl;
    history.pop();
}

void Order::addToQueue(const string& name) {
    waitingOrders.push(name);
    cout << "Added to cooking queue: " << name << endl;
}

void Order::processNextOrder() {
    if (waitingOrders.empty()) {
        cout << "No pending orders." << endl;
        return;
    }
    cout << "Processing order: " << waitingOrders.front() << endl;
    waitingOrders.pop();
}

void Order::addDishAuto(const string& name, int count) {
    auto iterator = menuPrices.find(name);
    if (iterator != menuPrices.end()) {
        double price = iterator->second;
        addDish(name, count, price);
        cout << "Add dish \"" << name << "\" (" << count << " one/$" << price << ")" << endl;
    } else {
        cout << "Dish \"" << name << "\" not found!" << endl;
    }
}
