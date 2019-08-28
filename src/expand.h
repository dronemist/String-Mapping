#ifndef EXPAND_H
#define EXPAND_H
#include <string>
#include <vector>
#include "cost.h"
#include "fileReader.h"
#include "state.h"


/// This function returns the next state in the sequence
/// - Parameters:
///   - currentState: the current state of the search
///   - costMap: the map containg cost of each matching
extern state getNextState(state &);

/// This function returns a random state for restart
/// - Parameters:
///   - n: size of the state to be created
///   - inputStrings: vector consisiting of all the original strings
extern state randState(int n, std::vector<std::string>& inputStrings);
#endif
