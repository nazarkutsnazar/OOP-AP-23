#ifndef MOVIE_H
#define MOVIE_H

#include <array>
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
    static const size_t SIZE = 3; // розмір масиву
    array<Movie_Data, SIZE> movies;
    size_t currentSize; // кількість введених елементів

public:
    Movie(); // Конструктор
    ~Movie(); // Деструктор
    
    void addMovie(const string& title = "", const string& producer = "",
     int year = 0, const string& genre = "");
    
    void Movie_Shablon_1(const string& title = "Requiem for a dream",
     const string& producer = "Darren Aronofsky",
      int year = 2000, const string& genre = "Drama");
    
    void OutputMovies() const;
    void setTitle(string& title);
    void setGenre(string& genre);
    void setYear(int& year);
    void setProducer(string& producer);
};

#endif
