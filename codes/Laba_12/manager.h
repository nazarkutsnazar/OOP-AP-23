#ifndef MANAGER_H
#define MANAGER_H

#include "team.h"
#include "football.h"
#include "basketball.h"
#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <fstream>  
#include <sstream>  

using namespace std;

class Manager {
private:
    vector <shared_ptr<Team>> teams; 

public:
    void addTeam(shared_ptr<Team> team) {         
        teams.push_back(team);
        cout << "Team added successfully." << endl;
    }

    void displayTeams() const { 
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

    void removeTeam(const string& name) { 
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

    void saveTeams(const string& filename) const {
        ofstream outFile(filename); 
        if (!outFile) {
            cerr << "Error: Cannot open file for saving!" << endl;
            return;
        }

        for (const auto& team : teams) {
            outFile << team->getName() << "|" 
                    << team->getMembers() << "|";

            if (dynamic_pointer_cast<Football>(team)) {
                outFile << "Football|"
                        << dynamic_pointer_cast<Football>(team)->getGoals() << endl;
            } else if (dynamic_pointer_cast<Basketball>(team)) {
                outFile << "Basketball|"
                        << dynamic_pointer_cast<Basketball>(team)->getPoints() << endl;
            }
        }

        outFile.close();  
        cout << "Teams saved successfully to " << filename << "!" << endl;
    }

    void loadTeams(const string& filename) {
        ifstream inFile(filename);  
        if (!inFile) {
            cerr << "Error: Cannot open file for loading!" << endl;
            return;
        }

        teams.clear();  
        string line;
        while (getline(inFile, line)) {
            stringstream ss(line);  
            string name, type;
            int members, value;

            getline(ss, name, '|'); 
            ss >> members;
            ss.ignore(1, '|'); 
            getline(ss, type, '|');  
            ss >> value;

            if (type == "Football") {
                teams.push_back(make_shared<Football>(name, members, value));
            } else if (type == "Basketball") {
                teams.push_back(make_shared<Basketball>(name, members, value));
            }
        }

        inFile.close(); 
        cout << "Teams loaded successfully from " << filename << "!" << endl;
    }
};
#endif
