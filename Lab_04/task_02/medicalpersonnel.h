#ifndef MEDICALPERSONNEL_H
#define MEDICALPERSONNEL_H
#include "person.h"
#include <string>
#include <QString>
using namespace std;

class MedicalPersonnel : public Person
{
public:
    MedicalPersonnel(string name, string specialization, int age);

    virtual QString get_inf() = 0;
    void setAge(int age) override;

protected:
    string m_specialization;
};

#endif // MEDICALPERSONNEL_H
