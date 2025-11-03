#include <iostream>
#include "auto.h"
#include <string>
#include "supercar.h"

using namespace std;

int main()
{
    string mark, model, engType, cabinMat, drivetrain;
    float capacity, strenght, fuel, maxSpeed;
    short passenger, rate;

    cout << "Enter mark: ";
    getline(cin, mark);
    cout << "Enter model: ";
    getline(cin, model);

    cout << "Enter engine type: ";
    getline(cin, engType);
    cout << "Enter cabin material: ";
    getline(cin, cabinMat);

    cout << "Enter engine capacity (L): ";
    cin >> capacity;
    cout << "Enter engine power (HP): ";
    cin >> strenght;
    cout << "Enter fuel amount (L): ";
    cin >> fuel;

    cout << "Enter number of seats: ";
    cin >> passenger;
    while (true) {
        cout << "Rate cabin (0-10): ";
        cin >> rate;
        if (rate < 0 || rate > 10) {
            cout << "Enter a 0 < number < 10!\n";
            continue;
        }
        break;
    }

    Auto car(mark, model, engType, capacity, strenght, fuel, passenger, rate, cabinMat);

    cout << "\n--- Car information ---\n";
    car.auto_inf();
    cout << endl;

    cout << "Enter maxspeed: ";
    cin >> maxSpeed;
    cout << "Enter drivetrain: ";
    cin >> drivetrain;

    SuperCar supercar(car, maxSpeed, drivetrain);

    cout << "\n--- SuperCar information ---\n";
    supercar.printInfo();

    return 0;
}
