#include "basketball.h"
#include <iostream>
using namespace std;

Basketball::Basketball(const string& teamName, int count, int points)
    : Team(teamName, count), pointsScored(points) {}

void Basketball::setPointsScored(int points) {
    if (points >= 0) {
        pointsScored = points;
    } else {
        cerr << "Invalid points count." << endl;
    }
}

void Basketball::OutputInfo() const {
    Team::OutputInfo();
    cout << "Points Scored: " << pointsScored << endl;
}
