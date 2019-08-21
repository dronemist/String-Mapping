# Compiler to use
CXX = g++

# Flags
CXXFLAGS = -Wall -g

# Executable
main: fileReader.o cost.o
	$(CXX) $(CXXFLAGS) -o main fileReader.o cost.o

# fileReder
fileReader.o: fileReader.h

# cost
cost.o: cost.h

# Clean
clean:
	rm *.o main