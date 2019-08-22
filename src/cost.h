#ifndef COST_INCLUDE
#define COST_INCLUDE
#include <string>
#include <vector>
#include <map>
#include "state.h"

/// Map for the cost vector
typedef std::map<char, std::map<char, int> > costDatabase; 

extern int costOfState(costDatabase &, state &, int);
#endif