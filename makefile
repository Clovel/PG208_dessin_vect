
CXX = g++ 
SRC = ./SOURCES


all: Formes

downloaded:
	g++ -Wall -O3 -o downloaded main.cpp ./SOURCES/Format/CBitmap.cpp ./SOURCES/image/CImage.cpp ./SOURCES/image/CPixel.cpp ./SOURCES/image/CLigne.cpp

Formes:
	g++ -Wall -O3 -o temp_compiled/Formes.o -c ...

Coord: 
	$(CXX) -Wall -O3 -o test_Coord $(SRC)/test_Coord.cpp $(SRC)/Coord.cpp

clean_exec:
	rm -rf downloaded

clean_o:
	rm -rf ./temp_compiled/*.o