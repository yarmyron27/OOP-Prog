#ifndef HEADER_H
#define HEADER_H
#include <string>
using namespace std;

class Country {
private:
    string name;
    string capital;
    int population;

public:
    void setName(string New_name);
    void setCapital(string New_capital);
    void setPopulation(int New_population);

    string getName();
    string getCapital();
    int getPopulation();

    Country();
    Country(string Country_EU, string Capital_EU, int Population_EU);
    ~Country();
};

#endif // HEADER_H
