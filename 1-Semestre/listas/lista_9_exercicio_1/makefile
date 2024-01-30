CXX = g++
CXXFLAGS = -std=c++11 -Wall
SRC = main.cpp functions.cpp
HDR = includes.hpp functions.hpp
OBJS = $(SRC:.cpp=.o)
EXE = l9e1

all: $(EXE)

$(EXE): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(EXE)