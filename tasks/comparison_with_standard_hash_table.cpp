#include <ctime>
#include <unordered_map>

#include "Hashtable.hpp"

void compareGet(std::unordered_map<int, double> stdHashTable, Hashtable<int, double> myHashTable, size_t numberOfInputs);
void compareInput(std::unordered_map<int, double> &stdHashTable, Hashtable<int, double> &myHashTable, size_t numberOfInputs);

template <typename Key, typename Value>
size_t Hashtable<Key, Value>::hashFunction(Key x) {
    int s = 1, result = 0;
    for (int i = 0; i < 3; ++i) {
        result += s * static_cast<int>(x + i, i);
        s *= s + 1;
    }

    return static_cast<size_t>(result);
}

void compareInput(std::unordered_map<int, double> &stdHashTable, Hashtable<int, double> &myHashTable, size_t numberOfInputs) {
    unsigned int myStartTime = std::clock();
    for (size_t i = 0; i < numberOfInputs; ++i) {
        myHashTable.inputValue(i, static_cast<double>(rand() / RAND_MAX * numberOfInputs));
    }
    unsigned int myEndTime = std::clock();
    unsigned int myTime = myEndTime - myStartTime;

    unsigned int stdStartTime = std::clock();
    for (size_t i = 0; i < numberOfInputs; ++i) {
        stdHashTable.insert({i, static_cast<double>(rand() / RAND_MAX * numberOfInputs)});
    }
    unsigned int stdEndTime = std::clock();
    unsigned int stdTime = stdEndTime - stdStartTime;
    std::cout << "My Hashtable input time for " << numberOfInputs << ": " << myTime << '\n';
    std::cout << "Std Hashtable input time for " << numberOfInputs << ": " << stdTime;
}

void compareGet(std::unordered_map<int, double> stdHashTable, Hashtable<int, double> myHashTable, size_t numberOfInputs) {
    std::clock_t myStartTime = std::clock();
    for (size_t i = 0; i < numberOfInputs; ++i) {
        myHashTable.getValue(i);
    }
    std::clock_t myEndTime = std::clock();
    std::clock_t mytime = myEndTime - myStartTime;

    std::clock_t stdStartTime = std::clock();
    for (size_t i = 0; i < numberOfInputs; ++i) {
        stdHashTable[i];
    }
    std::clock_t stdEndTime = std::clock();
    std::clock_t stdtime = stdEndTime - stdStartTime;

    std::cout << "My Hashtable get time for " << numberOfInputs << ": " << mytime << '\n';
    std::cout << "Std Hashtable get time for " << numberOfInputs << ": " << stdtime << '\n';
}

int main() {
    Hashtable<int, double> myHashTable = Hashtable<int, double>();
    std::unordered_map<int, double> stdHashTable = std::unordered_map<int, double>();
    compareInput(stdHashTable, myHashTable, 50000);
    std::cout << '\n';
    compareGet(stdHashTable, myHashTable, 50000);

    return 0;
}
