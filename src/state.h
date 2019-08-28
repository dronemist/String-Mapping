#ifndef STATE_H
#define STATE_H
#include <string>
#include "fileReader.h"
#include <vector>
struct state {
    /// original strings without dashes
    std::vector<std::string> originalStrings;

    /// current strings with dashes
    std::vector<std::string> finalStrings;

    /// Returns the cost of the state
    // int cost(costDatabase &, int);
    
    state(std::vector<std::string>);
    state();

    /// This function returns the cost of state
    int sizeOfState();

    /// The cost of the state
    int cost;

    // TODO: optimise string equality check
    /// This function checks for string equality
    bool equals(state &);
};
#endif