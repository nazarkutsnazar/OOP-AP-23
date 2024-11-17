#ifndef BASKETBALL_H
#define BASKETBALL_H

#include "team.h"
using namespace std;

class Basketball : public Team {
private:
    int pointsScored;

public:
    Basketball(const string& teamName = "", int count = 0, int points = 0);
    void setPointsScored(int points);

    void OutputInfo() const override;
};
#endif
