#include "team.h"
#include "basketball.h"
#include <iostream>
using namespace std;

Basketball::Basketball(const string& name, int members, int points)
    : Team (name, members), scored_points (points) {}

Basketball::~Basketball() {}

void Basketball::setPoints(int points) {
    if (points < 0) {
        throw invalid_argument("Points cannot be negative!");
    }
    scored_points = points;
}


int Basketball::getPoints() const {
    return scored_points;
}

void Basketball::display() const {
    cout << "Basketball Team: " << team_name << endl << 
    "Members: " << team_members << endl <<
    "Points Scored: " << scored_points << endl;
}