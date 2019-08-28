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
  // srand (time(NULL));
  float time;
  string vocabulary;
  vector<string> strings;
  costDatabase cost;
  int extraDashCost;
  fileReader("input.txt", time, vocabulary, strings, cost, extraDashCost);
  string s1 = "--------U-Q------";
  string s3 = "-UUS----M-MQSI---";
  string s2 = "---S------I-UI---";
  string s4 = "II--OOU-IQM--I---";
  string s5 = "-U------I-M-UMOU-";
  string s6 = "O-------M-MO-M--Q";
  string s7 = "U----O--U-MQ-U-SQ";
  string s8 = "---OQ--QI-I--M---";
  vector<string> t;
  t.push_back(s1);t.push_back(s2);t.push_back(s3);
  t.push_back(s4);t.push_back(s5);t.push_back(s6);
  t.push_back(s7);t.push_back(s8);
  state temp(t, t);
  // state p = randState(17, strings);
  // loop(j, 0, l.finalStrings.size())
  // {
  //     cout<<l.finalStrings.at(j)<<endl;
  // }
  state n = runLocalSearch(strings, 180, cost, extraDashCost);
  // state n = getNextState(temp, cost, extraDashCost);
  loop(i, 0, n.finalStrings.size())
  {
    cout<<n.finalStrings.at(i)<<endl;
  }
  cout<<costOfState(cost, n, extraDashCost)<<endl;
}
