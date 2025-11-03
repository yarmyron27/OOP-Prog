#ifndef AUTO_H
#define AUTO_H
#include <string>

#include "engine.h"
#include "cabin.h"
using namespace std;

class Auto : public Engine, public Cabin { 
private:
    string mark;
    string model;

public:
    Auto(string mark = "", string model = "",
         string type_eng = "", float capacity = 0.0, float strenght = 0.0, float fuel = 0.0,
         short passenger = 0, short rate = 0, string mat_cabin = "");

    void setMark(string NewMark);
    void setModel(string NewModel);

    string getMark();
    string getModel();
    void auto_inf();
};

#endif // AUTO_H
