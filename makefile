# Clovis Durand & Camille Magnan
# ENSEIRB-Matmeca, E2
# 2017

# PG208 - Projet Dessin Vectoriel

# makefile
# makefile compliation file. 

TARGET 		= dessin_vect

CC 		    = g++

CFLAGS 		= -W -Wall -fopenmp

LINKER 		= g++ -o

LFLAGS 		= -Wall -I. -lm -lSDL2 -fopenmp

SRCDIR 		= SOURCES/*
HDRDIR		= HEADERS/*
MAINDIR		= ./
OBJDIR 		= o_files
BINDIR 		= bin

SOURCES 	:= $(wildcard $(SRCDIR)/*.cpp)
MAIN 		:= $(wildcard $(MAINDIR)/main.cpp)
INCLUDES 	:= $(wildcard $(SRCDIR)/*.h)
OBJECTS 	:= $(SOURCES:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)
OUTPUT		:= ./Sortie.bmp
rm 		    = rm -f

all: $(BINDIR)/$(TARGET)
	./bin/dessin_vect; open $(OUTPUT)

$(BINDIR)/$(TARGET): $(OBJECTS)
	@$(LINKER) $@ $(OBJECTS) $(MAIN) $(LFLAGS)


$(OBJECTS): $(OBJDIR)/%.o : $(SRCDIR)/%.cpp
	@$(CC) $(CFLAGS) -c $< -o $@

clean_exec:
	rm -f ./bin/dessin_vect
