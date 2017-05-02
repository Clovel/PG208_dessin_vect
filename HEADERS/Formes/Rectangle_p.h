// Clovis Durand & Camille Magnan
// ENSEIRB-Matmeca, E2
// 2017

// PG208 - Projet Dessin Vectoriel

// Rectangle_p.h
// Rectangle_p class header file. 

#ifndef RECTANGLE_P_H
#define RECTANGLE_P_H

#include "Rectangle.h"

class Rectangle_p : public Rectangle
{
public:
	// Con/Destructeurs
	Rectangle_p(Coord const c1, 
		unsigned int const longueur, 
		unsigned int const hauteur,  
		std::string const couleur, 
		unsigned int const transparence);


	// Afficheurs

	// Accesseurs

	// Mutateurs

	// Draw
	void draw(CImage *Image) const;

	// Méthodes publiques Diverses

//private:
	// Attributs/Variables membres

	// Méthodes privées diverses 
};

#endif // RECTANGLE_P_H