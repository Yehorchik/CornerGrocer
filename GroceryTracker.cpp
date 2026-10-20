#include "GroceryTracker.h"

#include <fstream>
#include <iostream>
#include <stdexcept>

GroceryTracker::GroceryTracker(const string& inputFile) {
    ifstream input(inputFile);
    if (!input) {
        throw runtime_error("Could not open " + inputFile +
                            ". Run from the folder containing the input file.");
    }

    string item;
    while (input >> item) {
        ++itemFrequencies[item];
    }
    if (input.bad() || (input.fail() && !input.eof())) {
        throw runtime_error("Could not finish reading " + inputFile);
    }
}

size_t GroceryTracker::GetFrequency(const string& item) const {
    // find() so a search doesn't add the item to the map
    const auto found = itemFrequencies.find(item);
    return found == itemFrequencies.end() ? 0 : found->second;
}

void GroceryTracker::PrintFrequencies() const {
    for (const auto& entry : itemFrequencies) {
        cout << entry.first << " " << entry.second << '\n';
    }
}

void GroceryTracker::PrintHistogram() const {
    for (const auto& entry : itemFrequencies) {
        cout << entry.first << " " << string(entry.second, '*') << '\n';
    }
}

void GroceryTracker::SaveBackup(const string& outputFile) const {
    ofstream output(outputFile);
    if (!output) {
        throw runtime_error("Could not create " + outputFile);
    }
    for (const auto& entry : itemFrequencies) {
        output << entry.first << " " << entry.second << '\n';
    }
    output.close();
    if (!output) {
        throw runtime_error("Could not finish writing " + outputFile);
    }
}
