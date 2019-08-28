#ifndef COST_INCLUDE
#define COST_INCLUDE
#include <string>
#include <vector>
#include <map>
#include "state.h"
#include "fileReader.h"

/// This function returns the cost of a state
///  - Parameters: 
///    - costArray: vector containing all the cost
///    - state: state whose cost is to be calculated
///    - costOfDash: cost of the dash
extern int costOfState(state &);

/// This function calculates cost in O(k) time
/// - Parameters:
///   -  currentState: the current state
///   -  i, j, k: position i and j are swapped of string k
int costFromLastState(state &, int, int, int);

#endif