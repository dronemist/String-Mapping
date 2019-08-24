#include <iostream>
#include <string>
#include "state.h"
using namespace std;

// /// Map for the cost vector
// typedef map<char, map<char, int> > costDatabase; 

// /// This function returns the cost of the state
// /// - Parameters: 
// ///   - costMap: the cost map
// ///   - costOfDash: cost of extra dash
// int state::cost(costDatabase &costMap, int costOfDash)
// {
//     costOfState(costMap, *this, costOfDash);
// }

/// Constructor for state
state::state(vector<string> &strings, vector<string> &originalString) {
    finalStrings = strings;
    originalStrings = originalString;
}

/// Constructor for state
state::state() {
    vector<string> temp;
    finalStrings = temp;
    originalStrings = temp;
}

/// This function returns the size of state
int state::sizeOfState() {
    return finalStrings.size();
}