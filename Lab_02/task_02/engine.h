#ifndef ENGINE_H
#define ENGINE_H
#include <string>
using namespace std;

class Engine {
private:
    string type_eng;
    float capacity;
    float strenght;
    float fuel;

public:
    void start();

    void setType_eng(string NewType_eng);
    void setCapacity(float NewCapacity);
    void setStrenght(float NewStrenght);
    void setFuel(float NewFuel);

    string getType_eng();
    float getCapacity();
    float getStrenght();
    float getFuel();

    Engine(string type_eng = "", float capacity = 0.0, float strenght = 0.0, float fuel = 0.0);
    ~Engine();
};

#endif // ENGINE_H
