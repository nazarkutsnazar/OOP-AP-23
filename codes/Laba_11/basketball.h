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
    Basketball() : Team("", 0), scored_points(0) {} //The default constructor

    Basketball(const string& name,
     int members, int points);                      //Constructor with parameters
    
    ~Basketball();                                  //Destructor

    void display() const override;                  //Virtual method

    int getPoints() const;

    void setPoints(int points);

    friend class Manager;                           //Access to protected info
};
#endif