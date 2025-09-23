#include <iostream>
#include "country.h"

using namespace std;

int main() {
    Country c;

    string name;
    string capital;
    int population = 0;

    cout << "Enter country:" << endl;
    cin >> name;
    cout << "Enter capital:" << endl;
    cin >> capital;
    cout << "Enter population:" << endl;
    cin >> population;

    c.setName(name);
    c.setCapital(capital);
    c.setPopulation(population);

    cout << "\nCountry: " << c.getName() << endl;
    cout << "Capital: " << c.getCapital() << endl;
    cout << "Population: " << c.getPopulation() << endl;

    cout << "Enter country:" << endl;
    cin >> name;
    cout << "Enter capital:" << endl;
    cin >> capital;
    cout << "Enter population:" << endl;
    cin >> population;

    Country a(name, capital, population);

    cout << "\nCountry: " << a.getName() << endl;
    cout << "Capital: " << a.getCapital() << endl;
    cout << "Population: " << a.getPopulation() << endl;

    return 0;
}
