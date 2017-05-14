// Clovis Durand & Camille Magnan
// ENSEIRB-Matmeca, E2
// 2017

// PG208 - Projet Dessin Vectoriel

// Carre_p.h
// Carre class header file. 

#ifndef CARRE_P_H
#define CARRE_P_H

#include "Rectangle_p.h"

class Carre_p : public Rectangle_p
{
public:
	// Constructeur
	Carre_p(Coord const c1, 
		unsigned int const c, 
		std::string const couleur, 
		unsigned int const transparence);
};

#endif // CARRE_P_H