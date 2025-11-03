#include "person.h"
#include <stdexcept>

Person::Person(string name, int age) {
    setName(name);
}

void Person::setName(string name) {
    if (name.empty()) throw invalid_argument("Name personal not empty!");
        m_name = name;
}

void Person::setAge(int age) {
    if (age < 0 || age > 110) throw invalid_argument("age must be between 0 and 110");
    m_age = age;
}

string Person::getName() {
    return m_name;
}

int Person::getAge() {
    return m_age;
}
