#include "supercar.h"
#include "auto.h"
#include <iostream>
using namespace std;

SuperCar::SuperCar(Auto* baseCar, float maxSpeed, string drivetrain) {
    this->baseCar = baseCar;
    this->drivetrain = drivetrain;
    this->maxSpeed = maxSpeed;
}
SuperCar::~SuperCar() = default;

void SuperCar::setBaseCar(Auto* car) {
    baseCar = car;
}
void SuperCar::setMaxSpeed(float speed) {
    maxSpeed = speed;
}
void SuperCar::setDrivetrain(string type) {
    drivetrain = type;
}

Auto* SuperCar::getBaseCar() {
    return this->baseCar;
}
float SuperCar::getMaxSpeed() {
    return this->maxSpeed;
}
string SuperCar::getDrivetrain() {
    return this->drivetrain;
}

void SuperCar::printInfo() {
    cout << "\n--- SportCar ---\n";
    if (baseCar) {
        baseCar->auto_inf();
    } else {
        cout << "Base: none\n";
    }
    cout << "Drivetrain: " << drivetrain << "\n";
    cout << "Max speed: " << maxSpeed << " km/h\n";
}
