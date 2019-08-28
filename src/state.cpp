#include <iostream>
#include <string>
#include "state.h"
using namespace std;

/// Definition for a 'for' loop
#define loop(i, start, end) for(int i = start; i < end; i++)

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
    if(finalStrings.size() != 0)
        return finalStrings.at(0).length();
    else
        return 0;  
}

// TODO: optimise string equality check
/// This function checks for string equality
bool state::equals(state &otherState) {
    bool isEqual = true;
    if(sizeOfState() != otherState.sizeOfState())
        return false;
    loop(i, 0, finalStrings.size()) 
    {
        if(finalStrings.at(i).compare(otherState.finalStrings.at(i)))
        {
            isEqual = false;
            break;
        }
    }
    return isEqual;
}