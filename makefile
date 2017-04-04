# Camille Mangan & Clovis Durand

#Compiler
CXX      =g++
CFLAGS   =-O3 -march=native -mtune=native -std=c++11

#Source directories
SRC      =./SOURCES
SRCFORME =./SOURCES/Formes
SRCS     =./SOURCES/Coord.cpp ./SOURCES/Formes/Ligne.cpp ./SOURCES/Formes/Rectangle.cpp ./SOURCES/Formes/Carre.cpp

#Header directories
HDR      =./HEADERS
HDRFORME =./HEADERS/Formes

#OTHER
EXEC     =main
EXECT    =./test_compiled
OFILE    =./o_files


all: 
	$(CXX) $(CFLAGS) -c $(SRCS)

downloaded:
	g++ -Wall -O3 -o downloaded main.cpp $(SRC)/Format/CBitmap.cpp $(SRC)/image/CImage.cpp $(SRC)/image/CPixel.cpp $(SRC)/image/CLigne.cpp

#Formes:
#	g++ -Wall -O3 -o temp_compiled/Formes.o -c ...

Carre: Rectangle
	$(CXX) $(CFLAGS) -o $(OFILE)/Rectangle.o -c $(SRCFORME)/Rectangle.cpp $(OFILE)/Ligne.o $(OFILE)/Coord.o

Rectangle: Ligne.o
	$(CXX) $(CFLAGS) -o $(OFILE)/Rectangle.o -c $(SRCFORME)/Rectangle.cpp $(OFILE)/Ligne.o $(OFILE)/Coord.o

Ligne: Coord.o
	$(CXX) $(CFLAGS) -o $(OFILE)/Ligne.o -c $(SRCFORME)/Ligne.cpp $(OFILE)/Coord.o

Coord:
	$(CXX) $(CFLAGS) -o $(OFILE)/Coord.o -c $(SRC)/Coord.cpp

Coord_test: 
	$(CXX) $(CFLAGS) -o $(EXECT)/test_Coord $(SRC)/test_Coord.cpp $(SRC)/Coord.cpp

clean_exec:
	rm -rf downloaded

#clean_o:
#	rm -rf $(OFILE)/*.o


# SRC=./src/main.cpp

# OBJ= $(SRC:.cpp=.o)

# all: $(EXEC)

# main: $(OBJ)
# 	$(CXX) $(CFLAGS) -o ./bin/$@ $^ $(LDFLAGS)

# %.o: %.cpp
# 	$(CXX) $(CFLAGS) -o $@ -c $< $(CFLAGS)

# .PHONY: clean mrproper

# clean:
# 	find ./bin -name main -exec rm {} \;
# 	find ./src -name *.o  -exec rm {} \;

# mrproper: clean
# 	rm $(EXEC)