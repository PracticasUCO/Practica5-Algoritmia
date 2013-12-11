.PHONY: clean-all clean-objects clean-test

CXX =  g++
CXXFLAGS = $(LIBRARY) $(HEADER) $(STD) -O3 $(OPTIMIZATION)
LIBRARY = -L.
HEADER = -I.
STD = -std=c++11
OPTIMIZATION = -fbounds-check -fdefault-inline -ffast-math -ffloat-store -fforce-addr -ffunction-cse -finline -finline-functions\
-fmerge-all-constants

practica5: Material.o ListaMateriales.o Mochila.o main.o funcionesAltoNivel.o
	$(CXX) $(CXXFLAGS) -o $@ $^

Material.o: Material.hpp Material.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ Material.cpp

ListaMateriales.o: ListaMateriales.hpp ListaMateriales.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ ListaMateriales.cpp
	
Mochila.o: Mochila.cpp Mochila.hpp
	$(CXX) $(CXXFLAGS) -c -o $@ Mochila.cpp
	
funcionesAltoNivel.o: funcionesAltoNivel.hpp funcionesAltoNivel.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ funcionesAltoNivel.cpp
	
main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ main.cpp
	
test: test.cpp Material.o ListaMateriales.o Mochila.o
	$(CXX) $(CXXFLAGS) -o $@ $^

clean-objects:
	-rm *.o

clean-all: clean-objects
	-rm practica5

clean-test: clean-objects
	-rm test
