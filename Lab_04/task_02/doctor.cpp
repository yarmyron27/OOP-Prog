#include "doctor.h"

Doctor::Doctor(string name, int age, int expiriance, int operations)
    : MedicalPersonnel(name, "Doctor", age)
{
    setExpiriance(expiriance);
    setOperations(operations);
}

void Doctor::setExpiriance(int expiriance) {
    if (expiriance < 2) throw invalid_argument("Expiriance not smoll 2 year");
    m_expiriance = expiriance;
}

void Doctor::setOperations(int operations) {
    if (operations < 5) throw invalid_argument("Expiriance not smoll 5 successful operations");
    m_successfulOperations = operations;
}

QString Doctor::get_inf() {
    return QString ("Specialist: %1\nName: %2\nAge: %3\nExpiriance: %4 years\nSuccessful Operations: %5")
        .arg(QString::fromStdString(m_specialization))
        .arg(QString::fromStdString(m_name))
        .arg(m_age)
        .arg(m_expiriance)
        .arg(m_successfulOperations);
}
