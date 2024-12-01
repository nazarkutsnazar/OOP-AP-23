#include <iostream>
#include <vector>
#include <algorithm>
#include "football.h"
#include "basketball.h"
using namespace std;

void outputTeams(const vector<Football>& footballTeams, const vector<Basketball>& basketballTeams) {
    cout << endl << "Football Teams:" << endl;
    for (const auto& team : footballTeams) {
        team.OutputInfo();
    }

    cout << endl << "Basketball Teams:" << endl;
    for (const auto& team : basketballTeams) {
        team.OutputInfo();
    }
}

int main() {
    int choice;
    vector<Football> footballTeams;
    vector<Basketball> basketballTeams;

    // приклади команд до списку
    footballTeams.emplace_back("Karpaty", 29, 49);
    basketballTeams.emplace_back("Lviv_P BC", 40, 60);

    while (true) {
        cout << endl << "Menu" << endl
             << "1 - Add Football Team" << endl
             << "2 - Add Basketball Team" << endl
             << "3 - Remove Football Team" << endl
             << "4 - Remove Basketball Team" << endl
             << "5 - Output Team List" << endl
             << "0 - Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();  // Очищення буфера після введення числа

        if (choice == 1) {
            // Додавання футбольної команди
            string name;
            int membersCount, goals;
            
            cout << "Enter the name of the football team: ";
            getline(cin, name);
            
            cout << "Enter the number of members: ";
            cin >> membersCount;
            
            cout << "Enter the number of goals scored: ";
            cin >> goals;
            cin.ignore();

            footballTeams.emplace_back(name, membersCount, goals);
            cout << "Football team added successfully!" << endl;
        
        } else if (choice == 2) {
            // Додавання баскетбольної команди
            string name;
            int membersCount, points;
            
            cout << "Enter the name of the basketball team: ";
            getline(cin, name);
            
            cout << "Enter the number of members: ";
            cin >> membersCount;
            
            cout << "Enter the number of points scored: ";
            cin >> points;
            cin.ignore();

            basketballTeams.emplace_back(name, membersCount, points);
            cout << "Basketball team added successfully!" << endl;
       
        } else if (choice == 3) {
            // Видалення футбольної команди
            string name;
            cout << "Enter the name of the football team to remove: ";
            getline(cin, name);

            auto it = remove_if(footballTeams.begin(), footballTeams.end(), [&name](const Football& team) {
                return team.getName() == name;
            });

            if (it != footballTeams.end()) {
                footballTeams.erase(it, footballTeams.end());
                cout << "Football team removed successfully!" << endl;
            } else {
                cout << "Football team not found!" << endl;
            }

        } else if (choice == 4) {
            // Видалення баскетбольної команди
            string name;
            cout << "Enter the name of the basketball team to remove: ";
            getline(cin, name);

            auto it = remove_if(basketballTeams.begin(), basketballTeams.end(), [&name](const Basketball& team) {
                return team.getName() == name;
            });

            if (it != basketballTeams.end()) {
                basketballTeams.erase(it, basketballTeams.end());
                cout << "Basketball team removed successfully!" << endl;
            } else {
                cout << "Basketball team not found!" << endl;
            }

        } else if (choice == 5) {
            // Виведення списку команд
            outputTeams(footballTeams, basketballTeams);

        } else if (choice == 0) {
            // Вихід з програми
            cout << "Exiting program..." << endl;
            break;
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
