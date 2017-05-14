// Clovis Durand & Camille Magnan
// ENSEIRB-Matmeca, E2
// 2017

// PG208 - Projet Dessin Vectoriel

// Carre.h
// Carre class header file. 

#ifndef CARRE_H
#define CARRE_H

#include "Rectangle.h"

class Carre : public Rectangle
{
public:
	// Constructeur
	Carre(Coord const c1, 
		unsigned int const c, 
		std::string const couleur, 
		unsigned int const transparence);
};

#endif // CARRE_H