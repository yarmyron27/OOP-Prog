#include "engine.h"
#include <iostream>
#include <ostream>
using namespace std;

Engine::Engine(string type_eng, float capacity, float strenght, float fuel) {
    this->type_eng = type_eng;
    this->capacity = capacity;
    this->strenght = strenght;
    this->fuel = fuel;
}

Engine::~Engine() {}

void Engine::setType_eng(string NewType_eng) {
    type_eng = NewType_eng;
}

void Engine::setCapacity(float NewCapacity) {
    capacity = NewCapacity;
}

void Engine::setStrenght(float NewStrenght) {
    strenght = NewStrenght;
}

void Engine::setFuel(float NewFuel) {
    fuel = NewFuel;
}

string Engine::getType_eng(){
    return this->type_eng;
}

float Engine::getCapacity(){
    return this->capacity;
}

float Engine::getStrenght(){
    return this->strenght;
}

float Engine::getFuel(){
    return this->fuel;
}

bool Engine::HasFuel() {
    return fuel > 0;
}

void Engine::HasFuel(ostream& os) {
    if (HasFuel()) {
        os << "\nEngine start No problem";
    } else {
        os << "\nEngine Caput\n Error: No fuel";
    }
}
