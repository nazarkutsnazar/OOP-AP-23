#ifndef BASKETBALL_H
#define BASKETBALL_H

#include "team.h"
#include <iostream>
#include <string>

class Manager;

class Basketball : public Team {
protected:
    int scored_points;

public:
    Basketball() : Team("", 0), scored_points(0) {} 

    Basketball(const string& name,
     int members, int points);  
    
    ~Basketball();                

    void display() const override;          

    int getPoints() const;

    void setPoints(int points);

    friend class Manager;      
};
#endif