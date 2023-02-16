SHELL = /bin/bash
SRCS = ex_02.cpp cpmv.cpp
TARGETS = ex_02 ex_02_verb
CXXFLAGS = -Wall -std=c++11
CXX = g++

ex_02 : $(SRCS)
	$(CXX) $(CXXFLAGS) -o $@ $^

ex_02_verb : $(SRCS)
	$(CXX) $(CXXFLAGS) -DVERBOSE_ -o $@ $^

.PHONY: clean
clean:
	rm -rf $(TARGETS)
