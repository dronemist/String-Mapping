#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "fileReader.h"

using namespace std;

// Definition for a 'for' loop
#define loop(i, start, end) for(int i = start; i < end; i++)

/// This function reads the input.txt file
/// - Parameter: 
///  - fileName: name of the file to be read
void fileReader(string fileName) {
    
    ifstream inFile(fileName);
    string line;
    float time;
    int count = 0;
    vector<string> vocabulary;
    vector<string> strings;
    int vocabularySize, numberOfStrings, extraDashCost;
    vector<vector<int> > cost;
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
                vocabulary.push_back(temp);
                while (getline(ss, temp, ','))
                {
                    temp = temp.substr(1, temp.length() - 1);
                    vocabulary.push_back(temp);
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
                cost.push_back(costTemp);
                if(cost.size() == vocabularySize + 1) 
                    count++;    
                break;
            }
            default:
                break;
        }
    }
}
