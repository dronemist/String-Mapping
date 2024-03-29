#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include "fileReader.h"

using namespace std;

// Definition for a 'for' loop
#define loop(i, start, end) for(int i = start; i < end; i++)

/// Main cost database
costDatabase costMap;
string vocabulary;
float totalTime;
int extraDashCost;
vector<string> strings;

/// This function converts cost 2-D vector to costDatabase;
/// - Parameters:
///   - costVector: 2-D vector
///   - vocabulary: vocabulary of letters
void toCostDatabase(vector<vector<int> > &costVector) {
  // Assuming costVector is already square
  int size = costVector.size();
  loop(i, 0, size) 
  {
    loop(j, 0, size) 
    {
      if(i != size - 1 && j != size - 1)
        costMap[vocabulary[i]][vocabulary[j]] = costVector.at(i).at(j);
      else if(i == size - 1 && j != size - 1)
        costMap['-'][vocabulary[j]] = costVector.at(i).at(j);
      else if(i != size - 1 && j == size - 1)
        costMap[vocabulary[i]]['-'] = costVector.at(i).at(j);  
      else
        costMap['-']['-'] = costVector.at(i).at(j);  
    }
  }
}


/// This function reads the input.txt file
/// - Parameter: 
///  - fileName: name of the file to be read
void fileReader(string fileName) {
    
    ifstream inFile(fileName);
    string line = "";
    int count = 0;
    int vocabularySize, numberOfStrings;
    vector<vector<int> > costVector;
    vector<int> costTemp;
    while (inFile>>line) 
    {
        switch (count) 
        {
            case 0:
            {
                // Time is the 0th line
                totalTime = stof(line);
                count++;
                break;
            }
            case 1:
            {
                // Size of vocabulary
                vocabularySize = stoi(line);
                count++;
                break;
            }
            case 2: 
            {    // Vocabulary
                stringstream ss(line);
                string temp;
                // Adding the first character
                vocabulary += line[0];
                // TODO: handle incorrect input
                if(vocabulary.size() == vocabularySize)
                    count++;
                break;  
            }
            case 3:  
            { 
                // Number of strings(k)
                numberOfStrings = stoi(line);
                count++;
                break;  
            }
            case 4:
            {   
                // Strings
                strings.push_back(line);
                // TODO: handle incorrect input
                if(strings.size() == numberOfStrings)
                    count++;
                break; 
            }
            case 5: 
            {    
                // inputting extra dash cost
                extraDashCost = stoi(line);
                count++;
                break;
            }
            case 6:
            {  
                costTemp.push_back(stoi(line));
                if(costTemp.size() == vocabularySize + 1) 
                {
                    costVector.push_back(costTemp); 
                    costTemp.clear();
                }
                if(costVector.size() == vocabularySize + 1)
                    count++;
                break;    
            }
            default:
                break;
        }
    }
    inFile.close();
    toCostDatabase(costVector);
}
