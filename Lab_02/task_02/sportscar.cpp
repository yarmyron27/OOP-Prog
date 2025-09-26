#include "sportscar.h"
#include "auto.h"
#include <iostream>
using namespace std;

SportCar::SportCar(Auto* baseCar, float maxSpeed, const string& drivetrain)
    : baseCar(baseCar), maxSpeed(maxSpeed), drivetrain(drivetrain) {}

void SportCar::setBaseCar(Auto* car) { baseCar = car; }
void SportCar::setMaxSpeed(float speed) { maxSpeed = speed; }
void SportCar::setDrivetrain(const string& type) { drivetrain = type; }

Auto* SportCar::getBaseCar() const { return baseCar; }
float SportCar::getMaxSpeed() const { return maxSpeed; }
string SportCar::getDrivetrain() const { return drivetrain; }

void SportCar::printInfo() const {
    cout << "\n--- SportCar ---\n";
    if (baseCar) {
        baseCar->auto_inf();
        cout << "\n";
    } else {
        cout << "Base: none\n";
    }
    cout << "Drivetrain: " << drivetrain << "\n";
    cout << "Max speed: " << maxSpeed << " km/h\n";
}
