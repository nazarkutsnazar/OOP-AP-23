#include "movie.h"
#include <iostream>
#include <limits>
using namespace std;

int main() {
    Movie movieLibrary;
    int choice;

    while (true) {
        cout << endl << "Menu:" << endl;
        cout << "[1] - Add Movie" << endl;
        cout << "[2] - Insert Movie" << endl;
        cout << "[3] - Remove Movie" << endl;
        cout << "[4] - Swap Movies" << endl;
        cout << "[5] - Clear Movie List" << endl;
        cout << "[6] - Output Movies" << endl;
        cout << "[7] - Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');  //очищення буферу

        if (choice == 1) {
            Movie_Data newMovie;
            movieLibrary.setTitle(newMovie.title);
            movieLibrary.setGenre(newMovie.genre);
            movieLibrary.setYear(newMovie.year);
            movieLibrary.setProducer(newMovie.producer);
            movieLibrary.addMovie(newMovie);
        
        } else if (choice == 2) {                      
            Movie_Data newMovie;
            size_t index;

            movieLibrary.setTitle(newMovie.title);
            movieLibrary.setGenre(newMovie.genre);
            movieLibrary.setYear(newMovie.year);
            movieLibrary.setProducer(newMovie.producer);

            cout << "Enter 1-based index to insert at (or " << movieLibrary.getSize() + 1 
                << " to add at the end): ";
            cin >> index;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            if (index < 1 || index > movieLibrary.getSize() + 1) {      // Перевірка правильності індексу
                cout << "Invalid index! Please enter a valid index between 1 and " 
                    << movieLibrary.getSize() + 1 << "." << endl;
            } else {
                movieLibrary.insertMovie(index - 1, newMovie);          // 0-індексація
            }

        } else if (choice == 3) {
            size_t index;
            cout << "Enter index of movie to remove: ";
            cin >> index;
            movieLibrary.removeMovie(index - 1);                // Врахування 0-індексації
        
        } else if (choice == 4) {
            size_t index1, index2;
            cout << "Enter index of first movie to swap: ";
            cin >> index1;
            cout << "Enter index of second movie to swap: ";
            cin >> index2;
            movieLibrary.swapMovie(index1 - 1, index2 - 1);
        
        } else if (choice == 5) {
            movieLibrary.clearMovie();
        
        } else if (choice == 6) {
            movieLibrary.outputMovies();
        
        } else if (choice == 7) {
            cout << "Exiting program." << endl;
            break;
        
        } else {
            cout << "Invalid choice! Please try again." << endl;
        }
    }

    return 0;
}
