#include "course.h"

Course::Course(const string& name, const string& lecturer, unsigned short students)
    : name(name), lecturer(lecturer), students(students)
{}

string Course::getName() const { return name; }

string Course::getLecturer() const { return lecturer; }

unsigned short Course::getCount_stud() const { return students; }

ostream& operator<<(ostream& os, const Course& course) {
    os << "Course: \"" << course.getName()
       << "\" (Lecturer: " << course.getLecturer()
       << ", Students: " << course.getCount_stud() << ")";
    return os;
}
