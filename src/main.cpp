#include <iostream>
#include <algorithm>
#include <map>
#include "cost.h"
#include "fileReader.h"
#include "expand.h"
#include "state.h"
using namespace std;

/// Map for the cost vector
typedef map<char, map<char, int> > costDatabase; 

/// Definition for a 'for' loop
#define loop(i, start, end) for(int i = start; i < end; i++)

int main () {
  float time;
  string vocabulary;
  vector<string> strings;
  costDatabase cost;
  int extraDashCost;
  fileReader("input.txt", time, vocabulary, strings, cost, extraDashCost);
  string s1 = "ACTG_A";
  string s2 = "TACTGC";
  vector<string> t;
  t.push_back(s1);
  t.push_back(s2);
  state temp(t);
  state n = nextState(temp, cost);
  loop(i, 0, n.finalStrings.size())
  {
    cout<<n.finalStrings.at(i)<<endl;
  }
}