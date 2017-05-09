// Clovis Durand & Camille Magnan
// ENSEIRB-Matmeca, E2
// 2017

// PG208 - Projet Dessin Vectoriel

// Point.h
// Point class header file. 

#ifndef POINT_H
#define POINT_H

#include "Forme.h"

class Point : public Forme
{
public :
	// Con/Destructeurs
	Point();
	Point(Coord const c, 
		std::string const couleur, 
		unsigned int const transparence);
	// Afficheurs

	// Accesseurs

	// Mutateurs

	// Draw
	void draw(CImage *img);

	// Méthodes publiques Diverses

//private:
	// Attributs/Variables membres

	// Méthodes privées diverses 
};

#endif //POINT_H