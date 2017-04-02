all: Formes

downloaded:
	g++ -Wall -o downloaded main.cpp ./SOURCES/Format/CBitmap.cpp ./SOURCES/image/CImage.cpp ./SOURCES/image/CPixel.cpp ./SOURCES/image/CLigne.cpp

Formes:
	g++ -Wall -o temp_compiled/Formes.o -c ...

clean_exec:
	rm -rf downloaded

clean_o:
	rm -rf ./temp_compiled/*.o