#include <iostream>
#include <algorithm>
#include "expand.h"

using namespace std;



/// Definition for a 'for' loop
#define loop(i, start, end) for(int i = start; i < end; i++)

/// This function returns the next state in the sequence
/// - Parameters:
///   - currentState: the current state of the search
///   - costMap: the map containg cost of each matching
state nextState(state &currentState, costDatabase &costMap) {
    // Old and new string vectors
    vector<string> currentStrings = currentState.finalStrings;
    vector<string> newStrings;

    // Old and new strings
    string currentString, newString;

    int minimum;

    // Old and new state
    state minState, newState;
    loop(i, 0, currentStrings.size()) 
    {
        currentString = currentStrings.at(i);
        newStrings = currentStrings;
        loop(j, 0, currentString.length())
        {
            if (currentString[j] == '_')
            {
                newString = currentString;
                // If we get a dash
                loop(k, max(0, j - 1), min(int(currentString.length()), j + 2))
                {
                    if(currentString[k] != '_')
                    {
                        // TODO: fix duplication of strings(don't make a newState everytime)
                        swap(newString[j], newString[k]);
                        newStrings.at(i) = newString;
                        state newState(newStrings);

                        // Saving the minimum state
                        // TODO: speed up cost
                        int temp = costOfState(costMap, newState, 5);
                        if(temp < minimum)
                        {
                            minimum = temp;
                            minState = newState; 
                        }
                    }
                }  
            }
                    
        }
    }
    return minState;
}

