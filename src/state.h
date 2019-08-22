#ifndef STATE_H
#define STATE_H
#include <string>
#include <vector>
struct state {
    std::vector<std::string> finalStrings;
    /// Returns the cost of the state
    // int cost(costDatabase &, int);
    state(std::vector<std::string> &);
    state();
};
#endif