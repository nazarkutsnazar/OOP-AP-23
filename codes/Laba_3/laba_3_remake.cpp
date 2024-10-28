#include <iostream>
#include <cmath>     // Для використання математичних функцій
#include <iomanip>   // Для налаштування ширини виводу
#include <vector>    // Для зберігання значень y > 1
using namespace std;

struct Data {
    double x1 = 0.5; // x початкове
    double x2 = 1.9; // x кінцеве
    double h = 0.2; // h
    double a = 0.84; // a
    double b = 0.63; // b
    double x;       // x
    double y;       // y, який ми шукаємо за формулою
};

// Функція для обчислення y
double calculating_y(double x, double a, double b) {
    double top = 1 + pow(cos(pow(a, 2) + pow(x, 2)), 2);  // Чисельник 1 + (cos(a^2 + x^2))^2
    double bottom = pow(x, 3) + pow(b * x, 1.0 / 3.0);     // Знаменник x^3 + (b * x)^(1/3)
    return top / bottom;
}

// Функція для обчислення середнього геометричного
double calculate_geometric_mean(const vector<double>& values) {
    if (values.empty()) return 0.0;
    double product = 1.0;
    for (double value : values) {
        product *= value;
    }
    return pow(product, 1.0 / values.size());
}

int main() {
    Data data;
    vector<double> y_values; // Вектор для зберігання значень y > 1

    cout << "Po4atkove (x1), Kinceve (x2), h, a, b" << endl;
    cout << "x1 = " << data.x1 << endl;
    cout << "x2 = " << data.x2 << endl;
    cout << "h = " << data.h << endl;
    cout << "a = " << data.a << endl;
    cout << "b = " << data.b << endl;

    // Виведення заголовку таблиці
    cout << setw(10) << "x" << setw(20) << "y" << endl;
    cout << "------------------------------------" << endl;
    // Цикл для табуляції функції
    for (double x = data.x1; x <= data.x2; x += data.h) {
        double y = calculating_y(x, data.a, data.b);  // Виклик функції для обчислення y
        cout << setw(10) << x << setw(20) << y << endl;

        // Збереження y > 1 для обчислення середнього геометричного
        if (y > 1) {
            y_values.push_back(y);
        }
    }
    // Обчислення середнього геометричного для всіх y > 1
    double geometric_mean = calculate_geometric_mean(y_values);
    if (geometric_mean > 0) {
        cout << "Average geometric of all y > 1: " << geometric_mean << endl;
    } else {
        cout << "There is no variables which y > 1" << endl;
    }

    return 0;
}
