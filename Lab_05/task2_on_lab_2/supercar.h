#ifndef SUPERCAR_H
#define SUPERCAR_H

#include <string>
#include <iosfwd>
using namespace std;

class Auto;

class SuperCar {
private:
    Auto* baseCar;
    float maxSpeed;
    string drivetrain;

public:
    SuperCar(Auto* baseCar = nullptr, float maxSpeed = 0.0, string drivetrain = "");
    ~SuperCar();

    void setBaseCar(Auto* supercar);
    void setMaxSpeed(float NewSpeed);
    void setDrivetrain(string NewDrivetrain);

    Auto* getBaseCar();
    float getMaxSpeed();
    string getDrivetrain();

    void printInfo();

    friend ostream& operator<<(ostream& os, SuperCar& s);
};

#endif // SPORTSCAR_H
