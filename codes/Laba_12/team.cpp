#include "team.h"
#include <iostream>
using namespace std;

Team::Team(const string& name, int members) : team_name(name), team_members(members) {}

void Team::setName(const string& name) {
    if (!name.empty()) {
        team_name = name;
    } else {
        cerr << "Error: Name cannot be empty!" << endl;
    }
}

void Team::setMembers(int members) {
    if (members <= 0) {
        throw invalid_argument("Number of members cannot be negative or zero!");
    } else if (members > 45) {
        throw out_of_range("Number of members exceeds the maximum limit of 45!");
    }
    team_members = members;
}



string Team::getName() const {
    return team_name;
}

int Team::getMembers() const {
    return team_members;
}
