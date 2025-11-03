#include <iostream>
#include "employee.h"
#include <locale>
using namespace std;

int main()
{
    setlocale(LC_ALL, ".UTF-8");

    cout << "--- Створення працівників ---" << endl;

    Employee emp1("Дмитро", 30, 1500.50);
    Employee emp2("Марина", 25, 1800.75);
    Employee emp3("Павло", 30, 1500.50);

    cout << "Працівник 1: " << emp1 << endl;
    cout << "Працівник 2: " << emp2 << endl;
    cout << "Працівник 3: " << emp3 << endl;
    cout << "--------------------------------\n" << endl;

    cout << "--- Тест оператора + (Об'єднання) ---" << endl;
    Employee combinedEmp = emp1 + emp2;
    cout << "Результат (emp1 + emp2): " << combinedEmp << endl;
    cout << "--------------------------------\n" << endl;

    cout << "--- Тест оператора == (Рівність) ---" << endl;
    cout << boolalpha;
    cout << "emp1 == emp2 (очікуємо false): " << (emp1 == emp2) << endl;
    cout << "emp1 == emp3 (очікуємо true):  " << (emp1 == emp3) << endl;
    cout << "--------------------------------\n" << endl;

    cout << "--- Тест оператора != (Нерівність) ---" << endl;
    cout << "emp1 != emp2 (очікуємо true):  " << (emp1 != emp2) << endl;
    cout << "emp1 != emp3 (очікуємо false): " << (emp1 != emp3) << endl;
    cout << "--------------------------------\n" << endl;

    return 0;
}
