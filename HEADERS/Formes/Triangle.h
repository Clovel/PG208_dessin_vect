// Clovis Durand & Camille Magnan
// ENSEIRB-Matmeca, E2
// 2017

// PG208 - Projet Dessin Vectoriel

// Triangle.cpp
// Triangle class header file. 

#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Ligne.h"
#define DEBUG

class Triangle : public Ligne
{
public:
	// Constructeurs
	Triangle(Ligne const l, 
		Coord const c);

	// Afficheurs

	// Accesseurs
	Coord getCoord3(void) const;

	// Mutateurs
	void setCoord3(Coord const &c);

	// Draw
	void draw(CImage *img);

	// Méthodes publiques diverses

private:
	Coord m_c3;

	// Méthodes privées diverses

};

#endif // TRIANGLE_H