#ifndef CABIN_H
#define CABIN_H
#include <string>
using namespace std;

class Cabin {
private:
    string mat_cabin;

public:
    char passenger;
    char rate;

    void setMat_cabin(string NewMat_cabin);

    string getMat_cabin();

    Cabin(char passenger = 0, char rate = 0, string mat_cabin = 0);
    ~Cabin();
};

#endif // CABIN_H
