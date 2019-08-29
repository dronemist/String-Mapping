#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <random>
#include <fstream>
#include "expand.h"

using namespace std;

/// Definition for a 'for' loop
#define loop(i, start, end) for(int i = start; i < end; i++)

/// This function writes to a file
void write(state &minState) {
    ofstream fout;
    fout.open(outputFileName);
    loop(j, 0, minState.finalStrings.size()-1)
    {
        fout<<minState.finalStrings.at(j)<<"\n";
    }
    fout<<minState.finalStrings.at(minState.finalStrings.size()-1);
    fout.close();
}

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
void runLocalSearch() {

    int currentSize = maxLength();
    state currentState = randState(currentSize), nextState, minState;
    currentState.cost = costOfState(currentState);
    minState = currentState;
    clock_t begin = clock();
    double elapsed_secs = 0;
    float currentRunningTime = totalTime / currentSize;
    // if time finished exit loop
    while (elapsed_secs < totalTime - 5)
    {
        nextState = getNextState(currentState);
        if(nextState.equals(currentState))
        {
            // Random restart
            if(elapsed_secs > currentRunningTime)
            {
                currentSize++;
                currentRunningTime += currentRunningTime;
            }
            currentState = randState(currentSize);
            currentState.cost = costOfState(currentState);
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
    write(minState);
}
