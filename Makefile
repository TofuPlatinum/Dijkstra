#!/bin/bash
#file name: Makefile
CC = g++
CFLAGS = -Wall -std=c++11
DEPS = Tas.h main.cpp Graph.h Sommet.h
OBJ = tas.o main.o graph.o  sommet.o

#compile stage
%.o: %.cpp $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<

#link stage -- prog = name of executable. You can change this.
run.exe: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

#target for cleaning -- remove object and executable files
clean:
	rm *.o
rm run.exe