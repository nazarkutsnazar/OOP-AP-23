#ifndef TEAM_H
#define TEAM_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Team {
protected:
    string name;
    int membersCount;

public:
    Team(const string& teamName = "", int count = 0);
    virtual ~Team();

    void setName(const string& teamName);
    void setMembersCount(int count);

    string getName() const { return name; }  

    virtual void OutputInfo() const;
};
#endif
