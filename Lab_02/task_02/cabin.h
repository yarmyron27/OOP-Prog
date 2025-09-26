#ifndef CABIN_H
#define CABIN_H
#include <string>
using namespace std;

class Cabin {
private:
    string mat_cabin;

public:
    Cabin(short passenger = 0, short rate = 0, string mat_cabin = "");
    ~Cabin();

    short passenger;
    short rate;

    void setMat_cabin(string NewMat_cabin);

    string getMat_cabin(); 
};

#endif // CABIN_H
