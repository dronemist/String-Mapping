#include <iostream>
#include <algorithm>
#include <map>
#include "cost.h"
#include "fileReader.h"
#include "expand.h"
#include "state.h"
#include "localSearch.h"
using namespace std;

/// Map for the cost vector
typedef map<char, map<char, int> > costDatabase; 

/// Definition for a 'for' loop
#define loop(i, start, end) for(int i = start; i < end; i++)

int main () {
  srand (time(NULL));
  float time;
  string vocabulary;
  vector<string> strings;
  costDatabase cost;
  int extraDashCost;
  fileReader("input.txt", time, vocabulary, strings, cost, extraDashCost);
  string s1 = "QN";
  string s3 = "_R";
  string s4 = "_Y";
  vector<string> t;
  t.push_back(s1);t.push_back(s3);
  t.push_back(s4);
  state temp(t, t);
  state n = randState(8, strings);
  // loop(j, 0, l.finalStrings.size())
  // {
  //     cout<<l.finalStrings.at(j)<<endl;
  // }
  // state n = runLocalSearch(strings, 1, cost, extraDashCost);
  loop(i, 0, n.finalStrings.size())
  {
    cout<<n.finalStrings.at(i)<<endl;
  }
  // cout<<costOfState(cost, temp, extraDashCost)<<endl;
}
