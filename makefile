# Clovis Durand & Camille Magnan
# ENSEIRB-Matmeca, E2
# 2017

# PG208 - Projet Dessin Vectoriel

# makefile
# makefile compliation file. 

TARGET 		= dessin_vect

CC 		    = g++

CFLAGS 		= -O3 -g -W -Wall -fopenmp

LINKER 		= g++ -o

LFLAGS 		= -Wall -I. -lm -fopenmp

SRCDIR 		= SOURCES/*
HDRDIR		= HEADERS/*
MAINDIR		= .
OBJDIR 		= o_files
BINDIR 		= bin

SOURCES 	:= $(wildcard $(SRCDIR)/*.cpp)
MAIN 		:= $(wildcard $(MAINDIR)/main.cpp)
INCLUDES 	:= $(wildcard $(SRCDIR)/*.h)
OBJECTS 	:= $(SOURCES:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)
OUTPUT		:= ./Sortie.bmp
TESTARG     := test
rm 		    = rm -f

all: $(BINDIR)/$(TARGET)

open: $(BINDIR)/$(TARGET)
	./bin/dessin_vect $(TESTARG); open $(OUTPUT);

comp: $(BINDIR)/$(TARGET)

$(BINDIR)/$(TARGET): $(OBJECTS) $(MAIN)
	@$(LINKER) $@ $(OBJECTS) $(MAIN) $(LFLAGS)


$(OBJECTS): $(OBJDIR)/%.o : $(SRCDIR)/%.cpp
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm ./bin/dessin_vect; rm ./*.o; rm $(OUTPUT)
