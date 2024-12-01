#ifndef MANAGER_H
#define MANAGER_H

#include "team.h"
#include "football.h"
#include "basketball.h"
#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
using namespace std;

class Manager {
private:
    vector <shared_ptr<Team>> teams;                        //Saving teams

public:
    void addTeam(shared_ptr<Team> team) {                   //Add a team          
        teams.push_back(team);
        cout << "Team added successfully." << endl;
    }

    void displayTeams() const {                             //Output teams
        if (teams.empty()) {
            cout << "No teams available." << endl;
        } else {
            cout << "Teams list:" << endl;
            for (const auto& team : teams) {
                team->display();
                cout << "----------------------" << endl;
            }
        }
    }
    void removeTeam(const string& name) {                   //Remove team
        auto it = remove_if(teams.begin(), teams.end(),
                            [&name](const shared_ptr<Team>& team) {
                                return team->getName() == name;
                            });

        if (it != teams.end()) {
            teams.erase(it, teams.end());
            cout << "Team removed successfully." << endl;
        } else {
            cout << "Team with name '" << name << "' not found." << endl;
        }
    }
};
#endif