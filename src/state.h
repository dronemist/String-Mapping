#ifndef STATE_H
#define STATE_H
#include <string>
#include <vector>
struct state {
    /// original strings without dashes
    std::vector<std::string> originalStrings;

    /// current strings with dashes
    std::vector<std::string> finalStrings;

    /// Returns the cost of the state
    // int cost(costDatabase &, int);
    
    state(std::vector<std::string> &, std::vector<std::string> &);
    state();

    /// This function returns the size of state
    int sizeOfState();

    // TODO: optimise string equality check
    /// This function checks for string equality
    bool equals(state &);
};
#endif