#include <iostream>
#include <vector>
#include <cctype>
#include <limits>
using namespace std;

class Movie {
private:
    string title;
    string producer;
    string genre;
    int r_year;
public:
    Movie() {
        cout << "Object was created." << endl;
    }
    ~Movie() {
        cout << "Object was destroyed." << endl;
    }
    Movie(string t, string p, string g, int y) {
        title = t;
        producer = p;
        genre = g;
        r_year = y;
    }

    void setYear() {
        int YY;
        while (true) {
            cout << "Enter year: ";
            cin >> YY;

            if (cin.fail() || YY > 2024 || YY < 1900) {
                cout << "Error! Year must be between 1900 and 2024." 
                << endl << "And you must enter only numbers!!" << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            } else {
                r_year = YY;
                break;
            }
        }
    }

    void setProducer() {
        string PP;
        while (true) {
            cout << "Enter producer: ";
            cin >> ws; // Пропуск пробілів
            getline(cin, PP);

            bool valid = !PP.empty() && PP.size() <= 18; 
            for (char c : PP) {
                if (!isalpha(c) && c != ' ') {
                    valid = false;
                    break;
                }
            }

            if (!valid) {
                cout << "Error! Producer's name should be alphabetic and up to 18 characters." << endl;
            } else {
                producer = PP;
                break;
            }
        }
    }

    void setTitle() {
        while (true) {
            cout << "Enter title: ";
            cin >> ws; // для пропуску пробілів
            getline(cin, title);
            if (title.empty()) {
                cout << "Error! Title cannot be empty." << endl;
            } else {
                break; // Вихід з циклу, якщо введено заголовок
            }
        }
    }

    void setGenre() {
        while (true) {
            cout << "Enter genre: ";
            cin >> ws;
            getline(cin, genre);
            if (genre.empty()) {
                cout << "Error! Genre cannot be empty." << endl;
            } else {
                break; // Вихід з циклу, якщо введено жанр
            }
        }
    }

    int getYear() const { return r_year; }
    string getGenre() const { return genre; }

    void Output_data() const {
        cout << "Title: " << title << endl
         << "Producer: " << producer << endl
         << "Genre: " << genre << endl
         << "Year: " << r_year << endl; 
    }
};

// Функція для фільтрації фільмів за жанром
void Filter_Genre(const vector<Movie>& movies, const string& genre) {
    cout << endl << "Movies with genre " << genre << ":" << endl;
    for (const auto& movie : movies) {
        if (movie.getGenre() == genre) {
            movie.Output_data();
            cout << endl;
        }
    }
}

int main(void) {
    vector<Movie> movieCollection;

    Movie Object1;

    Object1.setYear();  
    Object1.setProducer();  
    Object1.setTitle(); // Виклик setTitle
    Object1.setGenre(); // Виклик setGenre

    movieCollection.push_back(Object1);

    string filterGenre;
    cout << "Enter category of genre to filter movies: ";
    cin >> ws;
    getline(cin, filterGenre);
    Filter_Genre(movieCollection, filterGenre);

    return 0;
}
