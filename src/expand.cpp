#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>
#include "expand.h"

using namespace std;



/// Definition for a 'for' loop
#define loop(i, start, end) for(int i = start; i < end; i++)

/// This function returns the next state in the sequence
/// - Parameters:
///   - currentState: the current state of the search
///   - costMap: the map containg cost of each matching
///   - extraDashCost: cost of adding an extra dash
state nextState(state &currentState, costDatabase &costMap, int extraDashCost) {
    // Old and new string vectors
    vector<string> currentStrings = currentState.finalStrings;
    vector<string> newStrings;

    // Old and new strings
    string currentString, newString;

    int minimum = costOfState(costMap, currentState, extraDashCost);

    // Old and new state
    state minState = currentState, newState;
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
                        state newState(newStrings, currentState.originalStrings);

                        // Saving the minimum state
                        // TODO: speed up cost
                        int temp = costOfState(costMap, newState, extraDashCost);
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

/// This function returns a random state for restart
/// - Parameters:
///   - n: size of the state
///   - inputStrings: vector consisiting of all the strings
std::vector<std::string> randState(int n, std::vector<std::string>& inputStrings)
{
    std::vector<std::string> ans = inputStrings;
    int r;
    loop(i, 0, inputStrings.size())
    {
        int no_of_dashes = n - inputStrings.at(i).size();
        ans[i] = inputStrings.at(i);
        random();
        loop(j, 0, no_of_dashes)
        {
            r = rand()%n;
            ans[i] = ans[i].substr(0, r) + '-' + ans[i].substr(r, ans[i].size()-r);
        }
    }
    return ans;
}