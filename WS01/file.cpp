#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "file.h"
#include "movie.h"
#include "utils.h"
using namespace std;

namespace seneca {
    int main() {
        bool done = false;
        char genre[128];
        loadMovies();
        cout << "Welcome to 50 top movies of all times \"genre\" search." << endl << endl;
        while (!done) {
            cout << "Enter the movie genre to start the search: ";
            cin >> genre;
            flushkeys();
            displayMoviesWithGenre(genre);
            cout << "Do another search? (Y)es: ";
            done = !yes();
            cout << endl;
        }
        cout << "Goodbye!" << endl;
        return 0;
    }
}