# Camille Mangan & Clovis Durand

TARGET 		= dessin_vect

CC 		    = g++

CFLAGS 		= -W -Wall -fopenmp

LINKER 		= g++ -o

LFLAGS 		= -Wall -I. -lm -lSDL2 -fopenmp

SRCDIR 		= SOURCES/*/
HDRDIR		= HEADERS/*/
MAINDIR		= ./
OBJDIR 		= o_files
BINDIR 		= bin

SOURCES 	:= $(wildcard $(SRCDIR)/*.cpp)
MAIN 		:= $(wildcard $(MAINDIR)/main.cpp)
INCLUDES 	:= $(wildcard $(SRCDIR)/*.h)
OBJECTS 	:= $(SOURCES:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
rm 		    = rm -f

all: $(BINDIR)/$(TARGET)

$(BINDIR)/$(TARGET): $(OBJECTS) 
	@$(LINKER) $@ $(OBJECTS) $(LFLAGS)


$(OBJECTS): $(OBJDIR)/%.o : $(SRCDIR)/%.c $(MAINDIR)
	@$(CC) $(CFLAGS) -c $< -o $@

clean_exec:
	rm -f ./bin/dessin_vect
