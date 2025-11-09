#ifndef COURSE_H
#define COURSE_H

#include <iostream>
using namespace std;

class Course
{
public:
    Course(const string&, const string&, unsigned short);

    string getName() const;
    string getLecturer() const;
    unsigned short getCount_stud() const;

    friend ostream& operator<<(ostream& os, const Course& course);

private:
    string name;
    string lecturer;
    unsigned short students;
};

#endif // COURSE_H
