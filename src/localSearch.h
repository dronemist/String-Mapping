#ifndef LOCALSEARCH_H
#define LOCALSEARCH_H
#include <string>
#include <vector>
#include <map>
#include "state.h"
/// Map for the cost vector
typedef std::map<char, std::map<char, int> > costDatabase; 

/// This function runs the local search
/// - Parameters
///   - originalStrings: the original strings
///   - time: time in seconds to run the local search for
state runLocalSearch(std::vector<std::string> &, double, costDatabase &, int);

#endif