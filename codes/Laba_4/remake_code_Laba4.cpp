#include <iostream>
using namespace std;

class Movie   // Створюю клас з назвою Movie
{
private:    // Дані, що приховані від користувача
  string name , producer, genre, country ;
  int r_year;
    // З методочики були взяті name, producer, r_year ; Решта придумані самостійно.
public:            // Дані, що доступні користувачу
  void enter_data()   // метод класу для введення даних
  {
    cout << "Movie's name: ";
    getline(cin, name);                     //Oppenheimer
    cout << "Producer (Name & Last name): ";
    getline(cin, producer);                 //Christopher Nolan
    cout << "Genre: " ;
    getline(cin, genre);                    //Comedy
    cout << "Country: ";
    getline(cin, country);                  //USA
    cout << "Release year: ";
    cin >> r_year;                          //2023
  }

  void print_data()   // метод класу для виведення даних
  {
    cout << endl << "Movie's name: " << name
         << endl << "Producer: " << producer
         << endl << "Genre: " << genre
         << endl << "Country: " << country
         << endl << "Release Year: " << r_year << endl;
  }
};

int main (void)   // Головна функція
{
  Movie feature_film;
  feature_film.enter_data();   // Викликаємо з класу Movie -- enter_data , для вводу даних

  cout << "_____Movie Info_____" ;
  feature_film.print_data();            // Виводимо результат введених даних
  return 0;
}
