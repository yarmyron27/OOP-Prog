#include "auto.h"
#include <iostream>
#include <string>
using namespace std;

Auto::Auto(string mark, string model,
           Engine engine, Cabin cabin) {
    this->mark = mark;
    this->model = model;
    this->engine = engine;
    this->cabin = cabin;
}

void Auto::setMark(string new_mark) {
    mark = new_mark;
}
void Auto::setModel(string new_model) {
    model = new_model;
}
void Auto::setEngine(Engine eng) {
    engine = eng;
}
void Auto::setCabin(Cabin cab) {
    cabin = cab;
}

string Auto::getMark() {
    return this->mark;
}
string Auto::getModel() {
    return this->model;
}
Engine Auto::getEngine() {
    return this->engine;
}
Cabin Auto::getCabin() {
    return this->cabin;
}

void Auto::auto_inf() {
    cout << "Mark: " << mark << "\nModel: " << model
         << "\nEngine: " << engine.getType_eng()
         << " " << engine.getCapacity() << "L"
         << "\nengine strenght: " << engine.getStrenght() << "HP"
         << "\nfuel: " << engine.getFuel() << "L\n";

    engine.HasFuel(engine.getFuel());

    cout << "\nCabin material: " << cabin.getMat_cabin()
         << "\nseats: " << cabin.passenger << "\n"
         << "Rate cabin: " << cabin.rate << "\n";
}







