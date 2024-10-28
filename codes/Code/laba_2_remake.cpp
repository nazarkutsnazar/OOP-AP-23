#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

struct Data {
    int a, b;
    double x, y;
};
int check_condition(double x) { // Функція для перевірки умов і визначення математичної функції
    if (x <= 3) {
        return 1;
    } else if (3 < x && x <= 5) {
        return 2;
    } else if (x > 5) {
        return 3;
    } else {
        return -1; // Невизначений прапорець для помилки
    }
}
double calculate_1st(double a, double x) {  // ПЕРША функція (умова x <= 3)
    double numerator = pow(x, 2) + fabs(a);
    double denominator = 1 + pow(x, 4);

    if (numerator / denominator <= 0) { // Перевірка на додатність
        cout << "Error: Log() argument is not positive." << endl;
        return -1; // Повертаємо значення, що вказує на помилку
    }

    return pow(log(numerator / denominator), 2);
}
double calculate_2nd(double b, double x) {  // ДРУГА функція (умова 3 < x <= 5)
    return pow(b, 3) + pow(cos(x), 2);
}
double calculate_3rd(double a, double b, double x) {  // ТРЕТЯ функція (умова x > 5)
    return cbrt(fabs(a * b) * x);
}

int main() {
    Data data;
    // Ввід
    cout << "Enter parameter a: ";
    cin >> data.a;
    cout << "Enter parameter b: ";
    cin >> data.b;
    cout << "Enter variable x: ";
    cin >> data.x;

    // Перевірка умови на основі "x"
    int flag = check_condition(data.x);

    switch (flag) {   // Switch-case для обчислення результату
        case 1:
            data.y = calculate_1st(data.a, data.x);
            if (data.y == -1) return 1; // Перевірка на помилку в першій функції
            break;
        case 2:
            data.y = calculate_2nd(data.b, data.x);
            break;
        case 3:
            data.y = calculate_3rd(data.a, data.b, data.x);
            break;
        default:
            cout << "Error: Invalid condition!" << endl;
            return 1;
    }
    // Виведення вхідних даних
    cout << endl << "Input values: a = " << data.a
    << ", b = " << data.b
    << ", x = " << data.x << endl;

    cout << "Result (y): " << data.y << endl;
    return 0;
}
