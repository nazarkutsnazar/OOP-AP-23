#include "movie.h"
#include <iostream>
using namespace std;

int main() {
    Movie myMovies;

    cout << "Add first movie:" << endl;
    myMovies.addMovie();

    cout << "Add second movie:" << endl;
    myMovies.addMovie();

    myMovies.Movie_Shablon_1();

    cout << endl;
    myMovies.OutputMovies();

    return 0;
}
