#include "OnlineLearningPlatform.h"
#include "course.h"

int main()
{
    string name;
    int count_students = 0;
    OnlineLearningPlatform<Course> platform;

    platform.addCourse(Course("Python in thirty days", "Guido", 100));
    platform.addCourse(Course("NG_2025", "Roman Tkachuk", 200));
    platform.addCourse(Course("Course in MySQL", "Luda", 50));
    platform.addCourse(Course("Soft Skills", "Oleksandr", 100));

    platform.showallcourse();

    cout << "Course search on count students" << endl;
    cin >> count_students;
    auto found = platform.findByCountStudents(count_students);
    for (const auto& course : found) {
        cout << " Found: " << course << endl;
    }

    cout << "\nEnter name course of remove: ";
    cin.ignore();
    getline(cin, name);
    platform.removeByName(name);

    cout << "Updated list: " << endl;
    platform.showallcourse();

    return 0;
}
