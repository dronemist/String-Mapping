#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "cost.h"
using namespace std;

/// Map for the cost vector
#define costDatabase map<char, map<char, int> >

/// Definition for a 'for' loop
#define loop(i, start, end) for(int i = start; i < end; i++)

/// This Function compares two strings(F(Xi)) and returns the cost
///  - Parameters: 
///    - string1: string to compute cost
///    - string2: string to compute cost
///    - cost: a map of costs
int costOfTwoStrings(string string1, string string2, costDatabase &costMap) {
    
    int cost = 0;
    loop(i, 0, string1.length()) 
    {
        cost += costMap[string1[i]][string2[i]];
    }
}

/// This function computes the conversion cost of a string from x to F(x)
///  - Parameters: 
///    - string1: string to compute cost
///    - costOfDash: cost of the dash
int conversionCost(string string1, int costOfDash) {
    int dashCount = 0;
    loop(i, 0, string1.length())
    {
        if(string1[i] == '_')
            dashCount++;
    }
    return dashCount * costOfDash;
}

// TODO: change parameter to state

/// This function returns the cost of a state
///  - Parameters: 
///    - costArray: vector containing all the cost
///    - strings: vector of all F(Xi)
///    - costOfDash: cost of the dash
int cost(costDatabase &costMap, vector<string> &strings, int costOfDash) {
    
    int cost = 0; 
    // Calculating conversion cost
    loop(i, 0, strings.size())
    {
        cost += conversionCost(strings.at(i), costOfDash);
    }
    // Calculating matching cost
    loop(i, 0, strings.size() - 1)
    {
        loop(j, i + 1, strings.size())
        {
            cost += costOfTwoStrings(strings.at(i), strings.at(j), costMap);
        }
    }

    return cost;
}