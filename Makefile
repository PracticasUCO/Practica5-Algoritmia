.PHONY: clean-all clean-objects

CXX =  g++
CXXFLAGS = $(LIBRARY) $(HEADER) $(STD) -ggdb3
LIBRARY = -L.
HEADER = -I.
STD = -std=c++11
OPTIMIZATION = -fbounds-check -fdefault-inline -ffast-math -ffloat-store -fforce-addr -ffunction-cse -finline -finline-functions\
-fmerge-all-constants

Material.o: Material.hpp Material.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ Material.cpp

test: test.cpp Material.o
	$(CXX) $(CXXFLAGS) -o $@ $^