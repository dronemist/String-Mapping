#ifndef COST_INCLUDE
#define COST_INCLUDE
#include <string>
#include <vector>
#include <map>
#include "state.h"

/// Map for the cost vector
typedef std::map<char, std::map<char, int> > costDatabase; 

/// This function returns the cost of a state
///  - Parameters: 
///    - costArray: vector containing all the cost
///    - state: state whose cost is to be calculated
///    - costOfDash: cost of the dash
extern int costOfState(costDatabase &, state &, int);
#endif