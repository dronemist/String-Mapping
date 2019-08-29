#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <random>
#include "expand.h"

using namespace std;

/// Map for the cost vector
typedef std::map<char, std::map<char, int> > costDatabase; 

/// Definition for a 'for' loop
#define loop(i, start, end) for(int i = start; i < end; i++)


/// This function returns the size of longest string in the vector
/// - Parameters
///   - strings: the vector to evaluate
int maxLength() {
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
state runLocalSearch() {

    int currentSize = maxLength();
    currentSize = 17;
    state currentState = randState(currentSize), nextState, minState;
    currentState.cost = costOfState(currentState);
    int numberOfRandomRestarts = 0;
    minState = currentState;
    clock_t begin = clock();
    double elapsed_secs = 0;
    // if time finished exit loop
    while (elapsed_secs < totalTime)
    {
        nextState = getNextState(currentState);
        if(nextState.equals(currentState))
        {
            // Random restart
            // currentSize++;
            // if(numberOfRandomRestarts == 0) {
            //     currentSize++;
            //     numberOfRandomRestarts = 21;
            // }
            // cout<<numberOfRandomRestarts++<<endl;
            currentState = randState(currentSize);
            currentState.cost = costOfState(currentState);
            // if(currentState.cost == 706)
            // break;
            // loop(i, 0, currentState.finalStrings.size())
            // {
            //     cout<<currentState.finalStrings.at(i)<<endl;
            // }
            // cout<<currentState.cost<<endl;
            // numberOfRandomRestarts--;
        }
        else
        {
            // continue
            currentState = nextState;
            if(minState.cost > currentState.cost)
            {
                minState = currentState;
            }
        }
        clock_t end = clock();
        elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
        
    }
    return minState;
}
