#ifndef AUTO_H
#define AUTO_H
#include <string>

#include "engine.h"
#include "cabin.h"
using namespace std;

class Auto {
private:
    Engine engine;
    Cabin cabin;
    string mark;
    string model;

public:
    Auto(string mark = "", string model = "",
        Engine engine = Engine(), Cabin cabin = Cabin());

    void setMark(string NewMark);
    void setModel(string NewModel);
    void setEngine(Engine eng);
    void setCabin(Cabin cab);

    string getMark();
    string getModel();
    Engine getEngine();
    Cabin getCabin();

    void auto_inf();
};

#endif // AUTO_H
