#ifndef CABIN_H
#define CABIN_H
#include <string>
using namespace std;

class Cabin {
private:
    short passenger;
    short rate;
    string mat_cabin;

public:
    Cabin(short passenger = 0, short rate = 0, string mat_cabin = "");
    ~Cabin();

    void setPassenger(short NewPassenger);
    void setRate(short NewRate);
    void setMat_cabin(string NewMat_cabin);

    short getPassenger();
    short getRate();
    string getMat_cabin();
};

#endif // CABIN_H
