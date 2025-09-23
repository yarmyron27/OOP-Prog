#include <iostream>
#include <string>

using namespace std;

struct Country {
    string name;
    string capital;
    int population;
};

int main() {
    Country c;

    cout << "Enter country:" << endl;
    cin >> c.name;
    cout << "Enter capital:" << endl;
    cin >> c.capital;
    cout << "Enter population:" << endl;
    cin >> c.population;

    cout << "\nCountry: " << c.name << endl;
    cout << "Capital: " << c.capital << endl;
    cout << "Population: " << c.population << endl;

    Country a = {c.name, c.capital, c.population};

    cout << "\nCountry: " << c.name << endl;
    cout << "Capital: " << c.capital << endl;
    cout << "Population: " << c.population << endl;

    return 0;
}
