#include "cabin.h"

Cabin::Cabin(short passenger, short rate, string mat_cabin) {
    this->passenger = passenger;
    this->rate = rate;
    this->mat_cabin = mat_cabin;
}

Cabin::~Cabin() {}

void Cabin::setMat_cabin(string NewMat_cabin) {
    mat_cabin = NewMat_cabin;
}

void Cabin::setPassenger(short NewPassenger) {
    passenger = NewPassenger;
}

void Cabin::setRate(short NewRate) {
    rate = NewRate;
}

short Cabin::getPassenger(){
    return passenger;
}

short Cabin::getRate(){
    return rate;
}

string Cabin::getMat_cabin(){
    return this->mat_cabin;
}
