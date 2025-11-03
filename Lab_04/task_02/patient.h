#ifndef PATIENT_H
#define PATIENT_H
#include <string>
#include <QString>
#include "person.h"
#include <string>
#include <QString>
using namespace std;

class Patient : public Person
{
public:
    Patient(string name, int age, string diagnosis);

    void setDiagnosis(string diagnosis);
    string getDiagnosis();

    QString get_inf() override;

private:
    string m_diagnosis;
};

#endif // PATIENT_H
