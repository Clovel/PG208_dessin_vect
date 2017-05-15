// Clovis Durand & Camille Magnan
// ENSEIRB-Matmeca, E2
// 2017

// PG208 - Projet Dessin Vectoriel

// Cercle_p.h
// Cercle_p class header file. 

#ifndef CERCLE_P_H
#define CERCLE_P_H

#include "Cercle.h"

class Cercle_p : public Cercle
{
public:
	// Con/Destructeurs
	Cercle_p();
	Cercle_p(Coord const c, 
		unsigned int const rayon, 
    	std::string const couleur, 
    	unsigned int const transparence);

	// Afficheurs

	// Accesseurs

	// Mutateurs

	// Draw
	void draw(CImage *img);

	// Méthodes publiques Diverses

private:
	// Attributs/Variables membres

	// Méthodes privées diverses
	void drawCircles(CImage *img, 
		unsigned int rayon, int const x, int const y);
};

#endif // CERCLE_P_H