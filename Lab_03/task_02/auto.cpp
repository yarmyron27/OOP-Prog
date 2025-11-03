#include "auto.h"
#include <iostream>
#include <string>
using namespace std;

Auto::Auto(string mark, string model,
           string type_eng, float capacity, float strenght, float fuel,
           short passenger, short rate, string mat_cabin)
    : Engine(type_eng, capacity, strenght, fuel),
      Cabin(passenger, rate, mat_cabin),
      mark(mark),
      model(model) {
}

void Auto::setMark(string new_mark) {
    mark = new_mark;
}
void Auto::setModel(string new_model) {
    model = new_model;
}

string Auto::getMark() {
    return this->mark;
}

string Auto::getModel() {
    return this->model;
}

void Auto::auto_inf() {
    cout << "Mark: " << mark << "\nModel: " << model
         << "\nEngine: " << getType_eng()
         << " " << getCapacity() << "L"
         << "\nengine strenght: " << getStrenght() << "HP"
         << "\nfuel: " << getFuel() << "L\n";

    HasFuel();

    cout << "\nCabin material: " << getMat_cabin()
         << "\nseats: " << getPassenger() << "\n"
         << "Rate cabin: " << getRate() << "\n";
}







