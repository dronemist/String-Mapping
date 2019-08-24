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

/// This function converts cost 2-D vector to costDatabase;
/// - Parameters:
///   - costVector: 2-D vector
///   - vocabulary: voacbulary of letters
costDatabase toCostDatabase(vector<vector<int> > &costVector, string vocabulary) {
  costDatabase costMap;
  // Assuming costVector is already square
  int size = costVector.size();
  loop(i, 0, size) 
  {
    loop(j, 0, size) 
    {
      if(i != size - 1 && j != size - 1)
        costMap[vocabulary[i]][vocabulary[j]] = costVector.at(i).at(j);
      else if(i == size - 1 && j != size - 1)
        costMap['_'][vocabulary[j]] = costVector.at(i).at(j);
      else if(i != size - 1 && j == size - 1)
        costMap[vocabulary[i]]['_'] = costVector.at(i).at(j);  
      else
        costMap['_']['_'] = costVector.at(i).at(j);  
    }
  }
  return costMap;
}


/// This function reads the input.txt file
/// - Parameter: 
///  - fileName: name of the file to be read
void fileReader(string fileName, float &time, string &vocabulary
, vector<string> & strings, costDatabase &cost, int &extraDashCost) {
    
    ifstream inFile(fileName);
    string line;
    int count = 0;
    int vocabularySize, numberOfStrings;
    vector<vector<int> > costVector;
    while (getline(inFile, line)) 
    {
        switch (count) 
        {
            case 0:
            {
                // Time is the 0th line
                time = stof(line);
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
                getline(ss, temp, ',');
                vocabulary += temp;
                while (getline(ss, temp, ','))
                {
                    temp = temp.substr(1, temp.length() - 1);
                    vocabulary += temp;
                }
                // TODO: handle incorrect input
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
                // Inputting costs
                stringstream ss(line);
                string temp;
                vector<int> costTemp;
                while (getline(ss, temp, ' '))
                {
                    costTemp.push_back(stoi(temp));
                }
                costVector.push_back(costTemp);
                if(costVector.size() == vocabularySize + 1) 
                    count++;    
                break;
            }
            default:
                break;
        }
    }
    cost = toCostDatabase(costVector, vocabulary);
}