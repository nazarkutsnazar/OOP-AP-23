#include <iostream>
#include <cmath>  // Для використання математичних функцій
#include <iomanip>  // Для налаштування ширини виводу
using namespace std;

struct Data { // Структура даних

    double x1 = 0.5; // x початкове
    double x2 = 1.9; // x кінцеве
    double h = 0.2; // h
    double a = 0.84; // a
    double b = 0.63; // b
    double x ; // x
    double y; // y, який ми шукаємо за формулою
};

// Функція підпрограма
double func_calculating_y(double x, double a, double b) {
    double top = 1 + pow(cos(x), 2)*(pow(a, 2) + pow(x, 2));
    double bottom = pow(x, 3) + pow(b*x, 1.0/3.0);
    return top / bottom;
}

int main() {
    Data data;
    cout << "Виведення x початкове (х1) , кінцеве (х2), h , a , b" << endl;
    cout << "x1 =   " << data.x1 << endl;
    cout << "x2 =   " << data.x2 << endl;
    cout << "h =  " << data.h << endl;
    cout << "a =  " << data.a << endl;
    cout << "b =  " << data.b << endl;
    //Кінець виведення перелічених вище аргументів

    // Виведення заголовку таблиці
    cout << setw(10) << "x" << setw(20) << "y" << endl;
    cout << "------------------------------------" << endl;

    double product_of_y = 1; // Змінна для добутку всіх y > 1
    int count_y = 0;  // Лічильник кількості значень y > 1

    // Цикл для табуляції функції
    for (double x = data.x1; x <= data.x2; x += data.h) {
        double y = func_calculating_y(x, data.a, data.b);  // Виклик функції для обчислення y
        cout << setw(10) << x << setw(20) << y << endl;

        if (y > 1) {
            product_of_y *= y;  // Множимо на значення y, яке більше за 1
            count_y++;  // Збільшуємо лічильник
        }
    }
    return 0;
} // Кінець програми
