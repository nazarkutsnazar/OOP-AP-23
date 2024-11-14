#ifndef MOVIE_H
#define MOVIE_H

#include <vector>
#include <string>
using namespace std;

struct Movie_Data {
    string title;
    string producer;
    int year;
    string genre;
};

class Movie {
private:
    vector<Movie_Data> movies;                      // Вектор для збереження фільмів

public:
    Movie();                                        // Конструктор
    ~Movie();                                       // Деструктор

    void setTitle(string& title);                   // Встановлення заголовку
    void setGenre(string& genre);                   // Встановлення жанру
    void setYear(int& year);                        // Встановлення року
    void setProducer(string& producer);             // Встановлення продюсера

    void addMovie(const Movie_Data& movie);          // Додавання фільму
    void insertMovie(size_t index, const Movie_Data& movie); // Вставка фільму
    void removeMovie(size_t index);                  // Видалення фільму
    void swapMovie(size_t index1, size_t index2);    // Заміна місцями
    void clearMovie();                               // Очищення списку

    void outputMovies() const;                       // Вивід фільмів

    bool validYear(int year) const;                  // Перевірка року
    bool validTitle(const string& title) const;      // Перевірка назви
};

#endif
