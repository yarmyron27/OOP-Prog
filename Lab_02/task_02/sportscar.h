#ifndef SPORTSCAR_H
#define SPORTSCAR_H

#include <string>
using namespace std;

class Auto;

class SportCar {
private:
    Auto* baseCar;
    float maxSpeed;
    string drivetrain;

public:
    SportCar(Auto* baseCar = nullptr, float maxSpeed = 0.0, const string& drivetrain = "");
    ~SportCar() = default;

    void setBaseCar(Auto* car);
    void setMaxSpeed(float speed);
    void setDrivetrain(const string& type);

    Auto* getBaseCar() const;
    float getMaxSpeed() const;
    string getDrivetrain() const;

    void printInfo();
};

#endif // SPORTSCAR_H
