#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include "expand.h"

using namespace std;

/// Map for the cost vector
typedef std::map<char, std::map<char, int> > costDatabase; 

/// Definition for a 'for' loop
#define loop(i, start, end) for(int i = start; i < end; i++)


/// This function returns the size of longest string in the vector
/// - Parameters
///   - strings: the vector to evaluate
int maxLength(vector<string> strings) {
    int maximum = 0;
    loop(i, 0, strings.size())
    {
        maximum = max(maximum, int(strings.at(i).size()));
    }
    return maximum;
}

/// This function runs the local search
/// - Parameters
///   - originalStrings: the original strings
///   - time: time in seconds to run the local search for
state runLocalSearch(vector<string> &originalStrings, double time,
costDatabase &cost, int extraDashCost) {

    int currentSize = maxLength(originalStrings);
    // currentSize += 3;
    state currentState = randState(17, originalStrings), nextState, minState, previousState;
    minState = currentState;
    previousState = currentState;
    clock_t begin = clock();
    double elapsed_secs = 0;
    // if time finished exit loop
    while (elapsed_secs < time)
    {
        nextState = getNextState(currentState, cost, extraDashCost);
        if(nextState.equals(currentState))
        {
            // Random restart
            // currentSize++;
            currentState = randState(17, originalStrings);
            // loop(i, 0, currentState.finalStrings.size())
            // {
            //     cout<<currentState.finalStrings.at(i)<<endl;
            // }
            // cout<<costOfState(cost, currentState, extraDashCost)<<endl;
        }
        else
        {
            // continue
            currentState = nextState;
            if(costOfState(cost, minState, extraDashCost) > costOfState(cost, currentState, extraDashCost))
            {
                minState = currentState;
            }
        }
        clock_t end = clock();
        elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
        
    }
    return minState;
}
