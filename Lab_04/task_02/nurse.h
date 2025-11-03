#ifndef NURSE_H
#define NURSE_H
#include "medicalpersonnel.h"
using namespace std;

class Nurse : public MedicalPersonnel
{
public:
    Nurse(string name, int age, string qualification, int procedures);

    void setQualification(string qualification);
    void setProcedures(int procedures);

    QString get_inf() override;

private:
    string m_qualification;
    int m_procedures;
};

#endif // NURSE_H
