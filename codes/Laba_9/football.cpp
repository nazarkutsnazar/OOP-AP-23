#include "team.h"
#include "football.h"
#include <iostream>
using namespace std;

Football::Football(const string& name, int members, int goals)
    : Team (name, members), scored_goals (goals) {}

Football::~Football() {}

void Football::setGoals(int goals) {
    if (goals >= 0) {
        scored_goals = goals;
    } else {
        cerr << "Error: Goals cannot be negative!" << endl;
    }
}

int Football::getGoals() const {
    return scored_goals;
}

void Football::display() const {
    cout << "Football Team: " << team_name << endl <<
    "Members: " << team_members << endl << 
    "Goals Scored: " << scored_goals << endl;
}