#ifndef SUPERCAR_H
#define SUPERCAR_H

#include "auto.h"
#include <string>
using namespace std;

class SuperCar : public Auto {
private:
    float maxSpeed;
    string drivetrain;

public:
    SuperCar(Auto base = Auto(), float maxSpeed = 0.0, string drivetrain = "");
    ~SuperCar();

    void setMaxSpeed(float NewSpeed);
    void setDrivetrain(string NewDrivetrain);

    float getMaxSpeed();
    string getDrivetrain();

    void printInfo();
};

#endif // SPORTSCAR_H
