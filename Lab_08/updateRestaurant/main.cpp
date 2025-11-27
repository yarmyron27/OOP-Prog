#include <iostream>
#include "order.h"
using namespace std;

int main() {
    Order myOrder;
    string dishToRemove;
    string name;
    int count = 0;
    double price = 0;

    myOrder.printMenu();

    cout << "Add dish in map..." << endl;
    myOrder.addDish("Borshch", 2, 3.50);
    myOrder.addDish("Pizza Paperoni", 1, 4.00);
    myOrder.addDish("Compot", 3, 0.50);

    cout << "\nCurent Order:" << endl;
    myOrder.printOrder();

    cout << "\nTotal price: $" << myOrder.calculateTotal() << endl;

    cout << "Enter dish name to remove: ";
    getline(cin, dishToRemove);
    myOrder.removeDish(dishToRemove);

    cout << "Enter name dish to add: ";
    getline(cin, name);
    cout << "Enter count: ";
    cin >> count;
    cin.ignore();
    myOrder.addDishAuto(name, count);

    cout << "\nUpdate order:" << endl;
    myOrder.printOrder();
    cout << "\nNew price: $" << myOrder.calculateTotal() << endl;

    cout << "Add recurring dish in multimap..." << endl;
    myOrder.addRepeatedOrder("Borshch", 3.50);
    myOrder.addRepeatedOrder("Borshch", 3.50);
    myOrder.addRepeatedOrder("Compot", 0.50);

    myOrder.showMostExpensive();

    cout << "Unique names of dishes in the order:" << endl;
    myOrder.printUniqueDishes();

    myOrder.undoLastAction();
    myOrder.undoLastAction();

    myOrder.addToQueue("Borshch");
    myOrder.addToQueue("Pizza Paperoni");
    myOrder.addToQueue("Cezar");

    cout << "\nOrder queue" << endl;
    myOrder.processNextOrder();
    myOrder.processNextOrder();
    myOrder.processNextOrder();
    myOrder.processNextOrder();

    return 0;
}
