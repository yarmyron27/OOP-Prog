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
    void setMark(string NewMark);
    void setModel(string NewModel);
    string getMark();
    string getModel();

    void auto_inf();

    Auto(string mark = "", string model = "", Engine engine = Engine(), Cabin cabin = Cabin());
};

#endif // AUTO_H
