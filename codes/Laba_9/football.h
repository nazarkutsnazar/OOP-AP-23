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
    Football() : Team("Shahtar", 19), scored_goals(0) {}    //The default constructor

    Football(const string& name, int members, int goals);   //Constructor with parameters 
    
    ~Football();                                            //Destructor 

    void display() const override;                          //Virtual method

    int getGoals() const;

    void setGoals(int goals);

    friend class Manager;                                   //Access to protected info
};
#endif