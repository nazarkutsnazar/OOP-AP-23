#include <iostream>
#include <cmath>  // Для використання математичних функцій
#include <iomanip>  // Для налаштування ширини виводу
using namespace std;

// Структура даних
struct Data {
    double a; // a
    double b; // b
    double h; // h

    double x1 = 0.5; // x початкове
    double x2 = 1.9; // x кінцеве

    double y; // y, який ми шукаємо за формулою
};

// Функція підпрограма
double func_calculating_y(double x, double a, double b) {
    double top = 1 + pow(cos(pow(a, 2) + pow(x, 2)), 2);
    double bottom = pow(x, 3) + 3 / (sqrt(b) * x);
    return top / bottom;
}

int main() {
    // Виведення фіксованих значень для змінних
    cout << "Задані значення змінних:\n x1 = 0.5 \n x2 = 1.9 \n h = 0.2 \n a = 0.84 \n b = 0.63\n";

    Data data;

    // Введення початкових значень з клавіатури
    cout << "Введіть початкове значення x: ";
    cin >> data.x1;
    cout << "Введіть кінцеве значення x: ";
    cin >> data.x2;
    cout << "Введіть крок h: ";
    cin >> data.h;
    cout << "Введіть значення a: ";
    cin >> data.a;
    cout << "Введіть значення b: ";
    cin >> data.b;

    // Виведення заголовку таблиці
    cout << setw(10) << "x" << setw(20) << "y" << endl;
    cout << "------------------------------------" << endl;

    // Цикл для табуляції функції
    for (double x = data.x1; x <= data.x2; x += data.h) {
        double y = func_calculating_y(x, data.a, data.b);  // Виклик функції для обчислення y
        cout << setw(10) << x << setw(20) << y << endl;
    }

    return 0;
} //Кінець програми
