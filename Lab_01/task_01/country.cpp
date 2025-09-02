#include <iostream>
#include "country.h"

using namespace std;

void Country::setName(string New_name) {
    name = New_name;
}
void Country::setCapital(string New_capital) {
    capital = New_capital;
}
void Country::setPopulation(int New_population) {
    population = New_population;
}

string Country::getName() {
    return name;
}
string Country::getCapital() {
    return capital;
}
int Country::getPopulation() {
    return population;
}

Country::Country() {
    name = "nul";
    capital = "nul";
    population = 0;
    cout << "constructor called" << endl;
}

Country::Country(string Country_EU, string Capital_EU, int Population_EU) {
    name = Country_EU;
    capital = Capital_EU;
    population = Population_EU;
    cout << "\nconstructor with parameters called" << endl;
}

Country::~Country() {
    cout << "\ndestructor called" << endl;
}
