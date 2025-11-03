#include "patient.h"
#include <stdexcept>

Patient::Patient(string name, int age, string diagnosis) : Person(name, age)
{
    setAge(age);
    setDiagnosis(diagnosis);
}

void Patient::setDiagnosis(string diagnosis) {
    if (diagnosis.empty()) throw invalid_argument("diagnosis not empty!");
        m_diagnosis = diagnosis;
}

string Patient::getDiagnosis() {
    return m_diagnosis;
}

QString Patient::get_inf() {
    return QString("Patient: %1\nAge: %2\nDiagnosis: %3\n")
        .arg(QString::fromStdString(m_name))
        .arg(m_age)
        .arg(QString::fromStdString(m_diagnosis));
}
