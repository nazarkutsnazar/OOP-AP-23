#ifndef FOOTBALL_H
#define FOOTBALL_H

#include "team.h"
using namespace std;

class Football : public Team {
private:
    int goalsScored;

public:
    Football(const string& teamName = "", int count = 0, int goals = 0);
    void setGoalsScored(int goals);

    void OutputInfo() const override;
};
#endif
