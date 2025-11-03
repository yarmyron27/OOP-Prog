#include "medicalpersonnel.h"
using namespace std;

MedicalPersonnel::MedicalPersonnel(string name, string specialization, int age)
    : Person(name, age), m_specialization(specialization)
{
    setAge(age);
}

void MedicalPersonnel::setAge(int age) {
    if (age < 22 || age > 50) throw invalid_argument("age must be between 22 and 50");
    m_age = age;
}
