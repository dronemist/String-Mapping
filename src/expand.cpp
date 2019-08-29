#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <random>
#include <cmath>
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
state getNextState(state &currentState) {
    // Old and new string vectors
    vector<string> currentStrings = currentState.finalStrings;
    vector<string> newStrings;

    // Old and new strings
    string currentString, newString;

    int minimum = currentState.cost;

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
                    int temp = costFromLastState(currentState, j, k, i);
                    if(temp < minimum)
                    {
                        state newState(newStrings);
                        newState.cost = temp;
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
                    int temp = costFromLastState(currentState, j, k, i);
                    if(temp < minimum)
                    {
                        state newState(newStrings);
                        newState.cost = temp;
                        minimum = temp;
                        minState = newState; 
                    }
                    k++;
                }
            }
                    
        }
    }
    return minState;
}

/// This function returns a random state for restart
/// - Parameters:
///   - n: size of the state to be created
///   - originalStrings: vector consisiting of all the original strings
state randState(int n)
{
    vector<string> ans;
    // Better random then rand()
    random_device rd;
    default_random_engine rng(rd());
    uniform_int_distribution<> distribution(0, n-1);
    int r;
    loop(i, 0, strings.size())
    {
        string currentString = strings.at(i);
        int sizeOfString = currentString.size();
        string ansTemp(sizeOfString, '*');
        int no_of_dashes = n - sizeOfString;
        ansTemp += string(no_of_dashes, '-');
        shuffle(ansTemp.begin(), ansTemp.end(), rng);
        int k = 0;
        loop(j, 0, n)
        {
            if(ansTemp[j] == '*')
            {
                ansTemp[j] = currentString[k];
                k++;
            }
        }
        ans.push_back(ansTemp);
    }
    return state(ans);
}
