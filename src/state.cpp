#include <iostream>
#include <string>
#include "state.h"
// #include "cost.h"
using namespace std;

/// Definition for a 'for' loop
#define loop(i, start, end) for(int i = start; i < end; i++)

/// Constructor for state
// TODO: calculate cost in the constructor
state::state(vector<string> initialStrings) {
    finalStrings = initialStrings;
    originalStrings = strings;
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