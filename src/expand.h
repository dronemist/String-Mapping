#ifndef EXPAND_H
#define EXPAND_H
#include <string>
#include <vector>
#include "cost.h"
#include "state.h"
/// Map for the cost vector
typedef std::map<char, std::map<char, int> > costDatabase; 
extern state nextState(state &, costDatabase &);
#endif