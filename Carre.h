#ifndef CARRE_H
#define CARRE_H

#include "Rectangle.h"

class Carre : public Rectangle
{
	// Constructeur
	Carre(Coord const c1, 
		unsigned int const c, 
		std::string const couleur, 
		unsigned int const transparence);
};

#endif // CARRE_H