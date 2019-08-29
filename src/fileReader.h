#ifndef FILEREADER_INCLUDE
#define FILEREADER_INCLUDE
#include <string>
#include <vector>
#include <map>
/// Map for the cost vector
typedef std::map<char, std::map<char, int> > costDatabase; 

/// This function reads the input.txt file
/// - Parameter: 
///  - fileName: name of the file to be read
extern void fileReader(std::string);

/// Main cost database
extern costDatabase costMap;

/// Vocabulary
extern std::string vocabulary;

/// Total time in mins available
extern float totalTime;

/// cost of each extra dash
extern int extraDashCost;

/// Strings to match
extern std::vector<std::string> strings;

#endif