#include "team.h"
#include "basketball.h"
#include <iostream>
using namespace std;

Basketball::Basketball(const string& name, int members, int points)
    : Team (name, members), scored_points (points) {}

Basketball::~Basketball() {}

void Basketball::setPoints(int points) {
    if (points >= 0) {
        scored_points = points;
    } else {
        cerr << "Error: Points cannot be negative!" << endl;
    }
}

int Basketball::getPoints() const {
    return scored_points;
}

void Basketball::display() const {
    cout << "Basketball Team: " << team_name << endl << 
    "Members: " << team_members << endl <<
    "Points Scored: " << scored_points << endl;
}