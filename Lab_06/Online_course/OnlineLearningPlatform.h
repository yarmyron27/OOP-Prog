#ifndef ONLINELEARNINGPLATFORM_H
#define ONLINELEARNINGPLATFORM_H

#include <iostream>
#include <string>
#include <QList>
using namespace std;

template <typename type>
class OnlineLearningPlatform {

    QList<type> allcourse;

public:
    OnlineLearningPlatform() = default;

    OnlineLearningPlatform(const initializer_list<type>& list) {
        for (const auto& course : list) allcourse.append(course);
    }

    void addCourse(const type& course) { allcourse.append(course); }

    void removeByName(const string& name) {
        for (int index = 0; index < allcourse.size(); index++)
            if (allcourse[index].getName() == name) {
                allcourse.removeAt(index);
                return;
            }
        cout << "Course not found" << endl;
    }

    void showallcourse() const {
        if (allcourse.isEmpty()) {
            cout << "List empty" << endl;
            return;
        }
        for (const auto& course : allcourse)
            cout << "*" << course << endl;

    }

    QList<type> findByCountStudents(unsigned short students) const {
        QList<type> foundList;

        for (const auto& course : allcourse)
            if (course.getCount_stud() == students)
                foundList.append(course);
        return foundList;
    }
};

#endif // ONLINELEARNINGPLATFORM_H
