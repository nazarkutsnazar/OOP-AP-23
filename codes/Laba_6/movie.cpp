#include "movie.h"
#include <iostream>
#include <cctype>
#include <limits>
using namespace std;

Movie::Movie() : currentSize(0) {} // Ініціалізація currentSize

Movie::~Movie() {}

void Movie::addMovie(const string& title, const string& producer, int year, const string& genre) {
    if (currentSize >= SIZE) { //3
        cout << "Array is filled. Cannot add more movies." << endl;
        return;
    }

    string t = title, p = producer, g = genre;
    int y = year;

    if (title.empty() && producer.empty() && genre.empty() && year == 0) {
        setTitle(t);
        setProducer(p);
        setYear(y);
        setGenre(g);
    }

    movies[currentSize++] = {t, p, y, g};
}

void Movie::Movie_Shablon_1(const string& title, const string& producer, int year, const string& genre) {
    if (currentSize >= SIZE) {
        cout << "Array is filled. Cannot add more movies." << endl;
        return;
    }
    movies[currentSize++] = {title, producer, year, genre};
}

void Movie::OutputMovies() const {
    if (currentSize == 0) {
        cout << "No movies to display." << endl;
        return;
    }

    cout << "List of Movies:" << endl;
    for (size_t i = 0; i < currentSize; ++i) {
        cout << "Title: " << movies[i].title
             << ", Producer: " << movies[i].producer
             << ", Year: " << movies[i].year
             << ", Genre: " << movies[i].genre << endl;
    }
}

void Movie::setTitle(string& title) {
    while (true) {
        cout << "Enter title: ";
        cin >> ws; // для пропуску пробілів
        getline(cin, title);
        if (title.empty()) {
            cout << "Error! Title cannot be empty." << endl;
        } else {
            break;
        }
    }
}

void Movie::setGenre(string& genre) {
    while (true) {
        cout << "Enter genre: ";
        cin >> ws;
        getline(cin, genre);

        if (genre.empty() || genre.size() < 2) {
            cout << "Error! Genre must have at least 2 characters and cannot be empty." << endl;
        } else {
            break;
        }
    }
}

void Movie::setYear(int& year) {
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

void Movie::setProducer(string& producer) {
    while (true) {
        cout << "Enter producer: ";
        cin >> ws; // Пропуск пробілів
        getline(cin, producer);

        if (producer.empty() || producer.size() > 18) {
            cout << "Error! Producer's name must be up to 18 characters and not empty." << endl;
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
