#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include <iostream>
using namespace std;

class Employee
{
private:
    string name = nullptr;
    int age = 0;
    double salary = 0;

public:
    Employee();

    Employee(string name, int age, double salary);

    ~Employee();

    Employee operator+(Employee& other);
    bool operator==(Employee& other);
    bool operator!=(Employee& other);

    friend ostream& operator<<(ostream& os, Employee& emp);
};

#endif // EMPLOYEE_H
