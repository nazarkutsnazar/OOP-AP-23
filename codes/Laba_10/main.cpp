#include <iostream>
#include <vector>
#include <algorithm>
#include "moreequal.h"
using namespace std;

int main(void) {
    vector<MoreEqual> originalStrings = {
        MoreEqual("Aqua"),
        MoreEqual("Little"),
        MoreEqual("Zoo"),
        MoreEqual("Finger")
    };

    vector<MoreEqual> sortedStrings = originalStrings;
    vector<MoreEqual> removedStrings;

    int choice;
    while (true) {
        cout << endl <<"        Menu:" << endl
             << "[1] - Set new string" << endl
             << "[2] - Sort alphabetically" << endl
             << "[3] - Remove a character" << endl
             << "[4] - Show original strings" << endl
             << "[5] - Show sorted strings" << endl
             << "[6] - Show strings after character removal" << endl
             << "[0] - Exit" << endl;

        cout << "Enter your choice: ";
        cin >> ws >> choice;

        if (choice == 1) {
            MoreEqual newString;
            newString.setStr();
            originalStrings.push_back(newString);
            sortedStrings = originalStrings; // Оновлює список для сортування

        } else if (choice == 2) {
            sort(sortedStrings.begin(), sortedStrings.end(),
                 [](const MoreEqual& a, const MoreEqual& b) {
                     return !(a >= b);
                 });
            cout << "Strings sorted successfully." << endl;

        } else if (choice == 3) {
            char symbolToRemove;
            cout << "Enter the character to remove: ";
            cin >> ws >> symbolToRemove;

            removedStrings = originalStrings; // Оновлює список для видалення
            for (auto& str : removedStrings) {
                str = str - symbolToRemove;
            }
            cout << "Character removed successfully." << endl;

        } else if (choice == 4) {
            cout << endl << "Original strings:" << endl;
            for (const auto& str : originalStrings) {
                cout << str << endl;
            }

        } else if (choice == 5) {
            cout << endl << "Sorted strings:" << endl;
            for (const auto& str : sortedStrings) {
                cout << str << endl;
            }

        } else if (choice == 6) {
            if (removedStrings.empty()) {
                cout << "No characters removed yet. Please choose option [3] first." << endl;
            } else {
                cout << endl << "Strings after character removal:" << endl;
                for (const auto& str : removedStrings) {
                    cout << str << endl;
                }
            }

        } else if (choice == 0) {
            cout << "Exiting program..." << endl;
            break;

        } else {
            cerr << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
