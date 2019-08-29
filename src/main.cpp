#include <iostream>
#include <algorithm>
#include <map>
#include <sstream>
#include "cost.h"
#include "fileReader.h"
#include "expand.h"
#include "state.h"
#include "localSearch.h"
using namespace std;

string outputFileName;
/// Definition for a 'for' loop
#define loop(i, start, end) for(int i = start; i < end; i++)

int main (int argc, char **argv) {
  fileReader(string(argv[argc - 2]));
  outputFileName = argv[argc - 1];
  totalTime = 1;
  // cout<<totalTime<<endl;
  // cout<<vocabulary.size()<<endl;
  // cout<<vocabulary<<endl;
  // cout<<strings.size()<<endl;
  // loop(i, 0, strings.size())
  // {
  //   cout<<strings.at(i)<<endl;
  // }
  // cout<<extraDashCost<<endl;
  // int size = vocabulary.size()+1;
  // loop(i, 0, vocabulary.size() + 1)
  // {
  //   loop(j, 0, vocabulary.size() + 1)
  //   {
  //     if(i != size - 1 && j != size - 1)
  //       cout<< costMap[vocabulary[i]][vocabulary[j]]; 
  //     else if(i == size - 1 && j != size - 1)
  //       cout<<costMap['-'][vocabulary[j]]; 
  //     else if(i != size - 1 && j == size - 1)
  //       cout<<costMap[vocabulary[i]]['-'];   
  //     else
  //       cout<<costMap['-']['-']; 
  //     cout<<" "; 
  //   }
  //   cout<<endl;
  // }
  // string s1 = "--------U-Q------";
  // string s3 = "-UUS----M-MQSI---";
  // string s2 = "---S------I-UI---";
  // string s4 = "II--OOU-IQM--I---";
  // string s5 = "-U------I-M-UMOU-";
  // string s6 = "O-------M-MO-M--Q";
  // string s7 = "U----O--U-MQ-U-SQ";
  // string s8 = "---OQ--QI-I--M---";
  string s1 = "ACTGTGA";
  string s2 = "TACTGC-";
  string s3 = "ACTGA--";
  vector<string> t;
  t.push_back(s1);t.push_back(s2);t.push_back(s3);
  // t.push_back(s4);t.push_back(s5);t.push_back(s6);
  // t.push_back(s7);t.push_back(s8);
  state temp(t);
  // temp.cost = costOfState(cost, temp, extraDashCost);
  // state p = randState(17, strings);
  // loop(j, 0, l.finalStrings.size())
  // {
  //     cout<<l.finalStrings.at(j)<<endl;
  // }
  state n = runLocalSearch();
  // state n = getNextState(temp, cost, extraDashCost);
  loop(i, 0, n.finalStrings.size())
  {
    cout<<n.finalStrings.at(i)<<endl;
  }
  cout<<costOfState(n)<<endl;
}
