#ifndef FOOTBALL_H
#define FOOTBALL_H

#include "team.h"
#include <iostream>
#include <string>

class Manager;

class Football : public Team {
protected:
    int scored_goals;

public:
    Football() : Team("Shahtar", 19), scored_goals(0) {}    

    Football(const string& name, int members, int goals);    
    
    ~Football(); 

    void display() const override;

    int getGoals() const;

    void setGoals(int goals);

    friend class Manager;
};
#endif