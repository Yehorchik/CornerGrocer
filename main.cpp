#include "GroceryTracker.h"

#include <exception>
#include <iostream>
#include <sstream>

void PrintMenu() {
    cout << "\nCorner Grocer\n"
         << "1. Find an item\n"
         << "2. Print all frequencies\n"
         << "3. Print histogram\n"
         << "4. Exit\n"
         << "Choose an option (1-4): ";
}

// only accept a whole number from 1 to 4
bool ParseChoice(const string& line, int& choice) {
    istringstream input(line);
    string extra;
    return (input >> choice) && !(input >> extra) && choice >= 1 && choice <= 4;
}

void SearchItem(const GroceryTracker& tracker) {
    cout << "Enter item (case-sensitive, for example Cranberries): ";
    string line;
    if (!getline(cin, line)) {
        return;
    }
    istringstream input(line);
    string item;
    string extra;
    if (!(input >> item) || (input >> extra)) {
        cout << "Please enter one item name.\n";
        return;
    }
    cout << item << " frequency: " << tracker.GetFrequency(item) << '\n';
}

int main() {
    try {
        // uncomment one of the test files to try it instead
        const string inputFile = "CS210_Project_Three_Input_File.txt";
        // const string inputFile = "test_inputs/small.txt";
        // const string inputFile = "test_inputs/messy_whitespace.txt";
        // const string inputFile = "test_inputs/empty.txt";
        // const string inputFile = "test_inputs/large.txt";

        const GroceryTracker tracker(inputFile);
        tracker.SaveBackup("frequency.dat");

        string line;
        while (true) {
            PrintMenu();
            if (!getline(cin, line)) {
                cout << "\nInput closed. Goodbye!\n";
                break;
            }
            int choice = 0;
            if (!ParseChoice(line, choice)) {
                cout << "Invalid choice. Enter a whole number from 1 to 4.\n";
                continue;
            }
            switch (choice) {
            case 1:
                SearchItem(tracker);
                break;
            case 2:
                tracker.PrintFrequencies();
                break;
            case 3:
                tracker.PrintHistogram();
                break;
            case 4:
                cout << "Goodbye!\n";
                return 0;
            }
        }
    } catch (const exception& error) {
        cerr << "Error: " << error.what() << '\n';
        return 1;
    }
    return 0;
}
