#include "supercar.h"
#include <iostream>
using namespace std;

SuperCar::SuperCar(Auto base, float maxSpeed, string drivetrain)
    : Auto(base), maxSpeed(maxSpeed), drivetrain(drivetrain) {
}

SuperCar::~SuperCar() = default;

void SuperCar::setMaxSpeed(float speed) {
    maxSpeed = speed;
}

void SuperCar::setDrivetrain(string type) {
    drivetrain = type;
}

float SuperCar::getMaxSpeed() {
    return maxSpeed;
}

string SuperCar::getDrivetrain() {
    return drivetrain;
}

void SuperCar::printInfo() {
    auto_inf();
    cout << "Drivetrain: " << drivetrain << "\n";
    cout << "Max speed: " << maxSpeed << " km/h\n";
}
