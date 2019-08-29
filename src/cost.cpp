#include <iostream>
#include "cost.h"

using namespace std;

/// Definition for a 'for' loop
#define loop(i, start, end) for(int i = start; i < end; i++)

/// This Function compares two strings(F(Xi)) and returns the cost
///  - Parameters: 
///    - string1: string to compute cost
///    - string2: string to compute cost
int costOfTwoStrings(string string1, string string2) {
    
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
///    - extraDashCost: cost of the dash
int conversionCost(string string1) {
    int dashCount = 0;
    loop(i, 0, string1.length())
    {
        if(string1[i] == '-')
            dashCount++;
    }
    return dashCount * extraDashCost;
}

/// This function returns the cost of a state
///  - Parameters: 
///    - costArray: vector containing all the cost
///    - state: state whose cost is to be calculated
///    - extraDashCost: cost of the dash
int costOfState(state &currentState) {
    
    int cost = 0;
    vector<string> strings = currentState.finalStrings;
    // Calculating conversion cost
    loop(i, 0, strings.size())
    {
        cost += conversionCost(strings.at(i));
    }
    // Calculating matching cost
    loop(i, 0, strings.size() - 1)
    {
        loop(j, i + 1, strings.size())
        {
            cost += costOfTwoStrings(strings.at(i), strings.at(j));
        }
    }
    return cost;
}

/// This function returns cost of ith position of the kth string
int costOfIthPosition(state &stateToEvaluate, int i, int k) {
    int cost = 0;
    loop(j, 0, stateToEvaluate.finalStrings.size())
    {
        if(j != k)
        {
            cost += costMap[stateToEvaluate.finalStrings.at(j).at(i)][stateToEvaluate.finalStrings.at(k).at(i)];
        }
    }
    return cost;
}

/// This function calculates cost in O(k) time
/// - Parameters:
///   -  currentState: the current state
///   -  i, j, k: position i and j are swapped of string k
int costFromLastState(state &currentState, int i, int j, int k) {

    int currCost = costOfIthPosition(currentState, i, k) +
    costOfIthPosition(currentState, j, k);
    // New state
    state newState(currentState.finalStrings);
    swap(newState.finalStrings.at(k)[i], newState.finalStrings.at(k)[j]); 

    int newCost = costOfIthPosition(newState, i, k) +
    costOfIthPosition(newState, j, k);

    return currentState.cost - currCost + newCost;
}