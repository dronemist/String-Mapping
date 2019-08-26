#include <iostream>
#include "cost.h"

using namespace std;

/// Definition for a 'for' loop
#define loop(i, start, end) for(int i = start; i < end; i++)

/// This Function compares two strings(F(Xi)) and returns the cost
///  - Parameters: 
///    - string1: string to compute cost
///    - string2: string to compute cost
///    - cost: a map of costs
int costOfTwoStrings(string string1, string string2, costDatabase &costMap) {
    
    int cost = 0;
    loop(i, 0, string1.length()) 
    {
        cost += costMap[string1[i]][string2[i]];
    }
    return cost;
}

/// This function computes the conversion cost of a string from x to F(x)
///  - Parameters: 
///    - string1: string to compute cost
///    - costOfDash: cost of the dash
int conversionCost(string string1, int costOfDash) {
    int dashCount = 0;
    loop(i, 0, string1.length())
    {
        if(string1[i] == '_')
            dashCount++;
    }
    return dashCount * costOfDash;
}

// TODO: make this function more effecient (given the previous state)

/// This function returns the number of dashes aligned across all strings in the state
///  - Parameters: 
///    - currentState: the current state of the local search
int numberOfAlignedDashes(state &currentState) {
    
    int numberOfDashes = 0;
    // TODO: fix border case if current state has no strings 
    loop(j, 0, currentState.finalStrings.at(0).length())
    {
        bool dashAligned = true;
        loop(i, 0, currentState.finalStrings.size())
        {
            if(currentState.finalStrings.at(i)[j] != '_')
            {
                dashAligned = false;
                break;
            }
        }
        if(dashAligned)
            numberOfDashes++;
    }
    return numberOfDashes;
}

// TODO: make cost function more effecient (given the previous state)

/// This function returns the cost of a state
///  - Parameters: 
///    - costArray: vector containing all the cost
///    - state: state whose cost is to be calculated
///    - costOfDash: cost of the dash
int costOfState(costDatabase &costMap, state &currentState, int costOfDash) {
    
    int cost = 0;
    int sizeOfState = currentState.sizeOfState(); 
    // TODO: a copy is being formed, fix it!
    vector<string> strings = currentState.finalStrings;
    // Calculating conversion cost
    loop(i, 0, strings.size())
    {
        cost += conversionCost(strings.at(i), costOfDash);
    }
    int numberOfDashesAligned = numberOfAlignedDashes(currentState);
    // Calculating matching cost
    loop(i, 0, strings.size() - 1)
    {
        loop(j, i + 1, strings.size())
        {
            cost += costOfTwoStrings(strings.at(i), strings.at(j), costMap);
        }
    }
    // cost = cost - (costOfDash * numberOfDashesAligned * sizeOfState) - 
    // (((sizeOfState) * (sizeOfState - 1) / 2) * costMap['_']['_']);
    return cost;
}