#include "employee.h"
#include <cmath>

Employee::Employee() : name("Невідомо"), age(0), salary(0.0)
{

}

Employee::Employee(string name, int age, double salary)
    : name(name), age(age), salary(salary)
{

}

Employee::~Employee()
{

}

Employee Employee::operator+(Employee& other) {
    string newName = this->name + " " + other.name;

    int newAge = static_cast<int>(round((this->age + other.age) / 2.0));

    double newSalary = this->salary + other.salary;

    return Employee(newName, newAge, newSalary);
}

bool Employee::operator==(Employee& other) {
    return (this->name == other.name) &&
           (this->age == other.age) &&
           (this->salary == other.salary);
}

bool Employee::operator!=(Employee& other) {
    return (this->name != other.name) ||
           (this->age != other.age) ||
           (this->salary != other.salary);
}

ostream& operator<<(ostream& os, Employee& emp) {
    os << "Ім'я: " << emp.name << ", Вік: " << emp.age << ", ЗП: " << emp.salary;
    return os;
}

