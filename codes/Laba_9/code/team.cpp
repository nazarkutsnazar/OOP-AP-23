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
    if (members >= 0) {
        team_members = members;
    } else {
        cerr << "Error: Number of members cannot be negative!" << endl;
    }
}

string Team::getName() const {
    return team_name;
}

int Team::getMembers() const {
    return team_members;
}