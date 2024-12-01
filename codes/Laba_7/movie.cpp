#include "movie.h"
#include <iostream>
#include <cctype>
#include <limits>
using namespace std;

Movie::Movie() {}                                          //Конструктор
Movie::~Movie() {}                                         //Деструктор

void Movie::setTitle(string& title) {                      //Метод встановлення назви
    while (true) {
        cout << "Enter title: ";
        cin >> ws;                                         // для пропуску пробілів
        getline(cin, title);
        if (title.empty()) {
            cout << "Error! Title cannot be empty." << endl;
        } else {
            break;
        }
    }
}

void Movie::setGenre(string& genre) {                       //Метод встановлення жанру
    while (true) {
        cout << "Enter genre: ";
        cin >> ws;
        getline(cin, genre);

        if (genre.empty() || genre.size() < 2) {
            cout << "Error! Genre must have at least 2 ";
            cout << "characters and cannot be empty." << endl;
        } else {
            break;
        }
    }
}

void Movie::setYear(int& year) {                            //Метод встановлення року
    while (true) {
        cout << "Enter year: ";
        cin >> year;

        if (cin.fail() || year > 2024 || year < 1888) { 
            cout << "Error! Year must be between 1888 and 2024."
                 << endl << "Please enter a valid number!" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            break;
        }
    }
}

void Movie::setProducer(string& producer) {                 //Метод встановлення продюсера
    while (true) {
        cout << "Enter producer: ";
        cin >> ws;                                          // Пропуск пробілів
        getline(cin, producer);

        if (producer.empty() || producer.size() > 18) {
            cout << "Error! Producer's name must be up ";
            cout << "to 18 characters and not empty." << endl;
            continue;
        }

        bool valid = true;
        for (char c : producer) {
            if (!isalnum(c) && c != ' ' && c != '-' && c != '.') {
                valid = false;
                break;
            }
        }

        if (!valid) {
            cout << "Error! Producer's name contains invalid characters." << endl;
        } else {
            break;
        }
    }
}
/*
void Movie::insertMovie(size_t index, const Movie_Data& movie) {
    if (index >= movies.size()) {
        movies.push_back(movie);                            // Додає в кінці
    } else {
        movies.insert(movies.begin() + index, movie);       // Вставляє на вказану позицію
    }
    cout << "Movie inserted successfully!" << endl;
}
*/
void Movie::swapMovie(size_t index1, size_t index2) {       //Обмін 
    if (index1 < movies.size() && index2 < movies.size()) {
        swap(movies[index1], movies[index2]); 
        cout << "Movies swapped successfully!" << endl;
    } else {
        cout << "Error! One or both indices are invalid." << endl;
    }
}

void Movie::insertMovie(size_t index, const Movie_Data& movie) {
    if (index >= movies.size()) {
        movies.push_back(movie); // Додає в кінець
        cout << "Index out of range! Movie added to the end of the list." << endl;
    } else {
        movies.insert(movies.begin() + index, movie); // Вставляє у вказану позицію
        cout << "Movie inserted successfully at position " << index + 1 << "." << endl;
    }
}

void Movie::clearMovie() {                                  //Очищення списку фільмів
    movies.clear();
    cout << "Movie list cleared!" << endl;
}

bool Movie::validYear(int year) const {                     //Перевірка року
    return year >= 1888 && year <= 2024;
}

bool Movie::validTitle(const string& title) const {         //Перевірка назви
    return !title.empty();
}

void Movie::addMovie(const Movie_Data& movie) {             //+1 фільм
    movies.push_back(movie);
    cout << "Movie added successfully!" << endl;
}

void Movie::removeMovie(size_t index) {                     // Видалення фільму
    if (index < movies.size()) {
        movies.erase(movies.begin() + index);
        cout << "Movie removed successfully!" << endl;
    } else {
        cout << "Invalid index!" << endl;
    }
}

void Movie::outputMovies() const {                          // Виведення фільмів
    if (movies.empty()) {
        cout << "No movies in the library." << endl;
    } else {
        cout << "Movie List:" << endl;
        for (size_t i = 0; i < movies.size(); ++i) {
            const auto& movie = movies[i];
            cout << "[" << i + 1 << "] Title: " << movie.title << endl;
            cout << "    Genre: " << movie.genre << endl;
            cout << "    Year: " << movie.year << endl;
            cout << "    Producer: " << movie.producer << endl;
            cout << "-----------------------------" << endl;
        }
    }
}

size_t Movie::getSize() const {
    return movies.size();
}
