#include "nurse.h"
#include <stdexcept>
using namespace std;

Nurse::Nurse(string name, int age, string qualification, int procedures)
    :MedicalPersonnel(name, "Nurse", age)
{
    setQualification(qualification);
    setProcedures(procedures);
}

void Nurse::setQualification(string qualification) {
    if (qualification.empty()) throw invalid_argument("qualification is not empty!");
    m_qualification = qualification;
}

void Nurse::setProcedures(int procedures) {
    if (procedures < 0) throw invalid_argument("procedures is not 0!");
    m_procedures = procedures;
}

QString Nurse::get_inf() {
    return QString("Specialist: %1\nName: %2\nAge: %3\nQualification: %4 years\nSuccessful procedur: %5")
        .arg(QString::fromStdString(m_specialization))
        .arg(QString::fromStdString(m_name))
        .arg(m_age)
        .arg(QString::fromStdString(m_qualification))
        .arg(m_procedures);
}
