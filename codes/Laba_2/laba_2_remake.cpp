#include <iostream>
#include <cmath>
using namespace std;

struct Data {
  //Параметри
int a , b ;
  //Змінні
double x , y ;
  //Коефіцієнти
  //double log() ;
};

int check_condition(double x) {
    if (x <= 3) {
        return 1;
    }
    else if (x > 3 && x <= 5) {
        return 2;
    }
    else {
        return 3;
    }
}

// Функція першої умови    (x <= 3)
double calculate_first(double a, double x) {
  //  return (pow(log(pow(x, 2)), 2) + fabs(a)) / (1 + pow(x, 4));
    return pow(log(10), 2) * ( (pow(x , 2)+abs(a)) / (1 + pow(x, 4)) );
}

// Функція другої умови     (3 < x <= 5)
double calculate_second(double b, double x) {
    return pow(b, 3) + pow(cos(x), 2);
}

// Функція третьої умови      (x > 5)
double calculate_third(double a, double b, double x) {
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

    // Перевіряє умову основану на вхідному "x"
    int flag = check_condition(data.x);

    // Switch case щоб обчислити результат
    switch (flag) {
        case 1:
            data.y = calculate_first(data.a, data.x);
            break;
        case 2:
            data.y = calculate_second(data.b, data.x);
            break;
        case 3:
            data.y = calculate_third(data.a, data.b, data.x);
            break;
        default:
            cout << "Error: Invalid condition!" << endl;
            return 1;
    }
    // Результат
    cout << "Result (y): " << data.y << endl;
    return 0;
}
