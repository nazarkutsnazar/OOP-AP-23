#include <iostream>
#include <vector>
#include <memory>
#include "manager.h"
using namespace std;

int main() {
    Manager teams;
    shared_ptr<Team> footballTeam = make_shared<Football>("Karpaty", 29, 49);
    shared_ptr<Team> basketballTeam = make_shared<Basketball>("Lviv_P BC", 40, 60);
    teams.addTeam(footballTeam);
    teams.addTeam(basketballTeam);

    int choice;

    while (true) {
        cout << endl
             << "Menu" << endl
             << "1 - Add Football Team" << endl
             << "2 - Add Basketball Team" << endl
             << "3 - Remove Team" << endl
             << "4 - Output Team List" << endl
             << "5 - Save Teams to File" << endl
             << "6 - Load Teams from File" << endl
             << "0 - Exit" << endl;

        cout << "Enter your choice: ";
        cin >> ws >> choice;

        try {
            if (choice == 1) {
                string name;
                int members, goals;

                cout << "Enter football team name: ";
                cin >> ws;
                getline(cin, name);

                cout << "Enter number of members: ";
                cin >> members;

                cout << "Enter number of goals scored: ";
                cin >> goals;

                shared_ptr<Team> footballTeam = make_shared<Football>(name, members, goals);
                teams.addTeam(footballTeam);

                cout << "Football team added successfully!" << endl;

            } else if (choice == 2) {
                string name;
                int members, points;

                cout << "Enter basketball team name: ";
                cin >> ws;
                getline(cin, name);

                cout << "Enter number of members: ";
                cin >> members;

                cout << "Enter number of points scored: ";
                cin >> points;

                shared_ptr<Team> basketballTeam = make_shared<Basketball>(name, members, points);
                teams.addTeam(basketballTeam);

                cout << "Basketball team added successfully!" << endl;

            } else if (choice == 3) {
                string name;

                cout << "Enter the name of the team to remove: ";
                cin >> ws;
                getline(cin, name);

                teams.removeTeam(name);

            } else if (choice == 4) {
                teams.displayTeams();
            
            } else if (choice == 5) {
            teams.saveTeams("teams_data.txt");
            
            } else if (choice == 6) {
            teams.loadTeams("teams_data.txt");

            } else if (choice == 0) {
                cout << "Exiting program..." << endl;
                break;

            } else {
                throw invalid_argument("Invalid choice. Please enter a valid option.");
            }
        } catch (const invalid_argument& e) {
            cerr << "Error: " << e.what() << endl;
        } catch (const out_of_range& e) {
            cerr << "Error: " << e.what() << endl;
        } catch (...) {
            cerr << "An unknown error occurred!" << endl;
        }
    }
    return 0;
}
