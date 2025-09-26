#include "engine.h"
#include <iostream>
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

void Engine::HasFuel(float getFuel){
    if (getFuel > 0){
        cout << "Engine start No problem";
    } else {
        cout << "Engine Caput\n Error: No fuel";
    }
}
