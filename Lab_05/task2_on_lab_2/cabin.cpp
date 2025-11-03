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

string Cabin::getMat_cabin() {
    return this->mat_cabin;
}
