# Camille Mangan & Clovis Durand

#Compiler
CXX      = g++ 

#Source directories
SRC      = ./SOURCES
SRCFORME = ./SOURCES/Formes

#Header directories
HDR      = ./HEADERS
HDRFORME = ./HEADERS/Formes

#OTHER
EXECT    = ./test_compiled
OFILE    = ./o_files


#all: 

downloaded:
	g++ -Wall -O3 -o downloaded main.cpp $(SRC)/Format/CBitmap.cpp $(SRC)/image/CImage.cpp $(SRC)/image/CPixel.cpp $(SRC)/image/CLigne.cpp

#Formes:
#	g++ -Wall -O3 -o temp_compiled/Formes.o -c ...

Rectangle.o: Ligne.o
	$(CXX) -Wall -O3 -c -o $(OFILE)/Rectangle.o $(SRCFORME)Rectangle.cpp $(OFILE)/Ligne.o $(OFILE)/Coord.o

Ligne.o: Coord.o
	$(CXX) -Wall -O3 -c -o $(OFILE)/Ligne.o $(SRCFORME)/Ligne.cpp $(OFILE)/Coord.o

Coord.o:
	$(CXX) -Wall -O3 -c -o $(OFILE)/Coord.o $(SRC)/Coord.cpp

Coord_test: 
	$(CXX) -Wall -O3 -o $(EXECT)/test_Coord $(SRC)/test_Coord.cpp $(SRC)/Coord.cpp

clean_exec:
	rm -rf downloaded

clean_o:
	rm -rf $(OFILE)/*.o