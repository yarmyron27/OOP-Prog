#ifndef DOCTOR_H
#define DOCTOR_H
#include "medicalpersonnel.h"
using namespace std;

class Doctor : public MedicalPersonnel
{
public:
    Doctor(string name, int age, int expiriance, int operations);

    void setExpiriance(int expiriance);
    void setOperations(int operations);

    QString get_inf() override;

private:
    int m_expiriance;
    int m_successfulOperations;
};

#endif // DOCTOR_H
