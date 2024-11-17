#include "team.h"
#include <iostream>
using namespace std;

Team::Team(const string& teamName, int count) {         // Конструктор з параметрами
    name = teamName;
    membersCount = count;
}
Team::~Team() {                                         // Деструктор
    cout << "Destructor" << endl;
}

void Team::setName(const string& teamName) {            // Встановлення імені
    if (!teamName.empty()) {
        name = teamName;
    } else {
        cerr << "Invalid team name." << endl;
    }
}

void Team::setMembersCount(int count) {                 // Встановлення числа гравців
    if (count > 0) {
        membersCount = count;
    } else {
        cerr << "Invalid members count." << endl;
    }
}

void Team::OutputInfo() const {                         // Виведення інформації
    cout << "Team Name: " << name << endl
         << "Members count: " << membersCount << endl;
}
