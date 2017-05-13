// Clovis Durand & Camille Magnan
// ENSEIRB-Matmeca, E2
// 2017

// PG208 - Projet Dessin Vectoriel

// Rectangle_p.h
// Rectangle_p class header file. 

#ifndef CARRE_P_H
#define CARRE_P_H

#include "Carre.h"

class Carre_p : public Rectangle
{
public:
	// Con/Destructeurs
	Carre_p(Coord const c1, 
		unsigned int const cote,   
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

#endif // CARRE_P_H