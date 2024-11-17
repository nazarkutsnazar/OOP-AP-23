#include "football.h"
#include <iostream>
using namespace std;

Football::Football(const string& teamName, int count, int goals)
    : Team(teamName, count), goalsScored(goals) {}

void Football::setGoalsScored(int goals) {
    if (goals >= 0) {
        goalsScored = goals;
    } else {
        cerr << "Invalid goals count" << endl;
    }
}

void Football::OutputInfo() const {
    Team::OutputInfo();
    cout << "Goals scored: " << goalsScored << endl;
}
