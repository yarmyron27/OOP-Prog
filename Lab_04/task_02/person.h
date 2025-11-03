#ifndef PERSON_H
#define PERSON_H
#include <string>
#include <QString>
using namespace std;

class Person
{
public:
    Person(string name, int age);

    virtual ~Person() {}

    void setName(string name);
    virtual void setAge(int age);

    string getName();
    int getAge();

    virtual QString get_inf() = 0;

protected:
    string m_name;
    int m_age;
};

#endif // PERSON_H
