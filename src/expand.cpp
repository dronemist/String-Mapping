#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <random>
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
state getNextState(state &currentState, costDatabase &costMap, int extraDashCost) {
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
            if (currentString[j] != '-')
            {
                int k = max(j - 1, 0);
                while(k >= 0 && currentString[k] == '-')
                {
                    newString = currentString;
                    swap(newString[j], newString[k]);
                    newStrings.at(i) = newString;
                    state newState(newStrings, currentState.originalStrings);
                    int temp = costOfState(costMap, newState, extraDashCost);
                    if(temp < minimum)
                    {
                        minimum = temp;
                        minState = newState; 
                    }
                    k--;
                }
                k = min(j + 1, int(currentString.length() - 1));
                while(k < currentString.length() && currentString[k] == '-')
                {
                    newString = currentString;
                    swap(newString[j], newString[k]);
                    newStrings.at(i) = newString;
                    state newState(newStrings, currentState.originalStrings);
                    int temp = costOfState(costMap, newState, extraDashCost);
                    if(temp < minimum)
                    {
                        minimum = temp;
                        minState = newState; 
                    }
                    k++;
                }
                // If we get a dash
                // loop(k, max(0, j - 1), min(int(currentString.length()), j + 2))
                // {
                //     newString = currentString;
                //     if(currentString[k] != '-')
                //     {
                //         // TODO: fix duplication of strings(don't make a newState everytime)
                //         swap(newString[j], newString[k]);
                //         newStrings.at(i) = newString;
                //         state newState(newStrings, currentState.originalStrings);

                //         // Saving the minimum state
                //         // TODO: speed up cost
                //         int temp = costOfState(costMap, newState, extraDashCost);
                //         if(temp < minimum)
                //         {
                //             minimum = temp;
                //             minState = newState; 
                //         }
                //     }
                // }  
            }
                    
        }
    }
    return minState;
}

/// This function returns a random state for restart
/// - Parameters:
///   - n: size of the state to be created
///   - originalStrings: vector consisiting of all the original strings
state randState(int n, vector<string>& originalStrings)
{
    vector<string> ans = originalStrings;
    // Better random then rand()
    random_device rd;
    default_random_engine rng(rd());
    uniform_int_distribution<> distribution(0, n-1);
    int r;
    loop(i, 0, originalStrings.size())
    {
        int no_of_dashes = n - originalStrings.at(i).size();
        ans[i] = originalStrings.at(i);
        loop(j, 0, no_of_dashes)
        {
            r = distribution(rng)%ans[i].size();
            if(r == ans[i].size() - 1)
            ans[i] = ans[i] + '-';
            else
            ans[i] = ans[i].substr(0, r) + '-' + ans[i].substr(r, ans[i].size()-r);
        }
    }
    return state(ans, originalStrings);
}
