#ifndef FILEREADER_INCLUDE
#define FILEREADER_INCLUDE
#include <string>
#include <vector>
/// Map for the cost vector
typedef std::map<char, std::map<char, int> > costDatabase; 

/// This function reads the input.txt file
/// - Parameter: 
///  - fileName: name of the file to be read
extern void fileReader(std::string, float &, std::string &
, std::vector<std::string> &, costDatabase &, int &);

#endif