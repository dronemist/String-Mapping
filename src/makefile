# Compiler to use
CXX = g++

# Flags
CXXFLAGS = -Wall -g

# Executable name
OUT = main

all: $(OUT)

# Executable
$(OUT): main.o fileReader.o state.o cost.o expand.o
	$(CXX) fileReader.o state.o cost.o expand.o main.o -o main $(CXXFLAGS)

# Main
main.o: main.cpp fileReader.h cost.h expand.h state.h

# FileReder
fileReader.o: fileReader.h

# State
state.o: state.h

# cost
cost.o: cost.cpp cost.h state.h
	$(CXX) -c cost.cpp -o $@

# Expand
expand.o: expand.cpp expand.h cost.h state.h
	$(CXX) -c expand.cpp -o $@

# Clean
clean:
	rm *.o
	rm $(OUT)