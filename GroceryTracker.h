#ifndef GROCERY_TRACKER_H
#define GROCERY_TRACKER_H

#include <cstddef>
#include <map>
#include <string>

using namespace std;

// counts how many times each item was bought
class GroceryTracker {
public:
    explicit GroceryTracker(const string& inputFile);
    size_t GetFrequency(const string& item) const;
    void PrintFrequencies() const;
    void PrintHistogram() const;
    void SaveBackup(const string& outputFile) const;

private:
    map<string, size_t> itemFrequencies;
};

#endif  // GROCERY_TRACKER_H
