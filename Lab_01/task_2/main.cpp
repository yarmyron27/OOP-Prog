#include <iostream>
#include <string>

using namespace std;

struct Country {
    string name;
    string capital;
    int population;
};

void setName(Country &c, string newName) {
    c.name = newName;
}
void setCapital(Country &c, string newCapital) {
    c.capital = newCapital;
}
void setPopulation(Country &c, int newPopulation) {
    c.population = newPopulation;
}

string getName(Country c) {
    return c.name;
}
string getCapital(Country c) {
    return c.capital;
}
int getPopulation(Country c) {
    return c.population;
}

int main() {
    Country c;

    setName(c, "Ukraine");
    setCapital(c, "Kyiv");
    setPopulation(c, 37800000);

    cout << "\nCountry: " << getName(c) << endl;
    cout << "Capital: " << getCapital(c) << endl;
    cout << "Population: " << getPopulation(c) << endl;

    Country a = {"Poland", "Warsaw", 38000000};

    cout << "\nCountry: " << getName(a) << endl;
    cout << "Capital: " << getCapital(a) << endl;
    cout << "Population: " << getPopulation(a) << endl;

    return 0;
}
