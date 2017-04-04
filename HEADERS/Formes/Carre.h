// Camille Magnan & Clovis Durand
// Dessin vectoriel

#ifndef CARRE_H
#define CARRE_H

#include "Rectangle.h"

class Carre : public Rectangle
{
public :

//Constructeur
	Carre(Coord c1, 
		  unsigned int cote, 
		  std::string const couleur, 
		  unsigned int const transparence);
};

#endif //CARRE_H