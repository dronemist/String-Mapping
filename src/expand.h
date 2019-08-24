#ifndef EXPAND_H
#define EXPAND_H
#include <string>
#include <vector>
#include "cost.h"
#include "state.h"
/// Map for the cost vector
typedef std::map<char, std::map<char, int> > costDatabase; 

/// This function returns the next state in the sequence
/// - Parameters:
///   - currentState: the current state of the search
///   - costMap: the map containg cost of each matching
extern state nextState(state &, costDatabase &, int);
extern std::vector<std::string> randState(int n, std::vector<std::string>& inputStrings);
#endif
