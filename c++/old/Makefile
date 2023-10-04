OBJECTS = $(patsubst %.cc, %, $(wildcard *.cc))

CXX = g++
CXXFLAGS = -std=c++14 -W -Wall

.SUFFIXES: .o .cc
%.o: %.cc
	$(CXX) $(CXXFLAGS) -c $<
%: %.cc
	$(CXX) $(CXXFLAGS) -o $@ $<

all: $(OBJECTS)

clean:
	rm -rf $(OBJECTS)
