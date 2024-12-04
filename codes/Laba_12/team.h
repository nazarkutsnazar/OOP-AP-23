#ifndef TEAM_H
#define TEAM_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <algorithm>
using namespace std;

class Manager;

class Team {
protected:
    string team_name;
    int team_members;

public:
    Team() : team_name(""), team_members(0) {      
        cout << "The object was created" << endl;
    }
    
    Team(const string& name, int members);     
    
    virtual ~Team() {           
        cout << "Object was destroyed" << endl;
    }

    virtual void display() const = 0;    

    string getName() const;
    int getMembers() const;

    void setName(const string& name);
    void setMembers(int members);

    friend class Manager;           
}; 
#endif
