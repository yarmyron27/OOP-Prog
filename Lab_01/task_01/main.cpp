#include <iostream>
#include "country.h"

using namespace std;

int main() {
    Country c;

    c.setName("Ukraine");
    c.setCapital("Kyiv");
    c.setPopulation(37800000);

    cout << "\nCountry: " << c.getName() << endl;
    cout << "Capital: " << c.getCapital() << endl;
    cout << "Population: " << c.getPopulation() << endl;

    Country a("Poland", "Warsaw", 38000000);

    cout << "\nCountry: " << a.getName() << endl;
    cout << "Capital: " << a.getCapital() << endl;
    cout << "Population: " << a.getPopulation() << endl;

    return 0;
}
