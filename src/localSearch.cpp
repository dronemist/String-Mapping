#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include "state.h"
#include "expand.h"

using namespace std;

/// Map for the cost vector
typedef std::map<char, std::map<char, int> > costDatabase; 

/// Definition for a 'for' loop
#define loop(i, start, end) for(int i = start; i < end; i++)

/// This function runs the local search
/// - Parameters
///   - originalStrings: the original strings
///   - time: time in seconds to run the local search for
state runLocalSearch(vector<string> &originalStrings, double time,
costDatabase &cost, int extraDashCost) {

    int currentSize = maxLength(originalStrings);
    state currentState = randState(currentSize, originalStrings), nextState;
    clock_t begin = clock();
    double elapsed_secs = 0;
    // if time finished exit loop
    while (elapsed_secs < time)
    {
        nextState = getNextState(currentState, cost, extraDashCost);
        if(nextState.equals(currentState))
        {
            // Random restart
            currentSize++;
            currentState = randState(currentSize, originalStrings);
        }
        else
        {
            // continue
            currentState = nextState;
        }
        clock_t end = clock();
        elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
    }
    return currentState;
}

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