#include "team.h"
#include "football.h"
#include <iostream>
using namespace std;

Football::Football(const string& name, int members, int goals)
    : Team(name, 0), scored_goals(0) { 
    setMembers(members);  
    setGoals(goals);    
}


Football::~Football() {}

void Football::setGoals(int goals) {
    if (goals < 0) {
        throw invalid_argument("Goals cannot be negative!");
    }
    scored_goals = goals;
}


int Football::getGoals() const {
    return scored_goals;
}

void Football::display() const {
    cout << "Football Team: " << team_name << endl <<
    "Members: " << team_members << endl << 
    "Goals Scored: " << scored_goals << endl;
}