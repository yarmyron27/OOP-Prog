#include <iostream>
#include "order.h"
#include "Dish.h"

int main()
{
    Order myOrder;

    myOrder.printMenu();

    myOrder.addDish({"Borshch", 1, 3.50});
    myOrder.addDish({"Pizza Paperoni", 1, 4.00});
    myOrder.addDish({"Compot", 2, 0.50});
    myOrder.printOrder();

    cout << "\nTotal prise: " << myOrder.calculatePrise() << " $" << endl;

    myOrder.removeDishByName("Pizza Paperoni");
    myOrder.addDish({"Cezar", 1, 1.99});

    myOrder.printOrder();
    cout << "\nTotal prise: " << myOrder.calculatePrise() << " $" << endl;

    double threshold = 2.00;
    myOrder.printExpensiveDishes(threshold);
    myOrder.printCheapDishes(threshold);

    return 0;
}
