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
  totalTime = totalTime * 60;
  state n = runLocalSearch();
  loop(i, 0, n.finalStrings.size())
  {
    cout<<n.finalStrings.at(i)<<endl;
  }
  cout<<costOfState(n)<<endl;
}
